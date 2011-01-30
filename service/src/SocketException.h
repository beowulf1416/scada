/*
 * SocketException.h
 *
 *  Created on: Jan 27, 2011
 *      Author: ftomale
 */

#ifndef SOCKETEXCEPTION_H_
#define SOCKETEXCEPTION_H_

#include <exception>
#include <string>

enum SocketExceptionEnum {
	SOCKET_EXCEPTION_CREATE,
	SOCKET_EXCEPTION_OPTION,
	SOCKET_EXCEPTION_BIND,
	SOCKET_EXCEPTION_LISTEN,
	SOCKET_EXCEPTION_ACCEPT,
	SOCKET_EXCEPTION_CONNECT,
	SOCKET_EXCEPTION_SEND,
	SOCKET_EXCEPTION_RECEIVE,
	SOCKET_EXCEPTION_OPTIONS
};
typedef enum SocketExceptionEnum SocketException_t;

class SocketException : public std::exception {

private:
	SocketException_t _code;
	std::string _msg;

public:
	SocketException(const SocketException_t code, const std::string message):
		_code(code),_msg(message){};
	virtual ~SocketException() throw ();

	SocketException_t get_code(){ return _code; };
	std::string get_description(){ return _msg; }
};

#endif /* SOCKETEXCEPTION_H_ */
