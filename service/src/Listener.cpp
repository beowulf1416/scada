/*
 * Listener.cpp
 *
 *  Created on: Jan 17, 2011
 *      Author: ftomale
 */

#include <sys/socket.h>

#include "Listener.h"

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

void Listener::listen(){
	this->sockfd = socket(AF_INET,SOCK_STREAM,IP);
	if(sockfd < 0){
		throw SOCKET_EXCEPTION_CREATE;
	}
}
