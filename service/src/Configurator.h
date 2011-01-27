/*
 * Configurator.h
 *
 *  Created on: Jan 17, 2011
 *      Author: ftomale
 */

#ifndef CONFIGURATOR_H_
#define CONFIGURATOR_H_

#include <string>

class Configurator {
private:
	static Configurator* instance;

	int port;		// port number
	int cns;		// number of maximum connections

	Configurator();
public:
	static Configurator* get_instance();
	virtual ~Configurator();
	void read(const std::string filename);

	int get_port();
	int get_max_connections();
};

#endif /* CONFIGURATOR_H_ */
