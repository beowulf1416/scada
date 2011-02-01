/*
 * LoggerException.cpp
 *
 *  Created on: Feb 1, 2011
 *      Author: ferd
 */

#include "LoggerException.h"

LoggerException::LoggerException(const LogType type, const std::string message) {
	_type = type;
	_msg = message;
}

LoggerException::~LoggerException() throw (){
	// TODO Auto-generated destructor stub
}

LogType LoggerException::get_type(){
	return _type;
}

std::string LoggerException::get_message(){
	return _msg;
}
