#include "binance_api.h"
#include <curl/curl.h>
#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

BinanceAccount::BinanceAccount(const std::string& api_key, const std::string& api_secret)
    : api_key(api_key), api_secret(api_secret) {}

Transaction BinanceAccount::market_buy(const std::string& symbol, double quantity) {
    CURL* curl = curl_easy_init();
    std::string readBuffer;
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.binance.com/api/v3/order");
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, ("symbol=" + symbol + "&side=BUY&type=MARKET&quantity=" + std::to_string(quantity)).c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, curl_slist_append(nullptr, ("X-MBX-APIKEY: " + api_key).c_str()));
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    nlohmann::json response = nlohmann::json::parse(readBuffer);
    Transaction transaction;
    transaction.ok = response["code"].is_null();
    transaction.error_message = response["msg"].is_null() ? "" : response["msg"].get<std::string>();
    transaction.status = response["status"].get<std::string>();
    transaction.order_id = response["orderId"].get<std::string>();
    return transaction;
}

Transaction BinanceAccount::market_sell(const std::string& symbol, double quantity) {
    CURL* curl = curl_easy_init();
    std::string readBuffer;
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.binance.com/api/v3/order");
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, ("symbol=" + symbol + "&side=SELL&type=MARKET&quantity=" + std::to_string(quantity)).c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, curl_slist_append(nullptr, ("X-MBX-APIKEY: " + api_key).c_str()));
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    nlohmann::json response = nlohmann::json::parse(readBuffer);
    Transaction transaction;
    transaction.ok = response["code"].is_null();
    transaction.error_message = response["msg"].is_null() ? "" : response["msg"].get<std::string>();
    transaction.status = response["status"].get<std::string>();
    transaction.order_id = response["orderId"].get<std::string>();
    return transaction;
}

Transaction BinanceAccount::order_status(const std::string& symbol, const std::string& order_id) {
    CURL* curl = curl_easy_init();
    std::string readBuffer;
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, ("https://api.binance.com/api/v3/order?symbol=" + symbol + "&orderId=" + order_id).c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, curl_slist_append(nullptr, ("X-MBX-APIKEY: " + api_key).c_str()));
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    nlohmann::json response = nlohmann::json::parse(readBuffer);
    Transaction transaction;
    transaction.ok = response["code"].is_null();
    transaction.error_message = response["msg"].is_null() ? "" : response["msg"].get<std::string>();
    transaction.status = response["status"].get<std::string>();
    transaction.order_id = response["orderId"].get<std::string>();
    return transaction;
}

BinanceGeneral::ExchangeInfo BinanceGeneral::exchange_info() {
    CURL* curl = curl_easy_init();
    std::string readBuffer;
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.binance.com/api/v3/exchangeInfo");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    nlohmann::json response = nlohmann::json::parse(readBuffer);
    ExchangeInfo exchange_info;
    for (const auto& symbol : response["symbols"]) {
        ExchangeInfo::Symbol sym;
        sym.symbol = symbol["symbol"].get<std::string>();
        sym.base_asset = symbol["baseAsset"].get<std::string>();
        sym.quote_asset = symbol["quoteAsset"].get<std::string>();
        sym.status = symbol["status"].get<std::string>();
        for (const auto& filter : symbol["filters"]) {
            ExchangeInfo::Filter fil;
            fil.type = filter["filterType"].get<std::string>();
            if (fil.type == "LOT_SIZE") {
                fil.step_size = filter["stepSize"].get<std::string>();
            }
            sym.filters.push_back(fil);
        }
        exchange_info.symbols.push_back(sym);
    }
    return exchange_info;
}

void BinanceWebSocket::connect(const std::vector<std::string>& symbols, std::function<void(const DepthOrderBookEvent&)> callback) {
    // Simulated WebSocket connection
    std::this_thread::sleep_for(std::chrono::seconds(1));
    DepthOrderBookEvent event;
    event.symbol = symbols[0];
    event.first_update_id = 1;
    event.final_update_id = 1;
    event.event_time = std::chrono::duration_cast<std::chrono::milliseconds>(
                           std::chrono::system_clock::now().time_since_epoch())
                           .count();
    event.bids = {{1.0, 1.0}};
    event.asks = {{1.0, 1.0}};
    callback(event);
}
