#ifndef TRADER_H
#define TRADER_H

#include "calculation_cluster.h"
#include "config.h"
#include "depth_cache.h"
#include "trading_pair.h"
#include "triangular_relationship.h"
#include "binance_api.h"

class bTrader {
public:
    bTrader(const std::string& config_path);
    void run();

private:
    CalculationCluster calculation_cluster;
};

#endif // TRADER_H
