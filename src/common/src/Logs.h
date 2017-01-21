/*
 * Logs.h
 *
 *  Created on: 17 janv. 2017
 *      Author: le_e
 */

#ifndef COMMON_SRC_LOGS_H_
#define COMMON_SRC_LOGS_H_

#include <ctime>
#include <iostream>

namespace common {


std::string retrieveDateTime();

void retrieveDate(tm *iLtm, std::string& ioStr);
void retrieveTime(tm *iLtm, std::string& ioStr);
std::string convert(int x);

std::string filterFileName(const char* s);

}

#endif /* COMMON_SRC_LOGS_H_ */
