/*
 * UnitTest.cpp
 *
 *  Created on: 30 oct. 2016
 *      Author: le_e
 */

//#include "UnitTest.h"
#include "../test/TestUnitTest.h"

namespace common{

template<typename T>
UnitTest<T>::UnitTest()
{}

template<typename T>
UnitTest<T>::~UnitTest()
{}

template<typename T>
void UnitTest<T>::setNameClasse(std::string aStr){
	_nameClasse.assign(aStr);
}

template<typename T>
void UnitTest<T>::addMethod(std::string iStr, void (T::*iPtr)(void)){
	if(iPtr){
		std::pair <std::string, void (T::*)(void)> aPair(iStr, iPtr);
		_list.push_back(aPair);
	}
}

template<typename T>
void UnitTest<T>::luanchMethods(void){
	typedef std::pair <std::string, void (T::*)(void)> pairType;
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	std::cout << _nameClasse << std::endl;
	for(pairType aValue : _list){
		aEchiquier.reset();
		std::cout << "	" << aValue.first;
		(_instance.*(aValue.second))();
		std::cout << "	=> OK" << std::endl;
	}
	std::cout << std::endl;
}

} /* namespace common */
