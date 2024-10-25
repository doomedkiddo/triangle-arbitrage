#include "config.h"

Configuration::Configuration(const std::string& config_path) {
    std::ifstream file(config_path);
    nlohmann::json config_json;
    file >> config_json;

    api_key = config_json["api_key"].get<std::string>();
    api_secret = config_json["api_secret"].get<std::string>();
    investment_base = config_json["investment_base"].get<std::string>();
    investment_min = config_json["investment_min"].get<double>();
    investment_max = config_json["investment_max"].get<double>();
    investment_step = config_json["investment_step"].get<double>();
    trading_enabled = config_json["trading_enabled"].get<bool>();
    trading_execution_cap = config_json["trading_execution_cap"].get<int>();
    trading_taker_fee = config_json["trading_taker_fee"].get<double>();
    trading_profit_threshold = config_json["trading_profit_threshold"].get<double>();
    trading_age_threshold = config_json["trading_age_threshold"].get<uint64_t>();
    depth_size = config_json["depth_size"].get<int>();
    telegram_enabled = config_json["telegram_enabled"].get<bool>();
    telegram_token = config_json["telegram_token"].get<std::string>();
    telegram_user_id = config_json["telegram_user_id"].get<int64_t>();
}
