/*
 * PostgresLogger.h
 *
 *  Created on: Feb 1, 2011
 *      Author: ferd
 */

#ifndef POSTGRESLOGGER_H_
#define POSTGRESLOGGER_H_

#include <ILogger.h>

class PostgresLogger: public ILogger {
public:
	PostgresLogger();
	virtual ~PostgresLogger();
};

#endif /* POSTGRESLOGGER_H_ */
