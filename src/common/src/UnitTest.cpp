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
void UnitTest<T>::addMethod(std::string iStr, void (T::*iPtr)(void) const, bool isImplement){
	if(iPtr){
		typeListUnitTest aPair(iStr, subType(iPtr, isImplement));
		_list.push_back(aPair);
	}
}

template<typename T>
void UnitTest<T>::luanchMethods(void){
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	std::cout << _nameClasse << std::endl;
	for(typeListUnitTest aValue : _list){
		aEchiquier.reset();
		std::cout << "	" << aValue.first;
		if(aValue.second.second){
			(_instance.*(aValue.second.first))();
			std::cout << "	=> OK" << std::endl;
		}
		else{
			std::cout << "	=> TO IMPLEMENT" << std::endl;
		}
	}
	std::cout << std::endl;
}

} /* namespace common */
