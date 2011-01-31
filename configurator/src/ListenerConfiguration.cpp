/*
 * ListenerConfiguration.cpp
 *
 *  Created on: Jan 31, 2011
 *      Author: ftomale
 */

#include "ListenerConfiguration.h"

#include <string>
#include <map>
#include <assert.h>

static std::map<std::string,ListenerType> _listenerTypes;

ListenerConfiguration::ListenerConfiguration(const ListenerType type) {
	_type = type;
}

ListenerConfiguration::~ListenerConfiguration() {
	// TODO Auto-generated destructor stub
}

ListenerType ListenerConfiguration::get_type(){
	return _type;
}

void ListenerConfiguration::initialize(){
	if(_listenerTypes.size() == 0){
		_listenerTypes["tcpip"] = LISTENER_TCPIP;
	}
}

ListenerType ListenerConfiguration::convert(const std::string typeName){
	assert(_listenerTypes.size() > 0);
	assert(_listenerTypes.find(typeName) != _listenerTypes.end());

	return _listenerTypes[typeName];
}

bool ListenerConfiguration::exists(const std::string typeName){
	assert(_listenerTypes.size() > 0);

	return _listenerTypes.find(typeName) != _listenerTypes.end();
}
