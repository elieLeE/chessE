/*
 * TestPosition.cpp
 *
 *  Created on: 25 sept. 2016
 *      Author: le_e
 */

#include "TestPosition.h"
#include "../src/Dimension.h"
#include "boost/assert.hpp"
#include "../src/Position.h"

namespace datas {

TestPosition::TestPosition()
{}

TestPosition::~TestPosition()
{}

void TestPosition::startTests() const{
	testComparePosition();
}

void TestPosition::testComparePosition() const {
	std::cout << "testPosition - compare position";

	Position aPosition1(2, 5);
	Position aPosition2(2, 5);
	BOOST_ASSERT_MSG(aPosition1==aPosition2, "test compare position egales");

	aPosition2.setY(6);
	BOOST_ASSERT_MSG(aPosition1!=aPosition2, "test compare position differentes");

	std::cout << "	OK" << std::endl;
}

} /* namespace datas */
