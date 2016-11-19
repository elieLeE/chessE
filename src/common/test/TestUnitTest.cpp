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
	unitT.launchMethods();

	unitT.addMethod("testB", &common::TestUnitTest::testB, TO_LAUNCH);
	unitT.addMethod("testC => OK", &common::TestUnitTest::testC, NOT_YET_IMPLEMENTED);
	unitT.addMethod("testD => OK", 0, NOT_YET_IMPLEMENTED);
	unitT.addMethod("testE => OK", 0, NOT_TO_LAUNCH);

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
