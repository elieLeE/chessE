/*
 * testUnitTest.cpp
 *
 *  Created on: 6 nov. 2016
 *      Author: le_e
 */

#include "TestUnitTest.h"
#include "../src/UnitTest.h"

#include <list>

using namespace common;
using namespace std;

TestUnitTest::TestUnitTest()
{}

TestUnitTest::~TestUnitTest()
{}

void TestUnitTest::startTests(){
	UnitTest<TestUnitTest> unitT("TestUnitTest");

	unitT.launchMethods();

	unitT.addMethod("testA", &common::TestUnitTest::testA);
	unitT.addMethod("testB", &common::TestUnitTest::testB, true);
	unitT.addMethod("testC => OK", &common::TestUnitTest::testC, false);
	unitT.addMethod("testD => OK", 0, false);
	unitT.addMethod("testD => OK", 0, true, false);

	unitT.launchMethods();
}

void TestUnitTest::testA(void) const{
	BOOST_ASSERT_MSG(true, "testA");
}

void TestUnitTest::testB(void) const{
	BOOST_ASSERT_MSG(true, "testB");
}

void TestUnitTest::testC(void) const
{}
