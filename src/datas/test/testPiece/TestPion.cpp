/*
 * TestPion.cpp
 *
 *  Created on: 29 oct. 2016
 *      Author: le_e
 */
#include <iostream>

#include "TestPion.h"

using namespace std;
using namespace datas;

TestPion::TestPion()
{}

TestPion::~TestPion()
{}

void TestPion::startTests(void){
	TestPion aTestPion;

	aTestPion.testIsValideMove();

	cout << endl;
}

void TestPion::testIsValideMove(void) const{
	cout << "TestPion - testIsValideMove";

	cout << "	TO IMPLMENT" << endl;
}
