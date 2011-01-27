/*
 * Service.cpp
 *
 *  Created on: Jan 26, 2011
 *      Author: ferd
 */

#include "Service.h"

#include <stddef.h>
#include <string.h>
#include <syslog.h>
#include <signal.h>

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

}

void Service::stop(){

}
