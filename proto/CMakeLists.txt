find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

set(Protobuf_PROTOC_EXECUTABLE /usr/bin/protoc)

find_package(Threads)
# Protobuf/Grpc source files
set(PROTO_FILES
    myproto/order.proto
)


add_library(myproto ${PROTO_FILES})
target_link_libraries(myproto
    PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
)
target_include_directories(myproto PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

# Compile protobuf and grpc files in myproto target to cpp
get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
protobuf_generate(TARGET myproto LANGUAGE cpp)
protobuf_generate(TARGET myproto LANGUAGE grpc GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")