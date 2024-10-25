#include "calculation_cluster.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

CalculationCluster::CalculationCluster(const std::unordered_map<std::string, TriangularRelationship>& relationships,
                                       DepthCache& depth_cache,
                                       const Configuration& config)
    : relationships(relationships), depth_cache(depth_cache), config(config), account(config.api_key, config.api_secret) {
    if (config.telegram_enabled) {
        // Start Telegram bot if enabled
    }
}

void CalculationCluster::start() {
    int execution_count = 0;
    auto relationships_names = std::vector<std::string>(relationships.size());
    std::transform(relationships.begin(), relationships.end(), relationships_names.begin(),
                   [](const auto& pair) { return pair.first; });

    while (execution_count < config.trading_execution_cap || config.trading_execution_cap == -1) {
        for (const auto& rel : relationships_names) {
            auto deal = calculate_relationship(relationships.at(rel));
            if (deal.profit >= (config.trading_profit_threshold / 100.0) &&
                (get_epoch_ms() - deal.timestamp) <= config.trading_age_threshold) {
                std::cout << "[" << std::fixed << std::setprecision(3) << deal.profit * 100.0 << "%] Deal: ";
                for (const auto& action : deal.actions) {
                    std::cout << action.action << " " << action.quantity << " " << action.pair.get_symbol() << " ";
                }
                std::cout << std::endl;

                if (config.trading_enabled) {
                    execute_deal(deal);
                    execution_count++;
                } else {
                    std::cout << "[INFO] Trading is not enabled, skipping..." << std::endl;
                }
            }
        }
    }
}

uint64_t CalculationCluster::get_epoch_ms() const {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
               std::chrono::system_clock::now().time_since_epoch())
        .count();
}

double CalculationCluster::correct_quantity(double quantity, double step) const {
    return floor(quantity / step) * step;
}

double CalculationCluster::custom_round(double quantity, double step) const {
    int power = 0;
    while (step < 1.0) {
        step *= 10.0;
        power++;
    }
    return std::stod(std::to_string(quantity).substr(0, std::to_string(quantity).find(".") + power + 1));
}

Deal CalculationCluster::calculate_relationship(const TriangularRelationship& relationship) const {
    auto pairs = relationship.get_trading_pairs();
    auto pair_names = relationship.get_pairs();
    auto pair_actions = relationship.get_actions();
    double fee_multiplier = pow((100.0 - config.trading_taker_fee) / 100.0, 3);
    uint64_t lowest_timestamp = std::numeric_limits<uint64_t>::max();
    double best_profit = -1.0;
    Deal results;

    for (int investment = config.investment_min / config.investment_step;
         investment <= config.investment_max / config.investment_step; investment++) {
        double true_investment = investment * config.investment_step;
        double current_quantity = true_investment;
        Deal tmp_deal;

        for (size_t j = 0; j < pair_names.size(); j++) {
            auto depth_book = depth_cache.get_depth(pair_names[j]);
            uint64_t timestamp = depth_book.event_time;
            if (timestamp < lowest_timestamp) {
                lowest_timestamp = timestamp;
            }
            double helper_quantity = current_quantity;
            current_quantity = 0.0;

            if (pair_actions[j] == "BUY") {
                for (const auto& ask : depth_book.asks) {
                    double tmp_quantity = correct_quantity(helper_quantity / ask.price, pairs[j].get_step());
                    if (ask.qty >= tmp_quantity) {
                        current_quantity += tmp_quantity;
                    } else {
                        tmp_quantity = correct_quantity(ask.qty, pairs[j].get_step());
                        current_quantity += tmp_quantity;
                    }
                    helper_quantity -= ask.qty * ask.price;
                    if (helper_quantity <= 0.0) break;
                }
                tmp_deal.actions.emplace_back(pairs[j], pair_actions[j], current_quantity);
            } else {
                tmp_deal.actions.emplace_back(pairs[j], pair_actions[j], correct_quantity(helper_quantity, pairs[j].get_step()));
                for (const auto& bid : depth_book.bids) {
                    if (bid.qty >= helper_quantity) {
                        current_quantity += correct_quantity(helper_quantity, pairs[j].get_step()) * bid.price;
                    } else {
                        current_quantity += correct_quantity(bid.qty, pairs[j].get_step()) * bid.price;
                    }
                    helper_quantity -= bid.qty;
                    if (helper_quantity <= 0.0) break;
                }
            }
        }

        double profit = ((current_quantity * fee_multiplier) - true_investment) / true_investment;
        if (profit >= best_profit) {
            results = tmp_deal;
            best_profit = profit;
        }
    }

    results.profit = best_profit;
    results.timestamp = lowest_timestamp;
    return results;
}

void CalculationCluster::execute_deal(const Deal& deal) {
    for (size_t i = 0; i < deal.actions.size(); i++) {
        const auto& action = deal.actions[i];
        std::string buy_sell = action.action;
        std::string pair = action.pair.get_symbol();
        double qty = custom_round(action.quantity, action.pair.get_step());

        Transaction transaction;

        if (buy_sell == "BUY") {
            std::cout << "[" << (i + 1) << "/" << deal.actions.size() << "] Buying " << qty << " from symbol " << pair << std::endl;
            transaction = account.market_buy(pair, qty);
            if (!transaction.ok) {
                std::cerr << "Failed to execute action #" << (i + 1) << " (symbol=" << pair << ", qty=" << qty << "): " << transaction.error_message << std::endl;
                return;
            }
        } else if (buy_sell == "SELL") {
            std::cout << "[" << (i + 1) << "/" << deal.actions.size() << "] Selling " << qty << " from symbol " << pair << std::endl;
            transaction = account.market_sell(pair, qty);
            if (!transaction.ok) {
                std::cerr << "Failed to execute action #" << (i + 1) << " (symbol=" << pair << ", qty=" << qty << "): " << transaction.error_message << std::endl;
                return;
            }
        } else {
            std::cerr << "Unknown operation for action #" << (i + 1) << ": " << buy_sell << std::endl;
            return;
        }

        std::string status;
        while (status != "FILLED") {
            auto order_status = account.order_status(pair, transaction.order_id);
            if (order_status.ok) {
                std::cout << "[" << (i + 1) << "/" << deal.actions.size() << "] " << order_status.status << std::endl;
                status = order_status.status;
            } else {
                std::cerr << "[" << (i + 1) << "/" << deal.actions.size() << "] Couldn't find order yet, will retry. Error: " << order_status.error_message << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
    }
    std::cout << "[INFO] Successfully executed deal!" << std::endl;
}
