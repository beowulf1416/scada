/*
 * Configurator.cpp
 *
 *  Created on: Jan 17, 2011
 *      Author: ftomale
 */

#include "Configurator.h"

#include <stddef.h>

Configurator* Configurator::instance = NULL;

Configurator::Configurator() {
	// TODO Auto-generated constructor stub

}

Configurator::~Configurator() {
	// TODO Auto-generated destructor stub
}

Configurator* Configurator::get_instance(){
	if(!Configurator::instance){
		Configurator::instance = new Configurator();
	}
	return Configurator::instance;
}

void Configurator::read(const std::string filename){

}

int Configurator::get_port(){
	return this->port;
}

int Configurator::get_max_connections(){
	return this->cns;
}
