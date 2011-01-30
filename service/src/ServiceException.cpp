/*
 * ServiceException.cpp
 *
 *  Created on: Jan 27, 2011
 *      Author: ftomale
 */

#include "ServiceException.h"

ServiceException::ServiceException(const ServiceException_t code, const std::string message) {
	_code = code;
	_msg = message;
}

ServiceException::~ServiceException() throw (){
	// TODO Auto-generated destructor stub
}
