/*
 * testUnitTest.cpp
 *
 *  Created on: 6 nov. 2016
 *      Author: le_e
 */

#include "../testUnitaires/TestUnitTest.h"

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
	unitT.addMethod("testC", &common::TestUnitTest::testC, TO_LAUNCH, true);
	unitT.addMethod("testD => OK", &common::TestUnitTest::testD, NOT_YET_IMPLEMENTED);
	unitT.addMethod("testE => OK", 0, NOT_YET_IMPLEMENTED);
	unitT.addMethod("testF => OK", 0, NOT_TO_LAUNCH);

	unitT.launchMethods();
}

void TestUnitTest::testA(void) const{
	BOOST_ASSERT_MSG(true, "testA");
}

void TestUnitTest::testB(void) const{
	BOOST_ASSERT_MSG(true, "testB");
}

void TestUnitTest::testC(void) const{
	cout << "\taffichage attendu " ;
	BOOST_ASSERT_MSG(true, "testB");
}

void TestUnitTest::testD(void) const
{}
