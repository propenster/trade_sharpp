
find_package(Threads)


set(SOURCES
    src/main.cpp
)

# source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES})

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


add_executable(server ${SOURCES})
target_link_libraries(server
    PRIVATE
        myproto
)