/*
 * UnitTest.h
 *
 *  Created on: 30 oct. 2016
 *      Author: le_e
 */

#ifndef UNITTEST_H_
#define UNITTEST_H_

#include <list>
#include <string>
//#include <pair>

#include "../../game/src/Echiquier.h"

namespace common{

template<typename T>
class UnitTest {
public:
	UnitTest();
	virtual ~UnitTest();

	void setNameClasse(std::string aStr);

	//void setPtr(void (T::*ptr)(void));
	void addMethod(std::string, void (T::*ptr)(void));
	void luanchMethods(void);

private:
	T _instance;
	std::string _nameClasse;
	std::list<std::pair<std::string, void (T::*)(void)> > _list;
};

} /* namespace common */

#include "UnitTest.cpp"

#endif /* UNITTEST_H_ */
