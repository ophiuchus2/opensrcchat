#include <iostream>
#include <memory>
#include <string>
#include <mutex>
#include <map>

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "wrongthink.grpc.pb.h"
#include "WrongthinkConfig.h"

#include "SynchronizedChannel.h"
#include "Util.h"

// grpc using statements
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerWriter;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using grpc::Status;
using grpc::StatusCode;

// soci using statements
using soci::session;
using soci::row;
using soci::rowset;
using soci::statement;
using soci::use;
using soci::into;

std::map<int, SynchronizedChannel> channelMap;
std::mutex channelMapMutex;

bool checkForChannel(int channelid, soci::session& sql) {
  if (channelMap.count(channelid) != 1) {
    row r;
    sql << "select name from channels where channel_id = :id",
          use(channelid), into(r);
    if(r.get_indicator(0) != soci::i_null)
      channelMap.emplace( std::piecewise_construct,
                          std::forward_as_tuple(channelid),
                          std::forward_as_tuple(channelid,
                                                r.get<std::string>(0)));
    else
      return false;
  }
  return true;
}

class WrongthinkServiceImpl final : public wrongthink::Service {
  Status GetWrongthinkChannels(ServerContext* context,
    const GetWrongthinkChannelsRequest* request,
    ServerWriter<WrongthinkChannel>* writer) {
    (void)context;
    try {
      soci::session sql = WrongthinkUtils::getSociSession();
      rowset<row> rs = (sql.prepare << "select channel_id, name, "
                                    << "allow_anon from channels");
      for (rowset<row>::const_iterator it = rs.begin(); it != rs.end(); ++it) {
        WrongthinkChannel channel;
        row const& row = *it;
        channel.set_channelid(row.get<int>(0));
        channel.set_name(row.get<std::string>(1));
        channel.set_anonymous(row.get<bool>(2));
        writer->Write(channel);
      }
    } catch (const std::exception& e) {
      std::cout << e.what() << std::endl;
      return Status(StatusCode::INTERNAL, "");
    }
    return Status::OK;
  }

  Status CreateWrongthinkChannel(ServerContext* context,
    const WrongthinkChannel* request, WrongthinkChannel* response) {
    (void)context;
    try {
      int channel_id = request->channelid();
      char anonymous = request->anonymous();
      std::string name = request->name();
      soci::session sql = WrongthinkUtils::getSociSession();
      sql << "insert into channels(channel_id,name, "
          << "allow_anon) "
          << "values(:channel_id,:name,:anonymous)",
          use(channel_id), use(name), use(anonymous);
      response->set_channelid(1);
    } catch (const std::exception& e) {
      std::cout << e.what() << std::endl;
      return Status(StatusCode::INTERNAL, "");
    }
    return Status::OK;
  }

  Status SendWrongthinkMessage(ServerContext* context,
    ServerReader< WrongthinkMessage>* reader, WrongthinkMeta* response) {
    (void) context;
    (void) response;
    WrongthinkMessage msg;
    try {
      soci::session sql = WrongthinkUtils::getSociSession();
      int channelid = 0;
      int uname = 0;
      int thread_id = 0;
      char thread_child = 0;
      std::string text;
      statement st = (sql.prepare <<
                "insert into message(uname,channel,thread_id,thread_child)"
                <<" values(:uname,:channel,:thread_id,:thread_child)",
                use(uname), use(channelid), use(thread_id), use(thread_child));
      while (reader->Read(&msg)) {
        channelid = msg.channelid();
        uname = msg.userid();
        thread_id = msg.threadid();
        thread_child = msg.threadchild();
        text = msg.text();
        if(!checkForChannel(msg.channelid(), sql))
          return Status(StatusCode::INVALID_ARGUMENT, "");
        channelMap[msg.channelid()].appendMessage(msg);
        st.execute(true);
      }
    } catch (const std::exception& e) {
      std::cout << e.what() << std::endl;
      return Status(StatusCode::INTERNAL, "");
    }
    return Status::OK;
  }

  Status ListenWrongthinkMessages(ServerContext* context,
    const ListenWrongthinkMessagesRequest* request,
    ServerWriter< WrongthinkMessage>* writer) {
    (void) context;
    (void) request;
    soci::session sql = WrongthinkUtils::getSociSession();
    int channelid = request->channelid();
    int count = 0;
    if (!checkForChannel(channelid, sql))
      return Status(StatusCode::INVALID_ARGUMENT, "");
    SynchronizedChannel& channel = channelMap[request->channelid()];
    // first write all the current messages in the channel
    std::vector<WrongthinkMessage> messages = channel.getMessages();
    for (auto& msg : messages)
      writer->Write(msg);
    while (true) {
      writer->Write(channel.waitMessage());
    }
    return Status::OK;
  }

};

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  WrongthinkServiceImpl service;

  grpc::EnableDefaultHealthCheckService(false);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main(int argc, char** argv) {
  //RunServer();
  std::cout << "wrongthink version: "
    << Wrongthink_VERSION_MAJOR
    << "."
    << Wrongthink_VERSION_MINOR << std::endl;

  try {
    std::cout << "validating sql tables." << std::endl;
    WrongthinkUtils::setCredentials("wrongthink", "test");
    WrongthinkUtils::validateDatabase();
  }
  catch (const std::exception& e) {
    // unexpecdted, terminate
    std::cout << e.what() << std::endl;
    return 0;
  }
  RunServer();

  return 0;
}
