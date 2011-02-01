/*
 * MysqlLogger.h
 *
 *  Created on: Feb 1, 2011
 *      Author: ferd
 */

#ifndef MYSQLLOGGER_H_
#define MYSQLLOGGER_H_

#include <ILogger.h>

class MysqlLogger: public ILogger {
public:
	MysqlLogger();
	virtual ~MysqlLogger();
};

#endif /* MYSQLLOGGER_H_ */
