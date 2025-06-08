#include <myproto/order.pb.h>
#include <myproto/order.grpc.pb.h>

#include <grpc/grpc.h>
#include <grpcpp/create_channel.h>

#include <iostream>






void printOrderResponse(const trade_sharpp::order_response& response) {
    int count = response.order_id_size();  // should match symbol_size, price_size, etc.
    for (int i = 0; i < count; ++i) {
        std::cout << "Order " << i + 1 << ":\n";
        std::cout << "  ID:     " << response.order_id(i) << "\n";
        std::cout << "  Symbol: " << response.symbol(i) << "\n";
        std::cout << "  Price:  " << response.price(i) << "\n";
        std::cout << "  Volume: " << response.volume(i) << "\n";
    }
}

int main(int argc, char *argv[])
{
    // Setup request
    trade_sharpp::order_request request;
    trade_sharpp::order_response response;
    request.add_order_id("12345");
    request.add_symbol("AAPL");
    request.add_price(150.25);
    request.add_volume(100);
    request.add_client_order_id("client123");

    request.add_order_id("67890");
    request.add_symbol("GOOG");
    request.add_price(2800.00);
    request.add_volume(50);
    request.add_client_order_id("client456");


    // Call
    auto channel = grpc::CreateChannel("127.0.0.1:50051", grpc::InsecureChannelCredentials());
    std::unique_ptr<trade_sharpp::order::Stub> stub = trade_sharpp::order::NewStub(channel);
    grpc::ClientContext context;
    grpc::Status status = stub->order_create(&context, request, &response);

    if (!status.ok()) {
        std::cerr << "RPC failed: " << status.error_message() << std::endl;
        return 1;
    }
    // Print response
    std::cout << "Response received from server successfully." << std::endl;
    printOrderResponse(response);

    return 0;
}