/*
 * ILogger.cpp
 *
 *  Created on: Feb 1, 2011
 *      Author: ferd
 */

#include "ILogger.h"

ILogger::ILogger() {
	// TODO Auto-generated constructor stub

}

ILogger::~ILogger() {
	// TODO Auto-generated destructor stub
}

std::string ILogger::get_id(){
	return _id;
}

void ILogger::set_id(const std::string id){
	_id = id;
}
