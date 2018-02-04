// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: remotepos.proto
#ifndef GRPC_remotepos_2eproto__INCLUDED
#define GRPC_remotepos_2eproto__INCLUDED

#include "remotepos.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/proto_utils.h>
#include <grpc++/impl/codegen/rpc_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/status.h>
#include <grpc++/impl/codegen/stub_options.h>
#include <grpc++/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace remotepos {

class PositionServer final {
 public:
  static constexpr char const* service_full_name() {
    return "remotepos.PositionServer";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status updatePosition(::grpc::ClientContext* context, const ::remotepos::PosData& request, ::remotepos::Status* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::remotepos::Status>> AsyncupdatePosition(::grpc::ClientContext* context, const ::remotepos::PosData& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::remotepos::Status>>(AsyncupdatePositionRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::remotepos::Status>> PrepareAsyncupdatePosition(::grpc::ClientContext* context, const ::remotepos::PosData& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::remotepos::Status>>(PrepareAsyncupdatePositionRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::remotepos::Status>* AsyncupdatePositionRaw(::grpc::ClientContext* context, const ::remotepos::PosData& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::remotepos::Status>* PrepareAsyncupdatePositionRaw(::grpc::ClientContext* context, const ::remotepos::PosData& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status updatePosition(::grpc::ClientContext* context, const ::remotepos::PosData& request, ::remotepos::Status* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::remotepos::Status>> AsyncupdatePosition(::grpc::ClientContext* context, const ::remotepos::PosData& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::remotepos::Status>>(AsyncupdatePositionRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::remotepos::Status>> PrepareAsyncupdatePosition(::grpc::ClientContext* context, const ::remotepos::PosData& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::remotepos::Status>>(PrepareAsyncupdatePositionRaw(context, request, cq));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientAsyncResponseReader< ::remotepos::Status>* AsyncupdatePositionRaw(::grpc::ClientContext* context, const ::remotepos::PosData& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::remotepos::Status>* PrepareAsyncupdatePositionRaw(::grpc::ClientContext* context, const ::remotepos::PosData& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_updatePosition_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status updatePosition(::grpc::ServerContext* context, const ::remotepos::PosData* request, ::remotepos::Status* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_updatePosition : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_updatePosition() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_updatePosition() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status updatePosition(::grpc::ServerContext* context, const ::remotepos::PosData* request, ::remotepos::Status* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestupdatePosition(::grpc::ServerContext* context, ::remotepos::PosData* request, ::grpc::ServerAsyncResponseWriter< ::remotepos::Status>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_updatePosition<Service > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_updatePosition : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_updatePosition() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_updatePosition() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status updatePosition(::grpc::ServerContext* context, const ::remotepos::PosData* request, ::remotepos::Status* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_updatePosition : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_updatePosition() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler< ::remotepos::PosData, ::remotepos::Status>(std::bind(&WithStreamedUnaryMethod_updatePosition<BaseClass>::StreamedupdatePosition, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_updatePosition() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status updatePosition(::grpc::ServerContext* context, const ::remotepos::PosData* request, ::remotepos::Status* response) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedupdatePosition(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::remotepos::PosData,::remotepos::Status>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_updatePosition<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_updatePosition<Service > StreamedService;
};

}  // namespace remotepos


#endif  // GRPC_remotepos_2eproto__INCLUDED