/*
 * Socket.cpp
 *
 *  Created on: Jan 26, 2011
 *      Author: ferd
 */

#include <string>
#include <string.h>
#include <arpa/inet.h>
#include <errno.h>

#include "Socket.h"
#include "SocketException.h"

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
		throw new SocketException(SOCKET_EXCEPTION_CREATE,"Unable to create socket.");
	}

	int on = 1;
	if(setsockopt(_sockfid,SOL_SOCKET,SO_REUSEADDR, (const char*) &on, sizeof(on)) < 0){
		throw new SocketException(SOCKET_EXCEPTION_OPTION,"Unable to set socket options.");
	}
}

void Socket::bind(const int port){
	if(is_valid()){

		_sockaddr.sin_family = AF_INET;
		_sockaddr.sin_addr.s_addr = INADDR_ANY;
		_sockaddr.sin_port = htons(port);
		if(::bind(_sockfid, (struct sockaddr *) &_sockaddr, sizeof(_sockaddr)) < 0){
			throw new SocketException(SOCKET_EXCEPTION_BIND,"Unable to bind to socket.");
		}

	} else {
		throw SOCKET_EXCEPTION_BIND;
	}
}

void Socket::listen(const int connections){
	if(is_valid()){

		if(::listen(_sockfid,connections) < 0){
			throw new SocketException(SOCKET_EXCEPTION_BIND,"Unable to listen to socket.");
		}

	} else {
		throw new SocketException(SOCKET_EXCEPTION_LISTEN,"The socket has not been created.");
	}
}

void Socket::accept(Socket* socket){
	socket->_sockfid = ::accept(_sockfid, (struct sockaddr *) &_sockaddr, (socklen_t *) sizeof(_sockaddr));
	if(socket->_sockfid < 0){
		throw new SocketException(SOCKET_EXCEPTION_ACCEPT,"Unable to accept socket.");
	}
}

void Socket::connect(const std::string host, const int port){
	if(is_valid()){

		_sockaddr.sin_family = AF_INET;
		_sockaddr.sin_port = htons(port);
		if(inet_pton(AF_INET, host.c_str(), &_sockaddr) == 1 && errno != EAFNOSUPPORT){

			if(::connect(_sockfid, (sockaddr *) &_sockaddr, (socklen_t) sizeof(_sockaddr)) != 0){
				throw new SocketException(SOCKET_EXCEPTION_CONNECT, "Unable to connect to socket.");
			}

		} else {
			throw new SocketException(SOCKET_EXCEPTION_CONNECT, "Unable to connect to socket.");
		}

	} else {
		throw new SocketException(SOCKET_EXCEPTION_CONNECT, "The socket has not been created.");
	}
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
