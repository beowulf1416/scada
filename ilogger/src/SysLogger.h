/*
 * SysLogger.h
 *
 *  Created on: Feb 2, 2011
 *      Author: ferd
 */

#ifndef SYSLOGGER_H_
#define SYSLOGGER_H_

#include "ILogger.h"

class SysLogger: public ILogger {

private:
	std::string _id;
public:
	SysLogger();
	virtual ~SysLogger();

	void log(const LogLevelType type, const std::string source);
	void close();
};

#endif /* SYSLOGGER_H_ */
