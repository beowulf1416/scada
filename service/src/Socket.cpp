/*
 * Socket.cpp
 *
 *  Created on: Jan 26, 2011
 *      Author: ferd
 */

#include "Socket.h"

Socket::Socket() {
	_sockfid = -1;

	memset(&_sockaddr,0,sizeof(_sockaddr));
}

Socket::~Socket() {
	if(is_valid()){
		close(_sockfid);
	}
}

void Socket::create(){
	_sockfid = socket(AF_INET,SOCK_STREAM,PROTOCOL_IP);
	if(_sockfid < 0){
		throw SOCKET_EXCEPTION_CREATE;
	}

	int on = 1;
	if(setsockopt(_sockfid,SOL_SOCKET,SO_REUSEADDR, (const char*) &on, sizeof(on)) < 0){
		throw SOCKET_EXCEPTION_OPTION;
	}
}

void Socket::bind(const int port){
	if(is_valid()){

		_sockaddr.sin_family = AF_INET;
		_sockaddr.sin_addr = INADDR_ANY;
		_sockaddr.sin_port = htons(port);
		if(::bind(_sockfid,&sockaddr,sizeof(_sockaddr)) < 0){
			throw SOCKET_EXCEPTION_BIND;
		}

	} else {
		throw SOCKET_EXCEPTION_BIND;
	}
}

void Socket::listen(const int connections){
	if(is_valid()){

		if(::listen(_sockfid,connections) < 0){
			throw SOCKET_EXCEPTION_LISTEN;
		}

	} else {
		throw SOCKET_EXCEPTION_LISTEN;
	}
}

bool Socket::accept(const Socket* socket){

}

bool Socket::connect(const std::string host, const int port){

}

bool Socket::send(const std::string data){

}

int Socket::receive(const std::string* data){

}

bool Socket::set_non_blocking(const bool blocking){

}

bool Socket::is_valid(){
	return _sockfid > 0;
}
