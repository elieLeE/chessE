/*
 * maic.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include <iostream>

#include "TestPosition.h"

#include <boost/assert.hpp>

using namespace std;
using namespace datas;

int main() {
	cout << "test unitaire datas" << endl;

	TestPosition unitTestPosition;

	unitTestPosition.startTests();

	cout << "OK" << endl;

	//BOOST_ASSERT_MSG(false, "test");

	return 0;
}

