/*
 * LoggerFactory.h
 *
 *  Created on: Jan 19, 2011
 *      Author: ftomale
 */

#ifndef LOGGERFACTORY_H_
#define LOGGERFACTORY_H_

#include "ILogger.h"

class LoggerFactory {
public:
	LoggerFactory();
	virtual ~LoggerFactory();

	ILogger create();
};

#endif /* LOGGERFACTORY_H_ */
