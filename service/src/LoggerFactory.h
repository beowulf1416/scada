/*
 * LoggerFactory.h
 *
 *  Created on: Jan 19, 2011
 *      Author: ftomale
 */

#ifndef LOGGERFACTORY_H_
#define LOGGERFACTORY_H_

#include "ILogger.h"
#include "ListenerConfiguration.h"

class LoggerFactory {
public:
	LoggerFactory();
	virtual ~LoggerFactory();

	static ILogger* create(const ListenerConfiguration config);
};

#endif /* LOGGERFACTORY_H_ */
