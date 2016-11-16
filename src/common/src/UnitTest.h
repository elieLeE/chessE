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
#include <iostream>
#include <sstream>

#include "../../game/src/Echiquier.h"

namespace common{

#define ALL_DISPLAY (bool)true

template<typename T>
class UnitTest {
public:
	UnitTest(const std::string aStr, const bool iDisplay=false);
	virtual ~UnitTest();

	void addMethod(std::string, void (T::*ptr)(void) const, bool isImplement = true);
	void launchMethods(void) ;

private:
	T _instance;
	const std::string _nameClasse;
	const bool _display;
	std::stringstream _stream;

	struct typeListUnitT{
		std::string str;
		void (T::*ptr)(void) const;
		bool isImplemented;
	};
	std::list<typeListUnitT> _list;

	void insertClasseName(void) ;
	void launchMethod(const typeListUnitT iUnitTest) ;
	void display(void);
};


} /* namespace common */

#include "UnitTest.cpp"

#endif /* UNITTEST_H_ */
