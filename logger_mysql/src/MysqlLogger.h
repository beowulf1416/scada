/*
 * MysqlLogger.h
 *
 *  Created on: Feb 1, 2011
 *      Author: ferd
 */

#ifndef MYSQLLOGGER_H_
#define MYSQLLOGGER_H_

#include <ILogger.h>

#include <mysql.h>
#include <string>

class MysqlLogger: public ILogger {

private:
	MYSQL *_cn;
public:
	MysqlLogger(const std::string hostname, const std::string username,
			const std::string password, const std::string dbname, const int port,
			const std::string socketfid, const unsigned long flags);
	virtual ~MysqlLogger();
};

#endif /* MYSQLLOGGER_H_ */
