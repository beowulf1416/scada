/*
 * ConfigurationException.h
 *
 *  Created on: Jan 30, 2011
 *      Author: ferd
 */

#ifndef CONFIGURATIONEXCEPTION_H_
#define CONFIGURATIONEXCEPTION_H_

#include <exception>
#include <string>

typedef enum ConfigExceptionEnum {
	CONFIG_EXCEPTION_PARSE
} ConfigurationExceptionCode;

class ConfigurationException : public std::exception {

private:
	ConfigurationExceptionCode _code;
	std::string _msg;

public:
	ConfigurationException(const ConfigurationExceptionCode code , const std::string msg);
	virtual ~ConfigurationException() throw ();

	ConfigurationExceptionCode get_code();
	std::string get_message();
};

#endif /* CONFIGURATIONEXCEPTION_H_ */
