/*
 * main.cpp
 *
 *  Created on: Jan 17, 2011
 *      Author: ftomale
 */

#include <iostream>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <getopt.h>

#define SERVICE_NAME "service"

#define DEFAULT_CONFIG_FILE "/etc/service/service.xml"

#include "Configurator.h"

#include "Service.h"
#include "ServiceException.h"
#include "ConfigurationException.h"

using namespace std;

/**
 * prints help information
 */
void print_usage(const int argc, char *argv[]){
	cout << "Usage: " << SERVICE_NAME << " [OPTIONS] " << endl;
	cout << "OPTIONS" << endl;
	cout << "\t-f filename\tuse specified configuration file" << endl;
	cout << "\t-n\tDo not daemonize. Runs in the foreground\n\t\tinstead of as a background process" << endl;
	cout << "\t-h\tPrints this usage information" << endl;
	cout << "\t--help\tPrints this usage information" << endl;
}

/**
 * handles signals that the service may receive
 * from the system.
 */
void signal_handler(const int sig){
	try {
		Service::get_instance()->process_signal(sig);
	}catch(ServiceException e){
		syslog(LOG_ERR, "Caught service exception: %s", e.get_description().c_str());
	}
}

int main(int argc, char *argv[]){

	// daemonize by default
#if defined(DEBUG)
	bool daemonize = false;
#else
	bool daemonize = true;
#endif

	// setup signal handlers
	signal(SIGHUP,signal_handler);
	signal(SIGTERM,signal_handler);
	signal(SIGINT,signal_handler);
	signal(SIGQUIT,signal_handler);
	signal(SIGABRT,signal_handler);
	signal(SIGSEGV,signal_handler);

	// parse arguments
	char* file = NULL;
	int c;
	while( (c = getopt(argc, argv, "f:nh|help")) != -1){
		switch(c){
			case 'f':{
				file = optarg;
				if(file == NULL){
					cout << SERVICE_NAME << " -f filename" << endl;
					cout << "\t-f option requires filename argument" << endl;
					print_usage(argc, argv);
					exit(EXIT_SUCCESS);
				}
				break;
			}
			case 'n':{
				// do not daemonize
				daemonize = false;
				break;
			}
			case 'h':{
				// show help
				print_usage(argc,argv);
				exit(EXIT_SUCCESS);
				break;
			}
			case '?':{
				// show help
				print_usage(argc,argv);
				exit(EXIT_SUCCESS);
				break;
			}
			default:{
				// show help
				print_usage(argc,argv);
				exit(EXIT_SUCCESS);
				break;
			}
		}
	}

	syslog(LOG_INFO,"%s starting up",SERVICE_NAME);

	// setup sys logging
#if defined(DEBUG)
    setlogmask(LOG_UPTO(LOG_DEBUG));
    openlog(SERVICE_NAME, LOG_CONS | LOG_NDELAY | LOG_PERROR | LOG_PID, LOG_USER);
#else
	setlogmask(LOG_UPTO(LOG_INFO));
	openlog(SERVICE_NAME,LOG_CONS, LOG_USER);
#endif

	// our process id and session id
	pid_t pid;
	pid_t sid;

	if(daemonize){
		syslog(LOG_INFO,"starting background processes");

		// fork off parent process
		pid = fork();
		if(pid < 0){
			exit(EXIT_FAILURE);
		}

		if(pid > 0){
			exit(EXIT_SUCCESS);
		}

		// change file mode mask
		umask(0);

		// create new sid for child process
		sid = setsid();
		if(sid < 0){
			// log failure
			exit(EXIT_FAILURE);
		}

		// change the current working directory
		if(chdir("/") < 0){
			// log failure
			exit(EXIT_FAILURE);
		}

		// close standard file descriptors
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
	}

	// core processing below

	try {
		Configurator::get_instance()->read(file == NULL ? DEFAULT_CONFIG_FILE : file);
		Service::get_instance()->start();
	}catch(ServiceException& e){
		syslog(LOG_ERR, "Unable to start up service %s (%s)", SERVICE_NAME, e.get_description().c_str());
	}catch(ConfigurationException& e){
		syslog(LOG_ERR, "Unable to start up service %s (%s)",SERVICE_NAME, e.get_message().c_str());
	}

	// core processing above

	syslog(LOG_INFO,"%s exiting",SERVICE_NAME);
	exit(EXIT_SUCCESS);
}
