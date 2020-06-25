// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: wrongthink.proto
#ifndef GRPC_wrongthink_2eproto__INCLUDED
#define GRPC_wrongthink_2eproto__INCLUDED

#include "wrongthink.pb.h"

#include <functional>
#include <grpc/impl/codegen/port_platform.h>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

class wrongthink final {
 public:
  static constexpr char const* service_full_name() {
    return "wrongthink";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    std::unique_ptr< ::grpc::ClientReaderInterface< ::Channel>> GetChannels(::grpc::ClientContext* context, const ::Channel& request) {
      return std::unique_ptr< ::grpc::ClientReaderInterface< ::Channel>>(GetChannelsRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::Channel>> AsyncGetChannels(::grpc::ClientContext* context, const ::Channel& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::Channel>>(AsyncGetChannelsRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::Channel>> PrepareAsyncGetChannels(::grpc::ClientContext* context, const ::Channel& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::Channel>>(PrepareAsyncGetChannelsRaw(context, request, cq));
    }
    virtual ::grpc::Status CreateChannel(::grpc::ClientContext* context, const ::Channel& request, ::Channel* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Channel>> AsyncCreateChannel(::grpc::ClientContext* context, const ::Channel& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Channel>>(AsyncCreateChannelRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Channel>> PrepareAsyncCreateChannel(::grpc::ClientContext* context, const ::Channel& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::Channel>>(PrepareAsyncCreateChannelRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::Message, ::Message>> JoinChannel(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::Message, ::Message>>(JoinChannelRaw(context));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::Message, ::Message>> AsyncJoinChannel(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::Message, ::Message>>(AsyncJoinChannelRaw(context, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::Message, ::Message>> PrepareAsyncJoinChannel(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::Message, ::Message>>(PrepareAsyncJoinChannelRaw(context, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void GetChannels(::grpc::ClientContext* context, ::Channel* request, ::grpc::ClientReadReactor< ::Channel>* reactor) = 0;
      #else
      virtual void GetChannels(::grpc::ClientContext* context, ::Channel* request, ::grpc::experimental::ClientReadReactor< ::Channel>* reactor) = 0;
      #endif
      virtual void CreateChannel(::grpc::ClientContext* context, const ::Channel* request, ::Channel* response, std::function<void(::grpc::Status)>) = 0;
      virtual void CreateChannel(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::Channel* response, std::function<void(::grpc::Status)>) = 0;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void CreateChannel(::grpc::ClientContext* context, const ::Channel* request, ::Channel* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void CreateChannel(::grpc::ClientContext* context, const ::Channel* request, ::Channel* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void CreateChannel(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::Channel* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void CreateChannel(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::Channel* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void JoinChannel(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::Message,::Message>* reactor) = 0;
      #else
      virtual void JoinChannel(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::Message,::Message>* reactor) = 0;
      #endif
    };
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    typedef class experimental_async_interface async_interface;
    #endif
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    async_interface* async() { return experimental_async(); }
    #endif
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientReaderInterface< ::Channel>* GetChannelsRaw(::grpc::ClientContext* context, const ::Channel& request) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::Channel>* AsyncGetChannelsRaw(::grpc::ClientContext* context, const ::Channel& request, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::Channel>* PrepareAsyncGetChannelsRaw(::grpc::ClientContext* context, const ::Channel& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::Channel>* AsyncCreateChannelRaw(::grpc::ClientContext* context, const ::Channel& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::Channel>* PrepareAsyncCreateChannelRaw(::grpc::ClientContext* context, const ::Channel& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientReaderWriterInterface< ::Message, ::Message>* JoinChannelRaw(::grpc::ClientContext* context) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::Message, ::Message>* AsyncJoinChannelRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::Message, ::Message>* PrepareAsyncJoinChannelRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    std::unique_ptr< ::grpc::ClientReader< ::Channel>> GetChannels(::grpc::ClientContext* context, const ::Channel& request) {
      return std::unique_ptr< ::grpc::ClientReader< ::Channel>>(GetChannelsRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::Channel>> AsyncGetChannels(::grpc::ClientContext* context, const ::Channel& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::Channel>>(AsyncGetChannelsRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::Channel>> PrepareAsyncGetChannels(::grpc::ClientContext* context, const ::Channel& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::Channel>>(PrepareAsyncGetChannelsRaw(context, request, cq));
    }
    ::grpc::Status CreateChannel(::grpc::ClientContext* context, const ::Channel& request, ::Channel* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Channel>> AsyncCreateChannel(::grpc::ClientContext* context, const ::Channel& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Channel>>(AsyncCreateChannelRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Channel>> PrepareAsyncCreateChannel(::grpc::ClientContext* context, const ::Channel& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::Channel>>(PrepareAsyncCreateChannelRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReaderWriter< ::Message, ::Message>> JoinChannel(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriter< ::Message, ::Message>>(JoinChannelRaw(context));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::Message, ::Message>> AsyncJoinChannel(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::Message, ::Message>>(AsyncJoinChannelRaw(context, cq, tag));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::Message, ::Message>> PrepareAsyncJoinChannel(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::Message, ::Message>>(PrepareAsyncJoinChannelRaw(context, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void GetChannels(::grpc::ClientContext* context, ::Channel* request, ::grpc::ClientReadReactor< ::Channel>* reactor) override;
      #else
      void GetChannels(::grpc::ClientContext* context, ::Channel* request, ::grpc::experimental::ClientReadReactor< ::Channel>* reactor) override;
      #endif
      void CreateChannel(::grpc::ClientContext* context, const ::Channel* request, ::Channel* response, std::function<void(::grpc::Status)>) override;
      void CreateChannel(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::Channel* response, std::function<void(::grpc::Status)>) override;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void CreateChannel(::grpc::ClientContext* context, const ::Channel* request, ::Channel* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void CreateChannel(::grpc::ClientContext* context, const ::Channel* request, ::Channel* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void CreateChannel(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::Channel* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void CreateChannel(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::Channel* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void JoinChannel(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::Message,::Message>* reactor) override;
      #else
      void JoinChannel(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::Message,::Message>* reactor) override;
      #endif
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientReader< ::Channel>* GetChannelsRaw(::grpc::ClientContext* context, const ::Channel& request) override;
    ::grpc::ClientAsyncReader< ::Channel>* AsyncGetChannelsRaw(::grpc::ClientContext* context, const ::Channel& request, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReader< ::Channel>* PrepareAsyncGetChannelsRaw(::grpc::ClientContext* context, const ::Channel& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::Channel>* AsyncCreateChannelRaw(::grpc::ClientContext* context, const ::Channel& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::Channel>* PrepareAsyncCreateChannelRaw(::grpc::ClientContext* context, const ::Channel& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientReaderWriter< ::Message, ::Message>* JoinChannelRaw(::grpc::ClientContext* context) override;
    ::grpc::ClientAsyncReaderWriter< ::Message, ::Message>* AsyncJoinChannelRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReaderWriter< ::Message, ::Message>* PrepareAsyncJoinChannelRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_GetChannels_;
    const ::grpc::internal::RpcMethod rpcmethod_CreateChannel_;
    const ::grpc::internal::RpcMethod rpcmethod_JoinChannel_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status GetChannels(::grpc::ServerContext* context, const ::Channel* request, ::grpc::ServerWriter< ::Channel>* writer);
    virtual ::grpc::Status CreateChannel(::grpc::ServerContext* context, const ::Channel* request, ::Channel* response);
    virtual ::grpc::Status JoinChannel(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::Message, ::Message>* stream);
  };
  template <class BaseClass>
  class WithAsyncMethod_GetChannels : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_GetChannels() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_GetChannels() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetChannels(::grpc::ServerContext* /*context*/, const ::Channel* /*request*/, ::grpc::ServerWriter< ::Channel>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetChannels(::grpc::ServerContext* context, ::Channel* request, ::grpc::ServerAsyncWriter< ::Channel>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(0, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_CreateChannel : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_CreateChannel() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_CreateChannel() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CreateChannel(::grpc::ServerContext* /*context*/, const ::Channel* /*request*/, ::Channel* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestCreateChannel(::grpc::ServerContext* context, ::Channel* request, ::grpc::ServerAsyncResponseWriter< ::Channel>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_JoinChannel : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_JoinChannel() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_JoinChannel() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status JoinChannel(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::Message, ::Message>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestJoinChannel(::grpc::ServerContext* context, ::grpc::ServerAsyncReaderWriter< ::Message, ::Message>* stream, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncBidiStreaming(2, context, stream, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_GetChannels<WithAsyncMethod_CreateChannel<WithAsyncMethod_JoinChannel<Service > > > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_GetChannels : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_GetChannels() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(0,
          new ::grpc_impl::internal::CallbackServerStreamingHandler< ::Channel, ::Channel>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::Channel* request) { return this->GetChannels(context, request); }));
    }
    ~ExperimentalWithCallbackMethod_GetChannels() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetChannels(::grpc::ServerContext* /*context*/, const ::Channel* /*request*/, ::grpc::ServerWriter< ::Channel>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerWriteReactor< ::Channel>* GetChannels(
      ::grpc::CallbackServerContext* /*context*/, const ::Channel* /*request*/)
    #else
    virtual ::grpc::experimental::ServerWriteReactor< ::Channel>* GetChannels(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::Channel* /*request*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_CreateChannel : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_CreateChannel() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(1,
          new ::grpc_impl::internal::CallbackUnaryHandler< ::Channel, ::Channel>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::Channel* request, ::Channel* response) { return this->CreateChannel(context, request, response); }));}
    void SetMessageAllocatorFor_CreateChannel(
        ::grpc::experimental::MessageAllocator< ::Channel, ::Channel>* allocator) {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(1);
    #else
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::experimental().GetHandler(1);
    #endif
      static_cast<::grpc_impl::internal::CallbackUnaryHandler< ::Channel, ::Channel>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_CreateChannel() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CreateChannel(::grpc::ServerContext* /*context*/, const ::Channel* /*request*/, ::Channel* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* CreateChannel(
      ::grpc::CallbackServerContext* /*context*/, const ::Channel* /*request*/, ::Channel* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* CreateChannel(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::Channel* /*request*/, ::Channel* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_JoinChannel : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_JoinChannel() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(2,
          new ::grpc_impl::internal::CallbackBidiHandler< ::Message, ::Message>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context) { return this->JoinChannel(context); }));
    }
    ~ExperimentalWithCallbackMethod_JoinChannel() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status JoinChannel(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::Message, ::Message>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerBidiReactor< ::Message, ::Message>* JoinChannel(
      ::grpc::CallbackServerContext* /*context*/)
    #else
    virtual ::grpc::experimental::ServerBidiReactor< ::Message, ::Message>* JoinChannel(
      ::grpc::experimental::CallbackServerContext* /*context*/)
    #endif
      { return nullptr; }
  };
  #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
  typedef ExperimentalWithCallbackMethod_GetChannels<ExperimentalWithCallbackMethod_CreateChannel<ExperimentalWithCallbackMethod_JoinChannel<Service > > > CallbackService;
  #endif

  typedef ExperimentalWithCallbackMethod_GetChannels<ExperimentalWithCallbackMethod_CreateChannel<ExperimentalWithCallbackMethod_JoinChannel<Service > > > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_GetChannels : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_GetChannels() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_GetChannels() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetChannels(::grpc::ServerContext* /*context*/, const ::Channel* /*request*/, ::grpc::ServerWriter< ::Channel>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_CreateChannel : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_CreateChannel() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_CreateChannel() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CreateChannel(::grpc::ServerContext* /*context*/, const ::Channel* /*request*/, ::Channel* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_JoinChannel : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_JoinChannel() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_JoinChannel() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status JoinChannel(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::Message, ::Message>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_GetChannels : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_GetChannels() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_GetChannels() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetChannels(::grpc::ServerContext* /*context*/, const ::Channel* /*request*/, ::grpc::ServerWriter< ::Channel>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetChannels(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncWriter< ::grpc::ByteBuffer>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(0, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_CreateChannel : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_CreateChannel() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_CreateChannel() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CreateChannel(::grpc::ServerContext* /*context*/, const ::Channel* /*request*/, ::Channel* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestCreateChannel(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_JoinChannel : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_JoinChannel() {
      ::grpc::Service::MarkMethodRaw(2);
    }
    ~WithRawMethod_JoinChannel() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status JoinChannel(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::Message, ::Message>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestJoinChannel(::grpc::ServerContext* context, ::grpc::ServerAsyncReaderWriter< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* stream, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncBidiStreaming(2, context, stream, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_GetChannels : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_GetChannels() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(0,
          new ::grpc_impl::internal::CallbackServerStreamingHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const::grpc::ByteBuffer* request) { return this->GetChannels(context, request); }));
    }
    ~ExperimentalWithRawCallbackMethod_GetChannels() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetChannels(::grpc::ServerContext* /*context*/, const ::Channel* /*request*/, ::grpc::ServerWriter< ::Channel>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerWriteReactor< ::grpc::ByteBuffer>* GetChannels(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/)
    #else
    virtual ::grpc::experimental::ServerWriteReactor< ::grpc::ByteBuffer>* GetChannels(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_CreateChannel : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_CreateChannel() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(1,
          new ::grpc_impl::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->CreateChannel(context, request, response); }));
    }
    ~ExperimentalWithRawCallbackMethod_CreateChannel() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CreateChannel(::grpc::ServerContext* /*context*/, const ::Channel* /*request*/, ::Channel* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* CreateChannel(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* CreateChannel(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_JoinChannel : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_JoinChannel() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(2,
          new ::grpc_impl::internal::CallbackBidiHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context) { return this->JoinChannel(context); }));
    }
    ~ExperimentalWithRawCallbackMethod_JoinChannel() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status JoinChannel(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::Message, ::Message>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerBidiReactor< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* JoinChannel(
      ::grpc::CallbackServerContext* /*context*/)
    #else
    virtual ::grpc::experimental::ServerBidiReactor< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* JoinChannel(
      ::grpc::experimental::CallbackServerContext* /*context*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_CreateChannel : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_CreateChannel() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler<
          ::Channel, ::Channel>(
            [this](::grpc_impl::ServerContext* context,
                   ::grpc_impl::ServerUnaryStreamer<
                     ::Channel, ::Channel>* streamer) {
                       return this->StreamedCreateChannel(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_CreateChannel() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status CreateChannel(::grpc::ServerContext* /*context*/, const ::Channel* /*request*/, ::Channel* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedCreateChannel(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::Channel,::Channel>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_CreateChannel<Service > StreamedUnaryService;
  template <class BaseClass>
  class WithSplitStreamingMethod_GetChannels : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithSplitStreamingMethod_GetChannels() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::SplitServerStreamingHandler<
          ::Channel, ::Channel>(
            [this](::grpc_impl::ServerContext* context,
                   ::grpc_impl::ServerSplitStreamer<
                     ::Channel, ::Channel>* streamer) {
                       return this->StreamedGetChannels(context,
                         streamer);
                  }));
    }
    ~WithSplitStreamingMethod_GetChannels() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status GetChannels(::grpc::ServerContext* /*context*/, const ::Channel* /*request*/, ::grpc::ServerWriter< ::Channel>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with split streamed
    virtual ::grpc::Status StreamedGetChannels(::grpc::ServerContext* context, ::grpc::ServerSplitStreamer< ::Channel,::Channel>* server_split_streamer) = 0;
  };
  typedef WithSplitStreamingMethod_GetChannels<Service > SplitStreamedService;
  typedef WithSplitStreamingMethod_GetChannels<WithStreamedUnaryMethod_CreateChannel<Service > > StreamedService;
};


#endif  // GRPC_wrongthink_2eproto__INCLUDED
