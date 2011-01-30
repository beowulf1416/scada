/*
 * Configurator.h
 *
 *  Created on: Jan 30, 2011
 *      Author: ferd
 */

#ifndef CONFIGURATOR_H_
#define CONFIGURATOR_H_

#include <string>

class Configurator {

private:
	static Configurator* _instance;
	Configurator();

public:
	virtual ~Configurator();
	static Configurator* get_instance();
	void read(const std::string file);
};

#endif /* CONFIGURATOR_H_ */
