#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

struct Configuration {
    std::string api_key;
    std::string api_secret;
    std::string investment_base;
    double investment_min;
    double investment_max;
    double investment_step;
    bool trading_enabled;
    int trading_execution_cap;
    double trading_taker_fee;
    double trading_profit_threshold;
    uint64_t trading_age_threshold;
    int depth_size;
    bool telegram_enabled;
    std::string telegram_token;
    int64_t telegram_user_id;

    Configuration(const std::string& config_path);
};

#endif // CONFIG_H
