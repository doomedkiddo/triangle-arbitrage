#include "trader.h"
#include <iostream>
#include <algorithm>

bTrader::bTrader(const std::string& config_path) {
    Configuration config(config_path);
    BinanceGeneral general;
    std::vector<TradingPair> pairs;

    auto exchange_info = general.exchange_info();
    for (const auto& symbol : exchange_info.symbols) {
        if (symbol.status == "TRADING") {
            double step = 0.0;
            for (const auto& filter : symbol.filters) {
                if (filter.type == "LOT_SIZE") {
                    step = std::stod(filter.step_size);
                }
            }
            pairs.emplace_back(symbol.symbol, symbol.base_asset, symbol.quote_asset, step);
        }
    }

    std::vector<TradingPair> starters;
    for (const auto& pair : pairs) {
        if (pair.has_asset(config.investment_base)) {
            starters.push_back(pair);
        }
    }

    std::unordered_map<std::string, TriangularRelationship> relationships;
    std::vector<std::string> socket_pairs;
    for (size_t i = 0; i < starters.size() - 1; i++) {
        for (size_t j = i + 1; j < starters.size(); j++) {
            auto start_pair = starters[i];
            auto end_pair = starters[j];
            auto middle = TradingPair("", start_pair.get_the_other(config.investment_base), end_pair.get_the_other(config.investment_base), 0.0);
            for (const auto& middle_pair : pairs) {
                if (middle_pair == middle) {
                    if (std::find(socket_pairs.begin(), socket_pairs.end(), start_pair.get_symbol()) == socket_pairs.end()) {
                        socket_pairs.push_back(start_pair.get_symbol());
                    }
                    if (std::find(socket_pairs.begin(), socket_pairs.end(), middle_pair.get_symbol()) == socket_pairs.end()) {
                        socket_pairs.push_back(middle_pair.get_symbol());
                    }
                    if (std::find(socket_pairs.begin(), socket_pairs.end(), end_pair.get_symbol()) == socket_pairs.end()) {
                        socket_pairs.push_back(end_pair.get_symbol());
                    }
                    relationships[start_pair.get_symbol() + " -> " + middle_pair.get_symbol() + " -> " + end_pair.get_symbol()] =
                        TriangularRelationship(config.investment_base, start_pair, middle_pair, end_pair);
                    break;
                }
            }
        }
    }

    DepthCache depth_cache(socket_pairs, 8, 1);
    calculation_cluster = CalculationCluster(relationships, depth_cache, config);
}

void bTrader::run() {
    calculation_cluster.start();
}
