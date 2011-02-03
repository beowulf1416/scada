/*
 * Service.cpp
 *
 *  Created on: Jan 26, 2011
 *      Author: ferd
 */

#include "Service.h"
#include "ILogger.h"
#include "LoggerFactory.h"
#include "Configurator.h"
#include "ListenerConfiguration.h"

#include <stddef.h>
#include <string.h>
#include <syslog.h>
#include <signal.h>
#include <sstream>

Service* Service::_instance = NULL;

Service::Service() {
	// TODO Auto-generated constructor stub

}

Service::~Service() {
	// TODO Auto-generated destructor stub
}

Service* Service::get_instance(){
	if(!Service::_instance){
		Service::_instance = new Service();
	}
	return Service::_instance;
}

void Service::process_signal(const int signal){
	switch(signal){
		case SIGTERM:{ // termination
			syslog(LOG_NOTICE,"Received SIGTERM. Stopping service.");
			stop();
			break;
		}
		case SIGABRT:{ // abort
			syslog(LOG_NOTICE,"Received SIGABRT. Stopping service.");
			stop();
			break;
		}
		case SIGSEGV:{ // segmentation fault
			syslog(LOG_ERR,"Received SIGSEGV. Stopping service.");
			stop();
			break;
		}
		default:{
			syslog(LOG_WARNING,"Unhandled signal %d (%s)",signal,strsignal(signal));
			break;
		}
	}
}

void Service::start(){
	std::vector<ListenerConfiguration> listeners = Configurator::get_instance()
		->get_listeners();
	std::vector<ListenerConfiguration>::iterator iterator;
	for(iterator = listeners.begin(); iterator != listeners.end(); iterator++){
		ILogger* logger = LoggerFactory::create(*iterator);
		if(logger != NULL){
			_loggers.push_back(*logger);
		}
	}
}

void Service::stop(){
	std::vector<ILogger>::iterator iterator;
	for(iterator = _loggers.begin(); iterator != _loggers.end(); iterator++){
		try {
			iterator->close();
		} catch(std::exception& e){
			std::stringstream s;
			s << iterator->get_id();
			syslog(LOG_ERR,"Unable to close logger %s", s.str().c_str());
		}
	}
}
