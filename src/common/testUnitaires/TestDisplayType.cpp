/*
 * TestDisplayType.cpp
 *
 *  Created on: 12 nov. 2016
 *      Author: le_e
 */

#include "../testUnitaires/TestDisplayType.h"

#include "../src/UnitTest.h"

#include <sstream>

using namespace common;
using namespace std;

TestDisplayType::TestDisplayType()
{}

TestDisplayType::~TestDisplayType()
{}

void TestDisplayType::startTests(){
	UnitTest<TestDisplayType> unitT("TestDisplayType");

	unitT.launchMethods();
}
