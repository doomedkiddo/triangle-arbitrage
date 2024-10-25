#ifndef CALCULATION_CLUSTER_H
#define CALCULATION_CLUSTER_H

#include <unordered_map>
#include <string>
#include <vector>
#include "config.h"
#include "depth_cache.h"
#include "triangular_relationship.h"
#include "binance_api.h"

struct Action {
    TradingPair pair;
    std::string action;
    double quantity;

    Action(const TradingPair& p, const std::string& a, double q) : pair(p), action(a), quantity(q) {}
};

struct Deal {
    double profit;
    uint64_t timestamp;
    std::vector<Action> actions;

    Deal() : profit(-1.0), timestamp(0) {}
};

class CalculationCluster {
public:
    CalculationCluster(const std::unordered_map<std::string, TriangularRelationship>& relationships,
                       DepthCache& depth_cache,
                       const Configuration& config);
    void start();

private:
    std::unordered_map<std::string, TriangularRelationship> relationships;
    DepthCache& depth_cache;
    Configuration config;
    BinanceAccount account;

    uint64_t get_epoch_ms() const;
    double correct_quantity(double quantity, double step) const;
    double custom_round(double quantity, double step) const;
    Deal calculate_relationship(const TriangularRelationship& relationship) const;
    void execute_deal(const Deal& deal);
};

#endif // CALCULATION_CLUSTER_H
