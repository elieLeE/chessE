/*
 * TestJoueurHumain.cpp
 *
 *  Created on: 8 nov. 2016
 *      Author: le_e
 */

#include "../../testUnitaires/testJoueur/TestJoueurHumain.h"

#include "../../../common/src/UnitTest.h"

using namespace datas;
using namespace common;

TestJoueurHumain::TestJoueurHumain()
{}

TestJoueurHumain::~TestJoueurHumain()
{}

void TestJoueurHumain::startTests(){
	UnitTest<TestJoueurHumain> unitT("TestJoueurHumain");

	unitT.launchMethods();
}
