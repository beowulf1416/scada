/*
 * Configurator.h
 *
 *  Created on: Jan 30, 2011
 *      Author: ferd
 */

#ifndef CONFIGURATOR_H_
#define CONFIGURATOR_H_

#include <string>
#include <vector>

#include "ListenerConfiguration.h"

class Configurator {

private:
	static Configurator* _instance;
	Configurator();

	std::vector<ListenerConfiguration> _listeners;
public:
	virtual ~Configurator();
	static Configurator* get_instance();
	void read(const std::string file);

	std::vector<ListenerConfiguration> get_listeners();
};

#endif /* CONFIGURATOR_H_ */
