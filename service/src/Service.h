/*
 * Service.h
 *
 *  Created on: Jan 26, 2011
 *      Author: ferd
 */

#ifndef SERVICE_H_
#define SERVICE_H_

#include "Socket.h"
#include "SocketException.h"

class Service {

private:
	static Service* _instance;
	Service();

	Socket _socket;

public:
	virtual ~Service();

	static Service* get_instance();
	void process_signal(const int signal);

	void start();
	void stop();
};

#endif /* SERVICE_H_ */
