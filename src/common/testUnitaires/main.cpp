/*
 * main.cpp
 *
 *  Created on: 6 nov. 2016
 *      Author: le_e
 */

#include <iostream>

#include "TestDisplayType.h"
#include "TestLogs.h"
#include "TestUnitTest.h"

using namespace std;

int main() {
	cout << "test unitaire common" << endl << endl;

	common::TestUnitTest::startTests();

	common::TestDisplayType::startTests();

	common::TestLogs::startTests();

	cout << endl << "all OK" << endl << endl;

	return 0;
}
