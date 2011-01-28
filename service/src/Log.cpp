/*
 * Logger.cpp
 *
 *  Created on: Jan 19, 2011
 *      Author: ftomale
 */

#include "Log.h"

#include <stddef.h>

Log* Log::instance = NULL;

Log::Log() {

}

Log::~Log() {
	// TODO Auto-generated destructor stub
}

Log* Log::get_instance(){
	if(!Log::instance){
		Log::instance = new Log();
	}
	return Log::instance;
}

void Log::add_logger(const ILogger logger){
	_loggers.push_back(logger);
}

void Log::log(const std::string source, const std::string message){
	vector<ILogger>::const_iterator iterator;
	for(iterator = _loggers.begin(); iterator != _loggers.end(); iterator++){
		*iterator->log(source, message);
	}
}
