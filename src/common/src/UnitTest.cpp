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
void UnitTest<T>::addMethod(std::string iStr, void (T::*iPtr)(void) const, const EEtatTest iEtatTest){
	_atLeastOneToImplement = _atLeastOneToImplement || (iEtatTest==NOT_YET_IMPLEMENTED);
	typeListUnitT aStruct = {iStr, iPtr, iEtatTest};
	_list.push_back(aStruct);
}

template<typename T>
void UnitTest<T>::insertClasseName(void) {
	_streamAll << _nameClasse;

	if(_atLeastOneToImplement || (_list.size() == 0))
		_streamToImplement << _nameClasse;
}

template<typename T>
void UnitTest<T>::display(void){
	if(ALL_DISPLAY || _display){
		std::cout << _streamAll.str() << std::endl;
	}
	else{
		if(_atLeastOneToImplement || (_list.size() == 0))
			std::cout << _streamToImplement.str() << std::endl;
	}
	_streamAll.str("");
	_streamToImplement.str("");
}
template<typename T>
void UnitTest<T>::launchMethods(void) {
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	insertClasseName();
	if(_list.size() == 0){
		_streamAll << "		=> NOT YET IMPLEMENTED";
		_streamToImplement << "		=> NOT YET IMPLEMENTED";
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
	if(iUnitTest.iEtatTest==NOT_TO_LAUNCH){
		_streamAll << "	=> NOT LAUNCHED" << std::endl;
	}
	else if((iUnitTest.iEtatTest==TO_LAUNCH) && iUnitTest.ptr){
		(_instance.*(iUnitTest.ptr))();
		_streamAll << "	=> OK" << std::endl;
	}
	else{
		_streamToImplement << "	" << iUnitTest.str << "		=> NOT YET IMPLEMENTED" << std::endl;
		_streamAll << "	=> NOT YET IMPLEMENTED" << std::endl;
	}
}

} /* namespace common */
