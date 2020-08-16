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
#include "Util.h"

namespace WrongthinkUtils {
  std::string dbUname_;
  std::string dbPass_;
  std::string dbName_;
  std::string dbConnectString_;
  soci::backend_factory const *dbType_;

  void setupPostgres(const std::string& user, const std::string& pass,
    const std::string& dbname) {
    dbType_ = &soci::postgresql;
    dbConnectString_ = "host=localhost dbname=" + dbname + " user=" + user + " password=" + pass;
  }

  void setupSqlite(const std::string &dbname) {
    dbType_ = &soci::sqlite3;
    dbConnectString_ = dbname;
  }

  soci::session getSociSession() {
    return soci::session(*dbType_, dbConnectString_);
  }

  void clearDatabase() {
    soci::session sql(*dbType_, dbConnectString_);
    sql << "drop table if exists message";
    sql << "drop table if exists control_message";
    sql << "drop table if exists channels";
    sql << "drop table if exists communities";
    sql << "drop table if exists users";
  }

  void validateDatabase() {
    // assume that the wrongthink database & user have already been created (manually)
    soci::session sql(*dbType_, dbConnectString_);
    // create tables if they don't already exist
    // create users table
    sql << "create table if not exists users ("
            "user_id           serial    primary key,"
            "uname             varchar(50) unique not null,"
            "password          varchar(50) not null,"
            "admin             boolean default false)";

    // create community table
    sql << "create table if not exists communities ("
            "community_id       serial   primary key,"
            "name               varchar(100) unique not null,"
            "admin              int references users,"
            "public             boolean default true)";

    // create channel table
    sql <<  "create table if not exists channels ("
            "channel_id      serial  primary key,"
            "name            varchar(100) unique not null,"
            "community       int references communities,"
            "admin              int references users,"
            "allow_anon       boolean default true)";

    // create message table
    sql <<  "create table if not exists message ("
            "msg_id         serial primary key,"
            "user_id          int references users,"
            "channel        int references channels,"
            "thread_id      int,"
            "thread_child   boolean not null default false,"
            "edited         boolean default false,"
            "mtext          text not null,"
            "mdate          date not null default now())";

    // create control message table
    sql <<  "create table if not exists control_message ("
            "msg_id         serial primary key,"
            "user_id          int references users,"
            "channel        int references channels,"
            "type           varchar(50),"
            "mtext          text not null,"
            "mdate          date not null default now())";
  }
}
