/*
 * ListenerConfiguration.h
 *
 *  Created on: Jan 31, 2011
 *      Author: ftomale
 */

#ifndef LISTENERCONFIGURATION_H_
#define LISTENERCONFIGURATION_H_

#include <string>
#include <map>

enum ListenerTypeEnum {
	LISTENER_TCPIP
};
typedef ListenerTypeEnum ListenerType;

class ListenerConfiguration {

private:
	ListenerType _type;

	static void initialize();
public:
	ListenerConfiguration(const ListenerType type);
	virtual ~ListenerConfiguration();

	ListenerType get_type();
	static ListenerType convert(const std::string typeName);
	static bool exists(const std::string typeName);
};

#endif /* LISTENERCONFIGURATION_H_ */
