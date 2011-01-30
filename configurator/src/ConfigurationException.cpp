/*
 * ConfigurationException.cpp
 *
 *  Created on: Jan 30, 2011
 *      Author: ferd
 */

#include "ConfigurationException.h"

#include <string>

ConfigurationException::ConfigurationException(const ConfigurationExceptionCode code , const std::string msg) {
	_code = code;
	_msg = msg;
}

ConfigurationException::~ConfigurationException() throw () {
	// TODO Auto-generated destructor stub
}

ConfigurationExceptionCode ConfigurationException::get_code(){
	return _code;
}

std::string ConfigurationException::get_message(){
	return _msg;
}
