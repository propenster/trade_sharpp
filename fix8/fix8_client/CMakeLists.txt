cmake_minimum_required(VERSION 3.12)
project(fix8_client)

include_directories(/usr/local/include/fix8)
link_directories(/usr/local/lib)


file(GLOB FIX8_SOURCES
    *.cpp
    *.h
    *.hpp
)
add_executable(fix8_client ${FIX8_SOURCES})

# target_link_libraries(fix8_client
#     PRIVATE
#         Fix8
# )

if(TARGET Fix8::Fix8)
    # Modern CMake: Use imported target if available
    target_link_libraries(fix8_client PRIVATE Fix8::Fix8)
else()
    # Fallback: Link directly (assumes libFix8.so or libFix8.a exists)
    target_link_libraries(fix8_client PRIVATE fix8)
endif()