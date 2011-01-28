/*
 * ILogger.h
 *
 *  Created on: Jan 19, 2011
 *      Author: ftomale
 */

#ifndef ILOGGER_H_
#define ILOGGER_H_

#include <string>

using namespace std;

class ILogger {
public:
	ILogger();
	virtual ~ILogger();

	virtual void log(const std::string source, const std::string msg);
};

#endif /* ILOGGER_H_ */
