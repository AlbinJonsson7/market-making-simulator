cmake_minimum_required(VERSION 3.20)

project(market_making_simulator VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(market_making_simulator
    src/main.cpp
    src/market.cpp
    src/market_maker.cpp
    src/fill_model.cpp
    src/pnl_tracker.cpp
)

target_include_directories(market_making_simulator
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)