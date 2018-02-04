/*
 *
 * Copyright 2015 gRPC authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>

#include "generated/remotepos.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;

class Player {
 public:
  Player(std::shared_ptr<Channel> channel)
      : stub_(Greeter::NewStub(channel)) {}

  // Assembles the client's payload, sends it and presents the response back
  // from the server.
  std::string SendCoordinates(const int playerID, const float latitude, const float longitude) {
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

    return reply.Status();
  }

 private:
  std::unique_ptr<remotepos::PositionServer::Stub> stub_;
};

int main(int argc, char** argv) {
  // Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint (in this case,
  // localhost at port 50051). We indicate that the channel isn't authenticated
  // (use of InsecureChannelCredentials()).

  Player player0(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));

  float lat = 47.1;
  float lon = 1.6;
  for ( ; lat < 47.5, lon > -1.55; lat = lat + 0.01, lon = lon - 0.01) {
        remotepos::Status reply = player0.SendCoordinates(0, lat, lon);
        std::cout << "Player received reply: " << reply.errorcode() << std::endl;
  }

  return 0;
}
