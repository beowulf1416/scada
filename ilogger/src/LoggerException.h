/*
 * LoggerException.h
 *
 *  Created on: Feb 1, 2011
 *      Author: ferd
 */

#ifndef LOGGEREXCEPTION_H_
#define LOGGEREXCEPTION_H_

#include <string>
#include <exception>

enum LogEnum {
	LOG_INIT,
	LOG_MSG
};
typedef LogEnum LogType;

class LoggerException: public std::exception {
private:
	LogType _type;
	std::string _msg;
public:
	LoggerException(const LogType type, const std::string message);
	virtual ~LoggerException() throw ();

	LogType get_type();
	std::string get_message();
};

#endif /* LOGGEREXCEPTION_H_ */
