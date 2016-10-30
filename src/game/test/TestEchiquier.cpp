/*
 * TestEchiquier.cpp
 *
 *  Created on: 30 oct. 2016
 *      Author: le_e
 */

#include "TestEchiquier.h"
#include "../src/Echiquier.h"
#include <iostream>

using namespace std;
using namespace game;

TestEchiquier::TestEchiquier()
{}

TestEchiquier::~TestEchiquier()
{}

void TestEchiquier::startTest(){
	TestEchiquier aTestEchiquier;

	aTestEchiquier.testMovePiece();

	cout << endl;
}

void TestEchiquier::testMovePiece(void) const{
	cout << "TestTour - testIsValideMove";

	cout << "	TO IMPLEMENT" << std::endl;
}
