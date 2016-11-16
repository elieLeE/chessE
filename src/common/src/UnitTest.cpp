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
UnitTest<T>::UnitTest(const std::string aStr, const bool iDisplay):
_nameClasse(aStr),
_display(iDisplay)
{}

template<typename T>
UnitTest<T>::~UnitTest()
{}

template<typename T>
void UnitTest<T>::addMethod(std::string iStr, void (T::*iPtr)(void) const, bool iIsImplement){
	typeListUnitT aStruct = {iStr, iPtr, iIsImplement};
	_list.push_back(aStruct);
}

template<typename T>
void UnitTest<T>::insertClasseName(void) {
	_stream << _nameClasse;
}

template<typename T>
void UnitTest<T>::display(void){
	if(ALL_DISPLAY || _display){
		std::cout << _stream.str() << std::endl;
	}
	_stream.str("");
}
template<typename T>
void UnitTest<T>::launchMethods(void) {
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	/*std::cout << std::endl;
	std::cout << "UnitTest<T>::launchMethods " <<  _nameClasse << std::endl;
	std::cout << "taille liste : " << _list.size() << std::endl;*/

	insertClasseName();
	if(_list.size() == 0){
		_stream << "		=> TO IMPLEMENT";
	}
	else{
		_stream << std::endl;
		for(typeListUnitT aValue : _list){
			aEchiquier.reset();
			launchMethod(aValue);
		}
		_stream << std::endl;
	}
	display();
}

template<typename T>
void UnitTest<T>::launchMethod(const typeListUnitT iUnitTest) {
	_stream << "	" << iUnitTest.str;
	if(iUnitTest.isImplemented && iUnitTest.ptr){
		(_instance.*(iUnitTest.ptr))();
		_stream << "	=> OK" << std::endl;
	}
	else{
		_stream << "	=> TO IMPLEMENT" << std::endl;
	}
}

} /* namespace common */
