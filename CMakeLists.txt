cmake_minimum_required(VERSION 3.16)
project(trade_sharpp LANGUAGES CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(client)
add_subdirectory(server)
add_subdirectory(proto)
# add_subdirectory(fix8)
add_subdirectory(quickfix)