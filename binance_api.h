#ifndef BINANCE_API_H
#define BINANCE_API_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

struct Bids {
    double price;
    double qty;
};

struct Asks {
    double price;
    double qty;
};

struct DepthOrderBookEvent {
    std::string symbol;
    uint64_t first_update_id;
    uint64_t final_update_id;
    uint64_t event_time;
    std::vector<Bids> bids;
    std::vector<Asks> asks;
};

struct OrderBook {
    uint64_t last_update_id;
    std::vector<Bids> bids;
    std::vector<Asks> asks;
};

struct Transaction {
    bool ok;
    std::string error_message;
    std::string status;
    std::string order_id;
};

struct Filter {
    std::string type;
    std::string step_size;
};

class BinanceAccount {
public:
    BinanceAccount(const std::string& api_key, const std::string& api_secret);
    Transaction market_buy(const std::string& symbol, double quantity);
    Transaction market_sell(const std::string& symbol, double quantity);
    Transaction order_status(const std::string& symbol, const std::string& order_id);

private:
    std::string api_key;
    std::string api_secret;
};

class BinanceGeneral {
public:
    struct ExchangeInfo {
        struct Symbol {
            std::string symbol;
            std::string base_asset;
            std::string quote_asset;
            std::string status;
            std::vector<Filter> filters;
        };
        std::vector<Symbol> symbols;
    };

    ExchangeInfo exchange_info();
};

class BinanceWebSocket {
public:
    void connect(const std::vector<std::string>& symbols, std::function<void(const DepthOrderBookEvent&)> callback);
};

#endif // BINANCE_API_H
