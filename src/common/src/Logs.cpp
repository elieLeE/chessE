/*
 * Logs.cpp
 *
 *  Created on: 17 janv. 2017
 *      Author: le_e
 */

#include "Logs.h"

namespace common {

std::string retrieveDateTime(){
	time_t now = time(0);
	tm *ltm = localtime(&now);

	std::string aStr;

	retrieveDate(ltm, aStr);
	retrieveTime(ltm, aStr);

	return aStr;
}

void retrieveDate(tm *iLtm, std::string& ioStr){
	ioStr = ioStr + std::string(convert(iLtm->tm_mday) + ":" + convert(iLtm->tm_mon+1) + ":" + std::to_string(1900 + iLtm->tm_year));
}

void retrieveTime(tm *iLtm, std::string& ioStr){
	ioStr = ioStr + std::string(" - " + convert(iLtm->tm_hour) + ":" + convert(iLtm->tm_min) + ":" + convert(iLtm->tm_sec));
}

std::string convert(int x){
	std::string aStr;

	if(x<10){
		aStr = std::to_string(0) + std::to_string(x);
	}
	else{
		aStr = std::to_string(x);
	}

	return aStr;
}

std::string filterFileName(const char* s){
	int i = 0;
	std::string aStr;

	while((s[i] == '.') || (s[i] == '/')){
		i++;
	}
	aStr.assign(s + i);

	return aStr;
}

}
