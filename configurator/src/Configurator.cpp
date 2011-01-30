/*
 * Configurator.cpp
 *
 *  Created on: Jan 30, 2011
 *      Author: ferd
 */

#include "Configurator.h"

#include <stddef.h>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLException.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMException.hpp>
#include <syslog.h>

#include "ConfigurationException.h"

using namespace xercesc;

Configurator* Configurator::_instance = NULL;

Configurator::Configurator() {
	// TODO Auto-generated constructor stub

}

Configurator::~Configurator() {
	// TODO Auto-generated destructor stub
}

Configurator* Configurator::get_instance(){
	if(!Configurator::_instance){
		Configurator::_instance = new Configurator();
	}
	return Configurator::_instance;
}

void Configurator::read(const std::string file){
	try {
		XMLPlatformUtils::Initialize();
	} catch(const XMLException& e){
		char* msg = XMLString::transcode(e.getMessage());
		std::string msg2 = msg;
		syslog(LOG_ERR,"Unable to initialize Xerces: %s", msg);
		XMLString::release(&msg);

		throw new ConfigurationException(CONFIG_EXCEPTION_PARSE, msg2);
	}

	XMLCh sz[100];
	XMLString::transcode("LX",sz,99);
	DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(sz);
	DOMLSParser* parser = ((DOMImplementationLS*) impl)
			->createLSParser(DOMImplementationLS::MODE_SYNCHRONOUS,0);

	const char* fn = file.c_str();
	DOMDocument* doc = 0;

	try {
		doc = parser->parseURI(fn);
	} catch(const XMLException& e){
		char* msg = XMLString::transcode(e.getMessage());
		std::string msg2 = msg;
		syslog(LOG_ERR,"Unable to parse configuration file: '%s' %s", fn, msg);
		XMLString::release(&msg);

		throw new ConfigurationException(CONFIG_EXCEPTION_PARSE, msg2);
	} catch(const DOMException& e){
		char* msg = XMLString::transcode(e.getMessage());
		std::string msg2 = msg;
		syslog(LOG_ERR,"Unable to parse configuration file: '%s' %s", fn, msg);
		XMLString::release(&msg);

		throw new ConfigurationException(CONFIG_EXCEPTION_PARSE, msg2);
	}

	xercesc::XMLPlatformUtils::Terminate();
}
