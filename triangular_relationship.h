#ifndef TRIANGULAR_RELATIONSHIP_H
#define TRIANGULAR_RELATIONSHIP_H

#include "trading_pair.h"
#include <array>
#include <string>

class TriangularRelationship {
public:
    TriangularRelationship() = default;
    TriangularRelationship(const std::string& base, const TradingPair& start, const TradingPair& middle, const TradingPair& end);

    std::string describe() const;
    std::array<std::string, 3> get_pairs() const;
    std::array<TradingPair, 3> get_trading_pairs() const;
    std::array<std::string, 3> get_actions() const;
    std::string text() const;
    std::array<std::pair<std::string, std::string>, 3> get_workflow() const;

private:
    std::string base;
    TradingPair start;
    TradingPair middle;
    TradingPair end;
    std::array<std::string, 3> actions;
    std::array<std::string, 3> action_wrappers;
    std::array<std::string, 2> intermediates;
};

#endif // TRIANGULAR_RELATIONSHIP_H
