#ifndef DEPTH_CACHE_H
#define DEPTH_CACHE_H

#include <unordered_map>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "binance_api.h"

struct LocalOrderBook {
    bool first_event;
    uint64_t last_update_id;
    uint64_t event_time;
    std::vector<Bids> bids;
    std::vector<Asks> asks;

    LocalOrderBook() : first_event(true), last_update_id(0), event_time(0) {}
};

class DepthCache {
public:
    DepthCache(const std::vector<std::string>& symbol_vec, uint32_t threads_enqueue, uint32_t threads_process_queue);
    LocalOrderBook get_depth(const std::string& symbol);

private:
    std::unordered_map<std::string, LocalOrderBook> map;
    std::mutex map_mutex;
    std::condition_variable cv;
    std::vector<std::thread> enqueue_threads;
    std::vector<std::thread> process_queue_threads;
    std::vector<DepthOrderBookEvent> queue;
    std::mutex queue_mutex;
    std::condition_variable queue_cv;

    void start_enqueue_diffs(const std::vector<std::string>& symbols, uint32_t threads_enqueue);
    void process_queue();
    void update_local_order_book(const DepthOrderBookEvent& event, LocalOrderBook& lob);
};

#endif // DEPTH_CACHE_H
