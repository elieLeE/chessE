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
UnitTest<T>::UnitTest(std::string aStr):
	_nameClasse(aStr)
{}

template<typename T>
UnitTest<T>::~UnitTest()
{}

template<typename T>
void UnitTest<T>::addMethod(std::string iStr, void (T::*iPtr)(void) const, bool iIsImplement){
	if(iPtr){
		typeListUnitT aStruct = {iStr, iPtr, iIsImplement};
		_aList.push_back(aStruct);
	}
}

template<typename T>
void UnitTest<T>::launchMethods(void){
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	std::cout << _nameClasse << std::endl;
	for(typeListUnitT aValue : _aList){
		aEchiquier.reset();
		std::cout << "	" << aValue.str;
		if(aValue.isImplemented){
			(_instance.*(aValue.ptr))();
			std::cout << "	=> OK" << std::endl;
		}
		else{
			std::cout << "	=> TO IMPLEMENT" << std::endl;
		}
	}
	std::cout << std::endl;
}

} /* namespace common */
