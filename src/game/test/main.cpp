/*
 * main.cpp
 *
 *  Created on: 28 sept. 2016
 *      Author: le_e
 */

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <memory>

#include "TestEchiquier.h"

using namespace std;
using namespace game;

int main() {
	cout << "test unitaire game" << endl;

	TestEchiquier::startTest();

	cout << endl << "all OK" << endl;

	return 0;
}




