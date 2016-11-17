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
_display(iDisplay),
_atLeastOneToImplement(false)
{}

template<typename T>
UnitTest<T>::~UnitTest()
{}

template<typename T>
void UnitTest<T>::addMethod(std::string iStr, void (T::*iPtr)(void) const, bool iIsImplement){
	_atLeastOneToImplement = _atLeastOneToImplement || !iIsImplement;
	typeListUnitT aStruct = {iStr, iPtr, iIsImplement};
	_list.push_back(aStruct);
}

template<typename T>
void UnitTest<T>::insertClasseName(void) {
	_streamAll << _nameClasse;

	if(_atLeastOneToImplement)
		_streamToImplement << _nameClasse;
}

template<typename T>
void UnitTest<T>::display(void){
	if(ALL_DISPLAY || _display){
		std::cout << _streamAll.str() << std::endl;
	}
	else{
		if(_atLeastOneToImplement)
			std::cout << _streamToImplement.str() << std::endl;
	}
	_streamAll.str("");
	_streamToImplement.str("");
}
template<typename T>
void UnitTest<T>::launchMethods(void) {
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	/*std::cout << std::endl;
	std::cout << "UnitTest<T>::launchMethods " <<  _nameClasse << std::endl;
	std::cout << "taille liste : " << _list.size() << std::endl;*/

	insertClasseName();
	if(_list.size() == 0){
		_streamAll << "		=> TO IMPLEMENT";
		_streamToImplement << "		=> TO IMPLEMENT";
	}
	else{
		if(_atLeastOneToImplement){
			_streamToImplement<< std::endl;
		}
		_streamAll << std::endl;
		for(typeListUnitT aValue : _list){
			aEchiquier.reset();
			launchMethod(aValue);
		}
	}
	display();
}

template<typename T>
void UnitTest<T>::launchMethod(const typeListUnitT iUnitTest) {
	_streamAll << "	" << iUnitTest.str;
	if(iUnitTest.isImplemented && iUnitTest.ptr){
		(_instance.*(iUnitTest.ptr))();
		_streamAll << "	=> OK" << std::endl;
	}
	else{
		_streamToImplement << "	" << iUnitTest.str << "		=> TO IMPLEMENT" << std::endl;
		_streamAll << "	=> TO IMPLEMENT" << std::endl;
	}
}

} /* namespace common */
