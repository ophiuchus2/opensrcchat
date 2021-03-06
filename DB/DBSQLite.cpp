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
#include "DBSQLite.h"

SQLiteDB::SQLiteDB(const std::string &filename) :
  DBPostgres(soci::sqlite3, filename)
{

}

void SQLiteDB::banUser(const std::string& uname, int days) {
  soci::session sql = getSociSession();
  //convert days to ms
  days = days * 24 * 60 * 60 * 1000;
  int uid;
  sql << "select user_id from users where uname = :uname", use(uname), into(uid);
  if (sql.got_data()) {
    sql << "select * from banned_users where user_id = :uid", use(uid);
    if(sql.got_data()) {
      sql << "update banned_users set expire = cast(strftime('%s', 'now') as int) + :days where user_id = :uid",
            use(days), use(uid);
    } else {
      sql << "insert into banned_users (user_id,expire) values(:uid, cast(strftime('%s', 'now') as int) + :days::integer)",
             use(uid), use(days);
    }//cast(extract(epoch from clock_timestamp()) as int)
  } else {
    throw soci::soci_error("user not found");
  }
}

void SQLiteDB::validate() {
  // assume that the wrongthink database & user have already been created (manually)
  soci::session sql = getSociSession();
  // create tables if they don't already exist
  // create users table
  sql << "create table if not exists users ("
          "user_id           integer    primary key,"
          "uname             varchar(50) unique not null,"
          "token          varchar(50) not null,"
          "admin             boolean default false)";

  sql << "create table if not exists banned_users ("
         "entry_id          integer primary key,"
         "user_id           int references users,"
         "expire            date not null default (cast(strftime('%s', 'now', '+3 days') as int)))";

  sql << "create table if not exists banned_ips ("
         "entry_id          integer primary key,"
         "ip                varchar(50) unique not null,"
         "expire            date not null)";

  // create community table
  sql << "create table if not exists communities ("
          "community_id       integer   primary key,"
          "name               varchar(100) unique not null,"
          "admin              int references users,"
          "public             boolean default true)";

  // create channel table
  sql <<  "create table if not exists channels ("
          "channel_id      integer  primary key,"
          "name            varchar(100) unique not null,"
          "community       int references communities,"
          "admin              int references users,"
          "allow_anon       boolean default true)";

  // create message table
  sql <<  "create table if not exists message ("
          "msg_id         integer primary key,"
          "user_id          int references users,"
          "channel        int references channels,"
          "thread_id      int,"
          "thread_child   boolean not null default false,"
          "edited         boolean default false,"
          "mtext          text not null,"
          "mdate          int not null default (cast(strftime('%s', 'now') as int)))";

  // create control message table
  sql <<  "create table if not exists control_message ("
          "msg_id         integer primary key,"
          "user_id          int references users,"
          "channel        int references channels,"
          "type           varchar(50),"
          "mtext          text not null,"
          "mdate          int not null default (cast(strftime('%s', 'now') as int)))";
}