cmake_minimum_required(VERSION 3.12)
project(fix8_server)

include_directories(/usr/local/include/fix8)
link_directories(/usr/local/lib)

find_package(Fix8 QUIET)


file(GLOB FIX8_SOURCES
    *.cpp
    *.h
    *.hpp
)
add_executable(fix8_server ${FIX8_SOURCES})

# target_link_libraries(fix8_server
#     PRIVATE
#         Fix8
# )

if(TARGET Fix8::Fix8)
    # Modern CMake: Use imported target if available
    target_link_libraries(fix8_server PRIVATE Fix8::Fix8)
else()
    # Fallback: Link directly (assumes libFix8.so or libFix8.a exists)
    message(STATUS "Linking directly to fix8 library")
    target_link_libraries(fix8_server PRIVATE fix8)
endif()