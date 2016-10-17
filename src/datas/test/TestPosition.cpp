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

void TestPosition::startTests(){
	std::cout << "testPosition";
	for(int i=0; i<NBRE_LIGNE; i++){
		for(int j=0; j<NBRE_LIGNE; j++){
			Position aPosition1(i, j);
			Position aPosition2(i, j);
			BOOST_ASSERT_MSG(aPosition1==aPosition2, "test Position");
		}
	}
	std::cout << "	OK" << std::endl;
}

} /* namespace datas */
