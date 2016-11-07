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

	unitT.addMethod("testA", &common::TestUnitTest::testA);
	unitT.addMethod("testB", &common::TestUnitTest::testB, true);
	unitT.addMethod("test => OK", &common::TestUnitTest::testC, false);

	unitT.luanchMethods();
}

void TestUnitTest::testA(void) const{
	BOOST_ASSERT_MSG(true, "testA");
	cout << "	testA OK	";
}

void TestUnitTest::testB(void) const{
	BOOST_ASSERT_MSG(true, "testB");
	cout << "	testB OK	";
}

void TestUnitTest::testC(void) const
{}
