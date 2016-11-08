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
	UnitTest(std::string aStr);
	virtual ~UnitTest();

	void addMethod(std::string, void (T::*ptr)(void) const, bool isImplement = true);
	void launchMethods(void);

private:
	T _instance;
	std::string _nameClasse;

	struct typeListUnitT{
		std::string str;
		void (T::*ptr)(void) const;
		bool isImplemented;
	};
	std::list<typeListUnitT> _list;
};


} /* namespace common */

#include "UnitTest.cpp"

#endif /* UNITTEST_H_ */
