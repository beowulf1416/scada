/*
 * ILogger.h
 *
 *  Created on: Feb 1, 2011
 *      Author: ferd
 */

#ifndef ILOGGER_H_
#define ILOGGER_H_

#include <string>

enum LogLevelEnum {
	LOG_LEVEL_DEBUG,
	LOG_LEVEL_INFO,
	LOG_LEVEL_DATA,
	LOG_LEVEL_ERROR,
	LOG_LEVEL_WARNING
};
typedef LogLevelEnum LogLevelType;

class ILogger {
public:
	ILogger();
	virtual ~ILogger();

	virtual void log(const LogLevelType level, const std::string source);
};

#endif /* ILOGGER_H_ */
