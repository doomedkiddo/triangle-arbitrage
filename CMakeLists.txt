cmake_minimum_required(VERSION 3.10)
project(btrader CXX)

set(CMAKE_CXX_STANDARD 17)

# Find required libraries
find_package(CURL REQUIRED)
find_package(Threads REQUIRED)

# Include directories
include_directories(${CMAKE_SOURCE_DIR})

# Source files
set(SOURCES
    calculation_cluster.cpp
    config.cpp
    depth_cache.cpp
    main.cpp
    trader.cpp
    trading_pair.cpp
    triangular_relationship.cpp
    binance_api.cpp
)

# Header files
set(HEADERS
    calculation_cluster.h
    config.h
    depth_cache.h
    trader.h
    trading_pair.h
    triangular_relationship.h
    binance_api.h
)

# Add executable
add_executable(btrader ${SOURCES} ${HEADERS})

# Link libraries
target_link_libraries(btrader ${CURL_LIBRARIES} Threads::Threads)
