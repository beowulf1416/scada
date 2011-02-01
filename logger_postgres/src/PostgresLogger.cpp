/*
 * PostgresLogger.cpp
 *
 *  Created on: Feb 1, 2011
 *      Author: ferd
 */

#include <LoggerException.h>
#include <string>

#include "PostgresLogger.h"

PostgresLogger::PostgresLogger(const std::string hostname, const std::string port,
		const std::string options, const std::string tty, const std::string dbname,
		const std::string username, const std::string password) {
	_cn = PQsetdbLogin(
			hostname.c_str(),
			port.c_str(),
			options.c_str(),
			tty.c_str(),
			dbname.c_str(),
			username.c_str(),
			password.c_str()
		);
	if(PQstatus(_cn) == CONNECTION_BAD){
		throw new LoggerException(LOG_INIT,"Unable to connect to the database");
	}
}

PostgresLogger::~PostgresLogger() {
	// TODO Auto-generated destructor stub
}

void ILogger::log(const LogLevelType type, const std::string source){

}
