/*
 * SysLogger.cpp
 *
 *  Created on: Feb 2, 2011
 *      Author: ferd
 */

#include <string>
#include <syslog.h>

#include "ILogger.h"
#include "SysLogger.h"
#include "LoggerException.h"

SysLogger::SysLogger() {
	// TODO Auto-generated constructor stub

}

SysLogger::~SysLogger() {
	// TODO Auto-generated destructor stub
}

void ILogger::log(const LogLevelType level, const std::string msg){
	int logLevel = LOG_LEVEL_DATA;
	switch(level){
		case LOG_LEVEL_INFO:{
			logLevel = LOG_INFO;
			break;
		}
		case LOG_LEVEL_DEBUG:{
			logLevel = LOG_DEBUG;
			break;
		}
		case LOG_LEVEL_DATA:{
			logLevel = LOG_DEBUG;
			break;
		}
		case LOG_LEVEL_ERROR:{
			logLevel = LOG_ERR;
			break;
		}
		case LOG_LEVEL_WARNING:{
			logLevel = LOG_WARNING;
			break;
		}
		default:{
			logLevel = LOG_LEVEL_DATA;
			break;
		}
	}

	syslog(logLevel, msg.c_str(), "");
}
