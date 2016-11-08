/*
 * TestFou.cpp
 *
 *  Created on: 29 oct. 2016
 *      Author: le_e
 */
#include <iostream>

#include "../../../common/src/UnitTest.h"
#include "TestFou.h"

using namespace std;
using namespace datas;
using namespace common;

TestFou::TestFou()
{}

TestFou::~TestFou()
{}

void TestFou::startTests(void){
	UnitTest<TestFou> unitT("TestFou");

	unitT.addMethod("testIsValideMove", &datas::TestFou::testIsValideMove, false);

	unitT.luanchMethods();
}

void TestFou::testIsValideMove(void) const{
}
