/*
 * TestPion.cpp
 *
 *  Created on: 29 oct. 2016
 *      Author: le_e
 */
#include <iostream>

#include "../../../common/src/UnitTest.h"
#include "TestPion.h"

using namespace std;
using namespace datas;
using namespace common;

TestPion::TestPion()
{}

TestPion::~TestPion()
{}

void TestPion::startTests(void){
	UnitTest<TestPion> unitT("TestPion");

	unitT.addMethod("testIsValideMove", &datas::TestPion::testIsValideMove, false);

	unitT.luanchMethods();
}

void TestPion::testIsValideMove(void) const{
}
