cmake_minimum_required(VERSION 3.10)
project(fix_client)

# Use C++17 standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Compiler flags
add_compile_options(-fexceptions -finline-functions)

# Source files
set(SOURCES
    tradeclient.cpp
    Application.cpp
)

# Add executable
add_executable(fix-client ${SOURCES})

# Link libraries
target_link_libraries(fix-client
    quickfix
    pthread
    xml2
    z
)
