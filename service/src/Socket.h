/*
 * Socket.h
 *
 *  Created on: Jan 26, 2011
 *      Author: ferd
 */

#ifndef SOCKET_H_
#define SOCKET_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>

#include "SocketException.h"

const int MAX_HOSTNAME = 200;
const int RECEIVE_BUFFER_SIZE = 500;

enum Protocol {
	PROTOCOL_IP = 0
};

class Socket {

private:
	int _sockfid;
	sockaddr_in _sockaddr;

public:
	Socket();
	virtual ~Socket();

	void create();
	void bind(const int port);
	void listen(const int connections);
	void accept(Socket* socket);

	void connect(const std::string host, const int port);

	void send(const std::string data);
	std::string receive();

	void set_non_blocking(const bool blocking);
	bool is_valid();
};

#endif /* SOCKET_H_ */
