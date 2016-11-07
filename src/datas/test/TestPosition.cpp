/*
 * TestPosition.cpp
 *
 *  Created on: 25 sept. 2016
 *      Author: le_e
 */

#include <boost/assert.hpp>
#include <sstream>

#include "TestPosition.h"
#include "../src/typeDefine/Dimension.h"
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
	aTestPosition.testDiffs();
	aTestPosition.testToStream();
	std::cout << std::endl;
}

void TestPosition::testComparePosition() const {
	std::cout << "TestPosition - compare position";

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
	std::cout << "TestPosition - sameLigne/sameCol";

	Position aPosition1(2, 5);
	Position aPosition2(2, 6);
	BOOST_ASSERT_MSG(aPosition1.sameLigne(aPosition2), "test compare sameLigne");

	aPosition2.setPosition(3, 5);
	BOOST_ASSERT_MSG(aPosition1.sameCol(aPosition2), "test compare sameCol");

	std::cout << "	OK" << std::endl;
}

void TestPosition::testEvaluatePosition(void) const{
	std::cout << "TestPosition - evaluate position";

	Position aPosition1(2, 5);
	Position aPosition2(4, 6);

	int dist = 5;
	BOOST_ASSERT_MSG(aPosition1.evaluateDistance(aPosition2) == dist, "testPosition evaluatePosition");

	std::cout << "	OK" << std::endl;
}

void TestPosition::testDiffs(void) const{
	std::cout << "TestPosition - testDiffs";

	Position aPosition1(2, 5);
	Position aPosition2(4, 6);

	BOOST_ASSERT_MSG(aPosition1.diffLigne(aPosition2) == 2, "testPosition evaluatePosition");
	BOOST_ASSERT_MSG(aPosition1.diffCol(aPosition2) == 1, "testPosition evaluatePosition");

	std::cout << "	OK" << std::endl;
}

void TestPosition::testToStream(void) const{
	std::cout << "TestPosition - toStream";
	Position aPosition(2, 5);


	std::ostream aStream(0);
	std::stringbuf aStr;
	aStream.rdbuf(&aStr);

	aPosition.toStream(aStream);

	BOOST_ASSERT_MSG(aStr.str().compare("2 5") == 0, "testPosition evaluatePosition");

	std::cout << "	OK" << std::endl;
}

} /* namespace datas */
