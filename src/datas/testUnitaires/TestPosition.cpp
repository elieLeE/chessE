/*
 * TestPosition.cpp
 *
 *  Created on: 25 sept. 2016
 *      Author: le_e
 */

#include "../testUnitaires/TestPosition.h"

#include <boost/assert.hpp>
#include <sstream>

#include "../../common/src/UnitTest.h"
#include "../src/typeDefine/Dimension.h"
#include "../src/Position.h"

using namespace datas;
using namespace common;
using namespace std;

TestPosition::TestPosition()
{}

TestPosition::~TestPosition()
{}

void TestPosition::startTests(){
	UnitTest<TestPosition> unitT("TestPosition");

	unitT.addMethod("testDefaultPosition", &datas::TestPosition::testDefaultConstructor);
	unitT.addMethod("testOperator == ", &datas::TestPosition::testOperatorEgale);
	unitT.addMethod("testOperator =!", &datas::TestPosition::testOperatorDifference);
	unitT.addMethod("testOperator =", &datas::TestPosition::testOperatorAffectation);
	unitT.addMethod("testSame", &datas::TestPosition::testSame);
	unitT.addMethod("testEvaluateDistance", &datas::TestPosition::testEvaluateDistance);
	unitT.addMethod("testDiffs", &datas::TestPosition::testDiffs);
	unitT.addMethod("testToStream", &datas::TestPosition::testToStream);

	unitT.launchMethods();
}

void TestPosition::testDefaultConstructor(void) const{
	Position aPosition;

	BOOST_ASSERT_MSG(aPosition.getX() == 1, "TestPosition: defaultConstructor - x");
	BOOST_ASSERT_MSG(aPosition.getY() == 1, "TestPosition: defaultConstructor - y");
}

void TestPosition::testOperatorEgale(void) const {
	Position aPosition1(2, 5);
	Position aPosition2(2, 5);

	BOOST_ASSERT_MSG(aPosition1==aPosition2, "testPosition operator ==");
}

void TestPosition::testOperatorDifference(void) const{
	Position aPosition1(2, 5);
	Position aPosition2(3, 2);

	BOOST_ASSERT_MSG(aPosition1!=aPosition2, "testPosition operator !=");
}

void TestPosition::testOperatorAffectation(void) const{
	Position aPosition1(2, 5);
	Position aPosition2(3, 2);

	BOOST_ASSERT_MSG(aPosition1!=aPosition2, "testPosition operator = - before affectation");

	aPosition1 = aPosition2;
	BOOST_ASSERT_MSG(aPosition1==aPosition2, "testPosition operator = - after affectation");
}

void TestPosition::testSame(void) const{
	Position aPosition1(2, 5);
	Position aPosition2(3, 5);
	BOOST_ASSERT_MSG(aPosition1.sameLigne(aPosition2), "testPosition same - ligne");

	aPosition2.setPosition(2, 6);
	BOOST_ASSERT_MSG(aPosition1.sameCol(aPosition2), "testPosiion same - colonne");
}

void TestPosition::testEvaluateDistance(void) const{
	Position aPosition1(2, 5);
	Position aPosition2(4, 6);

	int dist = 5;
	BOOST_ASSERT_MSG(aPosition1.evaluateDistance(aPosition2) == dist, "testPosition evaluatePosition");
}

void TestPosition::testDiffs(void) const{
	Position aPosition1(2, 5);
	Position aPosition2(4, 6);

	BOOST_ASSERT_MSG(aPosition1.diffLigne(aPosition2) == 1, "testPosition diffs - ligne");
	BOOST_ASSERT_MSG(aPosition1.diffCol(aPosition2) == 2, "testPosition diffs - colonne");
}

void TestPosition::testToStream(void) const{
	Position aPosition(2, 5);

	ostream aStream(0);
	stringbuf aStr;
	aStream.rdbuf(&aStr);

	aStream << aPosition;

	BOOST_ASSERT_MSG(aStr.str().compare("(2, 5)") == 0, "testPosition toStream");
}
