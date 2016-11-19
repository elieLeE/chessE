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
void UnitTest<T>::display(std::string iStr, bool iBool){
	if(iBool)
		std::cout << iStr;
}

template<typename T>
void UnitTest<T>::displayClassName(){
	display(_nameClasse, displayAll() || displayImplement());
}

template<typename T>
void UnitTest<T>::display(const EEtatTest iEtatTest, const std::string iStr){
	display(iEtatTest, iStr, iStr, iStr);
}

template<typename T>
void UnitTest<T>::display(const EEtatTest iEtatTest, const std::string iLaunchStr,
		const std::string iNotLaunchStr, const std::string iNotImplementStr) const{
	switch(iEtatTest){
	case TO_LAUNCH:
		if(displayAll()){
			std::cout << iLaunchStr;
		}
		break;

	case NOT_TO_LAUNCH:
		if(displayAll()){
			std::cout << iNotLaunchStr;
		}
		break;

	case NOT_YET_IMPLEMENTED:
		std::cout << iNotImplementStr;
		break;
	}
}

template<typename T>
bool UnitTest<T>::displayAll(void) const{
	return (ALL_DISPLAY || _display);
}

template<typename T>
bool UnitTest<T>::displayImplement(void) const{
	return (_atLeastOneToImplement || _list.size() == 0);
}

template<typename T>
void UnitTest<T>::launchMethods(void) {
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	displayClassName();
	if(_list.size() == 0){
		display("		=> NOT YET IMPLEMENTED\n");
	}
	else{
		display("\n", (displayAll() || displayImplement()));
		for(typeListUnitT aValue : _list){
			aEchiquier.reset();
			launchMethod(aValue);
		}
	}
	display("\n", (displayAll() || displayImplement()));
}

template<typename T>
void UnitTest<T>::launchMethod(const typeListUnitT iUnitTest) {
	display(iUnitTest.etatTest, "	" + iUnitTest.str);

	if((iUnitTest.etatTest==TO_LAUNCH) && iUnitTest.ptr){
		(_instance.*(iUnitTest.ptr))();
	}

	display(iUnitTest.etatTest, "	=> OK\n", "	=> NOT LAUNCHED\n", "	=> NOT YET IMPLEMENTED\n");
}

} /* namespace common */
