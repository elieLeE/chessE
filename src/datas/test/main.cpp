/*
 * maic.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include <iostream>
#include <boost/assert.hpp>

#include "TestPosition.h"
#include "testPiece/TestRoi.h"

using namespace std;
using namespace datas;

int main() {
	cout << "test unitaire datas" << endl;

	TestPosition::startTests();
	TestRoi::startTests();

	cout << endl << "all OK" << endl;

	//BOOST_ASSERT_MSG(false, "test");

	return 0;
}

