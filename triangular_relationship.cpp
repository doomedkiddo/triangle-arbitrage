#include "triangular_relationship.h"

TriangularRelationship::TriangularRelationship(const std::string& base, const TradingPair& start, const TradingPair& middle, const TradingPair& end)
    : base(base), start(start), middle(middle), end(end) {
    std::string next_base;
    if (base == start.get_base_asset()) {
        actions[0] = "SELL";
        action_wrappers[0] = "bids";
        next_base = start.get_quote_asset();
        intermediates[0] = start.get_quote_asset();
    } else {
        actions[0] = "BUY";
        action_wrappers[0] = "asks";
        next_base = start.get_base_asset();
        intermediates[0] = start.get_base_asset();
    }

    if (next_base == middle.get_base_asset()) {
        actions[1] = "SELL";
        action_wrappers[1] = "bids";
        next_base = middle.get_quote_asset();
        intermediates[1] = middle.get_quote_asset();
    } else {
        actions[1] = "BUY";
        action_wrappers[1] = "asks";
        next_base = middle.get_base_asset();
        intermediates[1] = middle.get_base_asset();
    }

    if (next_base == end.get_base_asset()) {
        actions[2] = "SELL";
        action_wrappers[2] = "bids";
    } else {
        actions[2] = "BUY";
        action_wrappers[2] = "asks";
    }
}

std::string TriangularRelationship::describe() const {
    return actions[0] + " from " + start.text() + ", then " + actions[1] + " from " + middle.text() + " and finally " + actions[2] + " from " + end.text();
}

std::array<std::string, 3> TriangularRelationship::get_pairs() const {
    return {start.get_symbol(), middle.get_symbol(), end.get_symbol()};
}

std::array<TradingPair, 3> TriangularRelationship::get_trading_pairs() const {
    return {start, middle, end};
}

std::array<std::string, 3> TriangularRelationship::get_actions() const {
    return actions;
}

std::string TriangularRelationship::text() const {
    return base + " -> " + intermediates[0] + " -> " + intermediates[1];
}

std::array<std::pair<std::string, std::string>, 3> TriangularRelationship::get_workflow() const {
    return {{start.get_symbol(), action_wrappers[0]}, {middle.get_symbol(), action_wrappers[1]}, {end.get_symbol(), action_wrappers[2]}};
}
