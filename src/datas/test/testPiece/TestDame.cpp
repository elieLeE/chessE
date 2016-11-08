/*
 * TestDame.cpp
 *
 *  Created on: 29 oct. 2016
 *      Author: le_e
 */
#include <iostream>

#include "../../../common/src/UnitTest.h"
#include "TestDame.h"

using namespace std;
using namespace datas;
using namespace common;

TestDame::TestDame()
{}

TestDame::~TestDame()
{}

void TestDame::startTests(void){
	UnitTest<TestDame> unitT("TestDame");

	unitT.addMethod("testIsValideMove", &datas::TestDame::testIsValideMove, false);

	unitT.luanchMethods();
}

void TestDame::testIsValideMove(void) const{
}
