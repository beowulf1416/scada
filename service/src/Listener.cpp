/*
 * Listener.cpp
 *
 *  Created on: Jan 17, 2011
 *      Author: ftomale
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>

#include "Listener.h"
#include "Configurator.h"

Listener::Listener(int port) {
	this->sockfd = 0;
	this->port = port;
}

Listener::~Listener() {
	// check if the socket has been opened
	// if open, then close it
	if(this->sockfd > 0){
		int result = shutdown(this->sockfd,SHUT_RDWR);
		// TODO what to do when shutdown fails
	}
}

void Listener::start(){
	this->sockfd = socket(AF_INET,SOCK_STREAM,IP);
	if(sockfd < 0){
		throw SOCKET_EXCEPTION_CREATE;
	}

	// bind to ip address and port
	struct sockaddr_in server_addr, client_addr;
	memset((char*) &server_addr,0,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = Configurator::get_instance()->get_port();
	if(bind(this->sockfd,(struct sockaddr*) &server_addr,sizeof(server_addr)) < 0){
		throw SOCKET_EXCEPTION_BIND;
	}

	// start listening
	if(listen(this->sockfd,Configurator::get_instance()->get_max_connections()) < 0){
		throw SOCKET_EXCEPTION_LISTEN;
	}
}
