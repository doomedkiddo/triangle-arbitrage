#ifndef TRADING_PAIR_H
#define TRADING_PAIR_H

#include <string>
#include <vector>
#include <chrono>
#include "binance_api.h"

class TradingPair {
public:
    TradingPair(const std::string& symbol, const std::string& base_asset, const std::string& quote_asset, double step);

    std::string get_symbol() const;
    double get_step() const;
    std::string get_base_asset() const;
    std::string get_quote_asset() const;
    bool has_asset(const std::string& asset) const;
    std::string get_the_other(const std::string& asset) const;
    std::string text() const;

    bool operator==(const TradingPair& other) const;

private:
    std::string symbol;
    std::string base_asset;
    std::string quote_asset;
    double step;
    bool initialized;
    std::vector<Asks> asks;
    std::vector<Bids> bids;
    std::chrono::system_clock::time_point timestamp;
};

#endif // TRADING_PAIR_H
