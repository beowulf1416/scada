/*
 * Syslogger.h
 *
 *  Created on: Jan 19, 2011
 *      Author: ftomale
 */

#ifndef SYSLOGGER_H_
#define SYSLOGGER_H_

#include <string>

#include "../ILogger.h"

class Syslogger: public ILogger {
public:
	Syslogger();
	virtual ~Syslogger();

	virtual void log(string msg);
};

#endif /* SYSLOGGER_H_ */
