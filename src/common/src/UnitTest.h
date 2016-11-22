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
#include "type/EEtatTest.h"

namespace common{

#define ALL_DISPLAY (bool)false

template<typename T>
class UnitTest {
public:
	UnitTest(const std::string aStr, const bool iDisplay=false);
	virtual ~UnitTest();

	void addMethod(std::string, void (T::*ptr)(void) const, const EEtatTest iEtatTest=TO_LAUNCH);
	void launchMethods(void) ;

private:
	struct typeListUnitT{
		std::string str;
		void (T::*ptr)(void) const;
		const EEtatTest etatTest;
	};

	void launchMethod(const typeListUnitT iUnitTest) ;
	void display(std::string iStr, bool iBool = true);
	void displayClassName(void);
	void display(const EEtatTest iEtatTest, const std::string iLaunchStr,
			const std::string iNotLaunchStr, const std::string iNotImplementStr) const;
	void display(const EEtatTest iEtatTest, const std::string iStr);

	bool displayAll(void) const;
	bool displayImplement(void) const;

	T _instance;
	const std::string _nameClasse;
	const bool _display;
	bool _atLeastOneToImplement;
	std::stringstream _streamAll;
	std::stringstream _streamToImplement;

	std::list<typeListUnitT> _list;
};


} /* namespace common */

#include "UnitTest.cpp"

#endif /* UNITTEST_H_ */

