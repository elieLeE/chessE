/*
 * TestDame.cpp
 *
 *  Created on: 29 oct. 2016
 *      Author: le_e
 */
#include <iostream>

#include "TestDame.h"

using namespace std;
using namespace datas;

TestDame::TestDame()
{}

TestDame::~TestDame()
{}

void TestDame::startTests(void){
	TestDame aTestDame;

	aTestDame.testIsValideMove();

	cout << endl;
}

void TestDame::testIsValideMove(void) const{
	cout << "TestDame - testIsValideMove";

	cout << "	TO IMPLMENT" << endl;
}
