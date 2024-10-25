#include "depth_cache.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <thread>

DepthCache::DepthCache(const std::vector<std::string>& symbol_vec, uint32_t threads_enqueue, uint32_t threads_process_queue) {
    for (const auto& symbol : symbol_vec) {
        map[symbol] = LocalOrderBook();
    }

    start_enqueue_diffs(symbol_vec, threads_enqueue);

    for (uint32_t i = 0; i < threads_process_queue; i++) {
        process_queue_threads.emplace_back(&DepthCache::process_queue, this);
    }
}

LocalOrderBook DepthCache::get_depth(const std::string& symbol) {
    std::unique_lock<std::mutex> lock(map_mutex);
    cv.wait(lock, [this, &symbol] { return map.find(symbol) != map.end(); });
    return map[symbol];
}

void DepthCache::start_enqueue_diffs(const std::vector<std::string>& symbols, uint32_t threads_enqueue) {
    for (uint32_t i = 0; i < threads_enqueue; i++) {
        enqueue_threads.emplace_back([this, symbols]() {
            BinanceWebSocket ws;
            ws.connect(symbols, [this](const DepthOrderBookEvent& event) {
                std::unique_lock<std::mutex> lock(queue_mutex);
                queue.push_back(event);
                queue_cv.notify_one();
            });
        });
    }
}

void DepthCache::process_queue() {
    while (true) {
        std::unique_lock<std::mutex> lock(queue_mutex);
        queue_cv.wait(lock, [this] { return !queue.empty(); });
        auto event = queue.front();
        queue.erase(queue.begin());
        lock.unlock();

        std::unique_lock<std::mutex> map_lock(map_mutex);
        auto& local_order_book = map[event.symbol];
        update_local_order_book(event, local_order_book);
        map_lock.unlock();
        cv.notify_all();
    }
}

void DepthCache::update_local_order_book(const DepthOrderBookEvent& event, LocalOrderBook& lob) {
    lob.first_event = false;
    lob.last_update_id = event.final_update_id;
    lob.event_time = event.event_time;

    for (const auto& ev_bid : event.bids) {
        auto it = std::find_if(lob.bids.begin(), lob.bids.end(), [&ev_bid](const Bids& bid) {
            return std::abs(bid.price - ev_bid.price) < std::numeric_limits<double>::epsilon();
        });
        if (it != lob.bids.end()) {
            if (ev_bid.qty == 0.0) {
                lob.bids.erase(it);
            } else {
                it->qty = ev_bid.qty;
            }
        } else if (ev_bid.qty != 0.0) {
            lob.bids.push_back(ev_bid);
            std::sort(lob.bids.begin(), lob.bids.end(), [](const Bids& a, const Bids& b) {
                return b.price < a.price;
            });
        }
    }

    for (const auto& ev_ask : event.asks) {
        auto it = std::find_if(lob.asks.begin(), lob.asks.end(), [&ev_ask](const Asks& ask) {
            return std::abs(ask.price - ev_ask.price) < std::numeric_limits<double>::epsilon();
        });
        if (it != lob.asks.end()) {
            if (ev_ask.qty == 0.0) {
                lob.asks.erase(it);
            } else {
                it->qty = ev_ask.qty;
            }
        } else if (ev_ask.qty != 0.0) {
            lob.asks.push_back(ev_ask);
            std::sort(lob.asks.begin(), lob.asks.end(), [](const Asks& a, const Asks& b) {
                return a.price < b.price;
            });
        }
    }
}
