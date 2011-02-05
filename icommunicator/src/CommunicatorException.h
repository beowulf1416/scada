/*
 * CommunicatorException.h
 *
 *  Created on: Feb 5, 2011
 *      Author: ferd
 */

#ifndef COMMUNICATOREXCEPTION_H_
#define COMMUNICATOREXCEPTION_H_

#include <exception>

class CommunicatorException: public std::exception {
public:
	CommunicatorException();
//	virtual ~CommunicatorException();
};

#endif /* COMMUNICATOREXCEPTION_H_ */
