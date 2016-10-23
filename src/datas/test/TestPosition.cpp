/*
 * TestPosition.cpp
 *
 *  Created on: 25 sept. 2016
 *      Author: le_e
 */

#include "TestPosition.h"
#include "../src/typeDefine/Dimension.h"
#include "boost/assert.hpp"
#include "../src/Position.h"

namespace datas {

TestPosition::TestPosition()
{}

TestPosition::~TestPosition()
{}

void TestPosition::startTests(){
	TestPosition aTestPosition;

	aTestPosition.testComparePosition();
	aTestPosition.testSame();
	aTestPosition.testEvaluatePosition();
}

void TestPosition::testComparePosition() const {
	std::cout << "testPosition - compare position";

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

	std::cout << "	OK" << std::endl;
}

void TestPosition::testSame(void) const{
	std::cout << "testPosition - same";

	Position aPosition1(2, 5);
	Position aPosition2(2, 6);
	BOOST_ASSERT_MSG(aPosition1.sameLigne(aPosition2), "test compare sameLigne");

	aPosition2.setPosition(3, 5);
	BOOST_ASSERT_MSG(aPosition1.sameCol(aPosition2), "test compare sameCol");

	std::cout << "	OK" << std::endl;
}

void TestPosition::testEvaluatePosition(void) const{
	std::cout << "testPosition - evaluate position";

	Position aPosition1(2, 5);
	Position aPosition2(4, 6);

	int dist = 5;
	BOOST_ASSERT_MSG(aPosition1.evaluateDistance(aPosition2) == dist, "testPosition evaluatePosition");

	std::cout << "	OK" << std::endl;
}

} /* namespace datas */
