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
#include <string>
#include "soci.h"
#include "soci-postgresql.h"
#include "soci-sqlite3.h"

namespace WrongthinkUtils {
  /**
  * @brief sets the database credentials, should only be called once from the
  * main thread at initialization.
  * @param [in] user db username.
  * @param [in] pass db user password.
  */
  void setupPostgres(const std::string& user, const std::string& pass,
    const std::string& dbname);
  void setupSqlite(const std::string &dbname);
  soci::session getSociSession();
  void validateDatabase();
  void clearDatabase();
  extern soci::backend_factory const *dbType_;
  extern std::string dbConnectString_;
}
