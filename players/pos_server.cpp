/*
 * Backend
 */

#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>

#include "generated/remotepos.grpc.pb.h"

#include "pos_server.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;

using remotepos::PositionServer;

// Logic and data behind the server's behavior.
class PositionServerImpl final : public PositionServer::Service {

    grpc::Status updatePosition(ServerContext* context, const remotepos::PosData* request, remotepos::Status* reply) override {

        if (request->playerid() >= 0 && request->playerid() < 4)  {
            emit mainthreadpointer->newPosition(request->playerid(), request->latitude(), request->longitude());

            reply->set_errorcode(true);

        } else {
            reply->set_errorcode(false);
        }

        return grpc::Status::OK;
    }

public:
    void setThreadPointer(PosServerThread* pointer) {
        mainthreadpointer = pointer;
    }

private:
    PosServerThread* mainthreadpointer;
};

PosServerThread::PosServerThread(QObject *parent)
    : QThread(parent)
{

}

PosServerThread::~PosServerThread()
{

}

void PosServerThread::run() {
    std::string server_address("0.0.0.0:50051");
    PositionServerImpl service0;

    service0.setThreadPointer(this);

    ServerBuilder builder;
    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(&service0);

    // Finally assemble the server.
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    server->Wait();
}
