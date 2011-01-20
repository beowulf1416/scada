/*
 * Listener.h
 *
 *  Created on: Jan 17, 2011
 *      Author: ftomale
 */

#ifndef LISTENER_H_
#define LISTENER_H_

// documented in /etc/protocols
enum _Protocol {
	IP = 0
};
typedef enum _Protocol Protocol;

// exceptions
enum _ListenerException {
	SOCKET_EXCEPTION_CREATE = 100,	// unable to create
	SOCKET_EXCEPTION_BIND = 101,	// unable to bind
	SOCKET_EXCEPTION_LISTEN = 102	// unable to listen
};
typedef enum _ListenerException ListenerException;

class Listener {
private:
	int sockfd; 	// socket file descriptor
	int port;

public:
	Listener(int port);
	virtual ~Listener();

	void start();
};

#endif /* LISTENER_H_ */
