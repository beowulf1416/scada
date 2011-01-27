/*
 * SocketException.h
 *
 *  Created on: Jan 27, 2011
 *      Author: ftomale
 */

#ifndef SOCKETEXCEPTION_H_
#define SOCKETEXCEPTION_H_

#include <string>

enum SocketExceptionEnum {
	SOCKET_EXCEPTION_CREATE = 100,
	SOCKET_EXCEPTION_OPTION = 101,
	SOCKET_EXCEPTION_BIND = 102,
	SOCKET_EXCEPTION_LISTEN = 103,
	SOCKET_EXCEPTION_ACCEPT = 104,
	SOCKET_EXCEPTION_CONNECT = 105
};
typedef enum SocketExceptionEnum SocketException_t;

class SocketException {

private:
	SocketException_t _code;
	std::string _msg;

public:
	SocketException(const SocketException_t code, const std::string message):
		_code(code),_msg(message){};
	virtual ~SocketException();

	SocketException_t get_code(){ return _code; };
	std::string get_description(){ return _msg; }
};

#endif /* SOCKETEXCEPTION_H_ */
