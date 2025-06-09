cmake_minimum_required(VERSION 3.16)
project(trade_sharpp LANGUAGES CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(fix8_server)
add_subdirectory(fix8_client)