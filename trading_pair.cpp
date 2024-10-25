#include "trading_pair.h"

TradingPair::TradingPair(const std::string& symbol, const std::string& base_asset, const std::string& quote_asset, double step)
    : symbol(symbol), base_asset(base_asset), quote_asset(quote_asset), step(step), initialized(false), timestamp(std::chrono::system_clock::now()) {}

std::string TradingPair::get_symbol() const {
    return symbol;
}

double TradingPair::get_step() const {
    return step;
}

std::string TradingPair::get_base_asset() const {
    return base_asset;
}

std::string TradingPair::get_quote_asset() const {
    return quote_asset;
}

bool TradingPair::has_asset(const std::string& asset) const {
    return asset == quote_asset || asset == base_asset;
}

std::string TradingPair::get_the_other(const std::string& asset) const {
    return asset == quote_asset ? base_asset : (asset == base_asset ? quote_asset : "");
}

std::string TradingPair::text() const {
    return base_asset + "/" + quote_asset;
}

bool TradingPair::operator==(const TradingPair& other) const {
    return (other.quote_asset == quote_asset && other.base_asset == base_asset) ||
           (other.quote_asset == base_asset && other.base_asset == quote_asset);
}
