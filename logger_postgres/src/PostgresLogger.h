/*
 * PostgresLogger.h
 *
 *  Created on: Feb 1, 2011
 *      Author: ferd
 */

#ifndef POSTGRESLOGGER_H_
#define POSTGRESLOGGER_H_

#include <string>
#include <postgresql/libpq-fe.h>
#include <LoggerException.h>
#include <ILogger.h>

class PostgresLogger: public ILogger {
private:
	PGconn *_cn;
public:
	PostgresLogger(const std::string hostname, const std::string port,
			const std::string options, const std::string tty, const std::string dbname,
			const std::string username, const std::string password);
	virtual ~PostgresLogger();

	void log(const LogLevelType type, const std::string msg);
};

#endif /* POSTGRESLOGGER_H_ */
