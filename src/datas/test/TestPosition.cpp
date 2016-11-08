/*
 * TestPosition.cpp
 *
 *  Created on: 25 sept. 2016
 *      Author: le_e
 */

#include <boost/assert.hpp>
#include <sstream>

#include "../../common/src/UnitTest.h"
#include "TestPosition.h"
#include "../src/typeDefine/Dimension.h"
#include "../src/Position.h"

using namespace datas;
using namespace common;

TestPosition::TestPosition()
{}

TestPosition::~TestPosition()
{}

void TestPosition::startTests(){
	UnitTest<TestPosition> unitT("TestPosition");

	unitT.addMethod("testComparePosition", &datas::TestPosition::testComparePosition);
	unitT.addMethod("testSame", &datas::TestPosition::testSame);
	unitT.addMethod("testEvaluatePosition", &datas::TestPosition::testEvaluatePosition);
	unitT.addMethod("testDiffs", &datas::TestPosition::testDiffs);
	unitT.addMethod("testToStream", &datas::TestPosition::testToStream);

	unitT.luanchMethods();
}

void TestPosition::testComparePosition() const {
	Position aPosition1(2, 5);
	Position aPosition2(2, 5);
	BOOST_ASSERT_MSG(aPosition1==aPosition2, "testPosition compare - position egales");

	aPosition2.setY(6);
	BOOST_ASSERT_MSG(aPosition1!=aPosition2, "testPosition compare - position differentes");

	aPosition1.setPosition(3, 4);
	aPosition2.setPosition(3, 4);
	BOOST_ASSERT_MSG(aPosition1==aPosition2, "testPosition compare - setPosition");

	aPosition2.setPosition(3, 5);
	BOOST_ASSERT_MSG(aPosition1.sameLigne(aPosition2), "test compare sameLigne");

	aPosition2.setPosition(4, 4);
	BOOST_ASSERT_MSG(aPosition1.sameCol(aPosition2), "test compare sameCol");
}

void TestPosition::testSame(void) const{
	Position aPosition1(2, 5);
	Position aPosition2(2, 6);
	BOOST_ASSERT_MSG(aPosition1.sameLigne(aPosition2), "test compare sameLigne");

	aPosition2.setPosition(3, 5);
	BOOST_ASSERT_MSG(aPosition1.sameCol(aPosition2), "test compare sameCol");
}

void TestPosition::testEvaluatePosition(void) const{
	Position aPosition1(2, 5);
	Position aPosition2(4, 6);

	int dist = 5;
	BOOST_ASSERT_MSG(aPosition1.evaluateDistance(aPosition2) == dist, "testPosition evaluatePosition");
}

void TestPosition::testDiffs(void) const{
	Position aPosition1(2, 5);
	Position aPosition2(4, 6);

	BOOST_ASSERT_MSG(aPosition1.diffLigne(aPosition2) == 2, "testPosition evaluatePosition");
	BOOST_ASSERT_MSG(aPosition1.diffCol(aPosition2) == 1, "testPosition evaluatePosition");
}

void TestPosition::testToStream(void) const{
	Position aPosition(2, 5);

	std::ostream aStream(0);
	std::stringbuf aStr;
	aStream.rdbuf(&aStr);

	aPosition.toStream(aStream);

	BOOST_ASSERT_MSG(aStr.str().compare("2 5") == 0, "testPosition evaluatePosition");
}
