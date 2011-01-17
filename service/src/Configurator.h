/*
 * Configurator.h
 *
 *  Created on: Jan 17, 2011
 *      Author: ftomale
 */

#ifndef CONFIGURATOR_H_
#define CONFIGURATOR_H_

class Configurator {
public:
	Configurator();
	virtual ~Configurator();
	void read(char *filename);
};

#endif /* CONFIGURATOR_H_ */
