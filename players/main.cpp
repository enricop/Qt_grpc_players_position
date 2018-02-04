/*
 * Player
 */

#include <iostream>
#include <memory>
#include <string>
#include <chrono>
#include <thread>

#include <grpc++/grpc++.h>

#include "generated/remotepos.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;

class Player {
 public:
  Player(std::shared_ptr<Channel> channel)
      : stub_(remotepos::PositionServer::NewStub(channel)) {}

  // Assembles the client's payload, sends it and presents the response back
  // from the server.
  bool SendCoordinates(const int playerID, const float latitude, const float longitude) {
    // Data we are sending to the server.
    remotepos::PosData request;
    request.set_playerid(playerID);
    request.set_latitude(latitude);
    request.set_longitude(longitude);

    // Container for the data we expect from the server.
    remotepos::Status reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    grpc::Status status = stub_->updatePosition(&context, request, &reply);

    // Act upon its status.
    if (!status.ok()) {
      std::cout << status.error_code() << ": " << status.error_message() << std::endl;
    }

    return reply.errorcode();
  }

 private:
  std::unique_ptr<remotepos::PositionServer::Stub> stub_;
};

void runPlayer1() {

    Player player1(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));

    float lat = 47.2;
    float lon = - 1.6;

    for ( ; lon > -1.65; lat = lat - 0.01, lon = lon - 0.01) {
          bool reply = player1.SendCoordinates(1, lat, lon);
          std::cout << "Player 1 received reply: " << reply << std::endl;
          std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main(int argc, char** argv) {

  // Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint (in this case,
  // localhost at port 50051). We indicate that the channel isn't authenticated
  // (use of InsecureChannelCredentials()).

  std::thread player1(&runPlayer1);

  Player player0(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));

  float lat = 47.1;
  float lon = - 1.6;

  for ( ; lon < -1.55; lat = lat + 0.01, lon = lon + 0.01) {
        bool reply = player0.SendCoordinates(0, lat, lon);
        std::cout << "Player 0 received reply: " << reply << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  //Join the thread with the main thread
  player1.join();

  return 0;
}
