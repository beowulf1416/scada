/*
 * Logger.h
 *
 *  Created on: Jan 19, 2011
 *      Author: ftomale
 */

#ifndef LOG_H_
#define LOG_H_

#include <string>
#include <vector>

#include "ILogger.h"

class Log {
private:
	static Log* instance;
	Log();

	vector<ILogger> _loggers;

public:
	static Log* get_instance();
	virtual ~Log();

	void add_logger(const ILogger logger);
	void log(const std::string source, const std::string message);
};

#endif /* LOG_H_ */
