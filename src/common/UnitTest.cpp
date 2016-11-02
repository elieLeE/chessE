/*
 * UnitTest.cpp
 *
 *  Created on: 30 oct. 2016
 *      Author: le_e
 */

#include "UnitTest.h"

namespace common{

UnitTest::UnitTest():
		aEchiquier(&(game::Echiquier::accessInstance()))
{}

UnitTest::~UnitTest()
{}

void UnitTest::resetEchiquier(void){
	aEchiquier->reset();
}

} /* namespace common */
