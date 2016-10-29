/*
 * maic.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include <iostream>
#include <boost/assert.hpp>

#include "TestPosition.h"

#include "testPiece/TestCavalier.h"
#include "testPiece/TestDame.h"
#include "testPiece/TestFou.h"
#include "testPiece/TestPion.h"
#include "testPiece/TestRoi.h"
#include "testPiece/TestTour.h"

using namespace std;
using namespace datas;

int main() {
	cout << "test unitaire datas" << endl;

	TestPosition::startTests();

	TestCavalier::startTests();
	TestDame::startTests();
	TestFou::startTests();
	TestFou::startTests();
	TestRoi::startTests();
	TestTour::startTests();

	cout << endl << "all OK" << endl;

	return 0;
}

