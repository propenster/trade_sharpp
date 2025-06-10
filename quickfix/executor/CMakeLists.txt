cmake_minimum_required(VERSION 3.10)
project(fix_executor)

# Use C++17 standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags
add_compile_options(-fexceptions -finline-functions)

# Source files
set(SOURCES
    executor.cpp
    Application.cpp
)

# Add executable
add_executable(fix-executor ${SOURCES})

# Link libraries
target_link_libraries(fix-executor
    quickfix
    pthread
    xml2
    z
)
