/*
This file is part of Wrongthink.

Wrongthink - Modern, open & performant chat protocol. Based on gRPC.
Copyright (C) 2020 Ophiuchus2

This program is free software: you can redistribute it and/or modify it under the
terms of the GNU Affero General Public License as published by the Free Software Foundation,
either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License along with this program.
If not, see <https://www.gnu.org/licenses/>.
*/
#include <grpcpp/grpcpp.h>

#include "wrongthink.grpc.pb.h"
#include "Util.h"
#include "SynchronizedChannel.h"
#include <vector>

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

template<class obj>
class ServerReaderWrapper {
public:
  ServerReaderWrapper(): objList{} { }
  ServerReaderWrapper(ServerReader<obj>* _reader): objList{}, reader{_reader} { }

  bool Read(obj* _obj) {
#ifdef GTEST
    static std::vector<obj>::iterator it = objList.begin();
    if(it == objList.end())
      return false;
    *_obj = *it;
    it++;
    return true;
#else
    return reader->Read(_obj);
#endif
  }

  std::vector<obj>& getObjList() { return objList; }

private:
  std::vector<obj> objList;
  ServerReader<obj>* reader;
};

template<class obj>
class ServerWriterWrapper {
public:
  ServerWriterWrapper(): objList{}, writer{} { }
  ServerWriterWrapper(ServerWriter<obj>* _writer): objList{}, writer{_writer} { }

  void Write(const obj& _obj) {
#ifdef GTEST
    objList.append(_obj);
#else
    writer->Write(_obj);
#endif
  }

  std::vector<obj>& getObjList() { return objList; }

private:
  std::vector<obj> objList;
  ServerWriter<obj>* writer;
};

class WrongthinkServiceImpl final : public wrongthink::Service {
public:
  Status GetWrongthinkChannels(ServerContext* context,
    const GetWrongthinkChannelsRequest* request,
    ServerWriter<WrongthinkChannel>* writer) override;

  /* needed to make the rpc function testable */
  Status GetWrongthinkChannelsImpl(const GetWrongthinkChannelsRequest* request,
    ServerWriterWrapper<WrongthinkChannel>* writer);

  Status CreateWrongthinkChannel(ServerContext* context,
    const CreateWrongThinkChannelRequest* request,
    WrongthinkChannel* response) override;

  Status CreateWrongthinkCommunity(ServerContext* context,
    const CreateWrongthinkCommunityRequest* request,
    WrongthinkCommunity* response) override;

  Status SendWrongthinkMessage(ServerContext* context,
    ServerReader< WrongthinkMessage>* reader, WrongthinkMeta* response) override;

  /* needed to make the rpc function testable */
  Status SendWrongthinkMessageImpl(ServerReaderWrapper< WrongthinkMessage>* reader,
    WrongthinkMeta* response);

  Status ListenWrongthinkMessages(ServerContext* context,
    const ListenWrongthinkMessagesRequest* request,
    ServerWriter< WrongthinkMessage>* writer) override;

  /* needed to make the rpc function testable */
  Status ListenWrongthinkMessagesImpl(const ListenWrongthinkMessagesRequest* request,
    ServerWriterWrapper< WrongthinkMessage>* writer);

  Status GetWrongthinkMessages(ServerContext* context,
    const GetWrongthinkMessagesRequest* request,
    ServerWriter< WrongthinkMessage>* writer) override;

  /* needed to make the rpc function testable */
  Status GetWrongthinkMessagesImpl(const GetWrongthinkMessagesRequest* request,
    ServerWriterWrapper< WrongthinkMessage>* writer);

  Status CreateUser(ServerContext* context, const CreateUserRequest* request,
    WrongthinkUser* response) override;
private:
  bool checkForChannel(int channelid, soci::session& sql);

  std::map<int, SynchronizedChannel> channelMap;
  std::mutex channelMapMutex;
};