/*
 * Logger.h
 *
 *  Created on: Jan 19, 2011
 *      Author: ftomale
 */

#ifndef LOG_H_
#define LOG_H_

class Log {
private:
	static Log* instance;
	Log();
public:
	static Log* get_instance();
	virtual ~Log();
};

#endif /* LOG_H_ */
