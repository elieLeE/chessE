/*
 * main.cpp
 *
 *  Created on: 6 nov. 2016
 *      Author: le_e
 */

#include <iostream>

#include "TestUnitTest.h"

using namespace std;

int main() {
	cout << "test unitaire common" << endl << endl;

	common::TestUnitTest::startTests();

	cout << "all OK" << endl;

	return 0;
}



