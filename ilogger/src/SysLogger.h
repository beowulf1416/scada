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
public:
	SysLogger();
	virtual ~SysLogger();
};

#endif /* SYSLOGGER_H_ */
