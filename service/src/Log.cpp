/*
 * Logger.cpp
 *
 *  Created on: Jan 19, 2011
 *      Author: ftomale
 */

#include "Log.h"

#include <stddef.h>

Log* Log::instance = NULL;

Log::Log() {

}

Log::~Log() {
	// TODO Auto-generated destructor stub
}

Log* Log::get_instance(){
	if(!Log::instance){
		Log::instance = new Log();
	}
	return Log::instance;
}
