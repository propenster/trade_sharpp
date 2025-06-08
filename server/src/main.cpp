#include <iostream>
#include "myproto/order.pb.h"
#include "myproto/order.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <grpcpp/create_channel.h>
#include <memory>


class order_service final : public trade_sharpp::order::Service
{
public:
    virtual grpc::Status order_create(::grpc::ServerContext *context, const trade_sharpp::order_request *request,
                                      trade_sharpp::order_response *response)
    {
        std::cout << "Received order create request: " << request->DebugString() << std::endl;

        // response->set_order_status("Order placed successfully");
        // First order
        response->add_order_id("12345");
        response->add_symbol("AAPL");
        response->add_price(150.25);
        response->add_volume(100);

        // Second order
        response->add_order_id("67890");
        response->add_symbol("GOOG");
        response->add_price(2800.00);
        response->add_volume(50);

        // printOrderResponse(*response);

        return grpc::Status::OK;
    }

    virtual grpc::Status order_cancel(::grpc::ServerContext *context, const trade_sharpp::order_request *request,
                                      trade_sharpp::order_response *response) override
    {
        std::cout << "Received order cancel request: " << request->DebugString() << std::endl;
        // response->set_order_status("Order cancelled successfully");
        return grpc::Status::OK;
    }

    virtual grpc::Status order_update(::grpc::ServerContext *context, const trade_sharpp::order_request *request,
                                      trade_sharpp::order_response *response) override
    {
        std::cout << "Received order update request: " << request->DebugString() << std::endl;
        // response->set_order_status("Order updated successfully");
        return grpc::Status::OK;
    }
}; // <-- Added missing semicolon here

int main(int, char **)
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    trade_sharpp::order_request req;
    trade_sharpp::order_response response{};

    std::cout << "Hello, from trade_sharpp! Let's go\n";

    grpc::ServerBuilder builder;
    builder.AddListeningPort("127.0.0.1:50051", grpc::InsecureServerCredentials());
    // LOG(ERROR) << "Error occurred!";
    // GPR_LOG(GPR_ERROR, "Something went wrong!");

    order_service my_service;
    builder.RegisterService(&my_service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    server->Wait();

    return 0;
}