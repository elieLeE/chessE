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
void UnitTest<T>::addMethod(std::string iStr, void (T::*iPtr)(void) const, const EEtatTest iEtatTest, const bool iDisplay){
	_atLeastOneToImplement = _atLeastOneToImplement || (iEtatTest==NOT_YET_IMPLEMENTED) || iDisplay;
	typeListUnitT aStruct = {iStr, iPtr, iEtatTest, iDisplay};
	_list.push_back(aStruct);
}

template<typename T>
void UnitTest<T>::display(std::string iStr, bool iBool) const{
	if(iBool)
		std::cout << iStr;
}

template<typename T>
void UnitTest<T>::displayClassName(){
	display(_nameClasse, displayAll() || displayImplement());
}

template<typename T>
void UnitTest<T>::display(const EEtatTest iEtatTest, const std::string iStr, const bool forceDisplay){
	std::string aStr;
	if(displayAll() || displayImplement()){
		aStr.assign(iStr);
	}
	else{
		aStr.assign(_nameClasse + " : " + iStr);
	}
	display(iEtatTest, iStr, iStr, iStr, forceDisplay);
}

template<typename T>
void UnitTest<T>::display(const EEtatTest iEtatTest, const std::string iLaunchStr, const std::string iNotLaunchStr,
		const std::string iNotImplementStr, const bool forceDisplay) const{
	switch(iEtatTest){
	case TO_LAUNCH:
		display(iLaunchStr, displayAll() || forceDisplay);
		break;

	case NOT_TO_LAUNCH:
		display(iNotLaunchStr, displayAll());
		break;

	case NOT_YET_IMPLEMENTED:
		display(iNotImplementStr);
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
	display(iUnitTest.etatTest, "	" + iUnitTest.str, iUnitTest.display);

	if((iUnitTest.etatTest==TO_LAUNCH) && iUnitTest.ptr){
		(_instance.*(iUnitTest.ptr))();
	}

	display(iUnitTest.etatTest, "	=> OK\n", "	=> NOT LAUNCHED\n", "	=> NOT YET IMPLEMENTED\n", iUnitTest.display);
}

} /* namespace common */
