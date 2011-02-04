/*
 * MysqlLogger.cpp
 *
 *  Created on: Feb 1, 2011
 *      Author: ferd
 */

#include <stddef.h>
#include <string>
#include <sstream>
#include <mysql.h>
#include <errmsg.h>
#include <LoggerException.h>

#include "MysqlLogger.h"

MysqlLogger::MysqlLogger(const std::string hostname, const std::string username,
		const std::string password, const std::string dbname, const int port,
		const std::string socketfid, const unsigned long flags) {

	if(mysql_init(_cn) == NULL){
		throw new LoggerException(LOG_INIT, mysql_error(_cn));
	}

	if(!mysql_real_connect(_cn, hostname.c_str(), username.c_str(), password.c_str(),
			dbname.c_str(), port, socketfid.c_str(), flags)){
		throw new LoggerException(LOG_INIT, mysql_error(_cn));
	}

}

MysqlLogger::~MysqlLogger() {
	// TODO Auto-generated destructor stub
}

void MysqlLogger::log(const LogLevelType type, const std::string msg){
	std::stringstream s;
	s << "insert into data (date_logged,data) values (now()," << msg;
	std::string sql = s.str();
	switch(mysql_query(_cn,sql.c_str())){
		case CR_COMMANDS_OUT_OF_SYNC:{
			// TODO
			break;
		}
		case CR_SERVER_GONE_ERROR:{
			// TODO
			break;
		}
		case CR_SERVER_LOST:{
			// TODO
			break;
		}
		case CR_UNKNOWN_ERROR:{
			// TODO
			break;
		}
	}
}

void MysqlLogger::close(){
	// no operation
}
