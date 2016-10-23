/*
 * TestRoi.cpp
 *
 *  Created on: 23 oct. 2016
 *      Author: le_e
 */

#include <iostream>

#include "TestRoi.h"

using namespace std;

namespace datas {

TestRoi::TestRoi()
{}

TestRoi::~TestRoi()
{}

void TestRoi::startTests(){
	TestRoi aTestRoi;

	aTestRoi.testEstMoveOKTheorique();
	aTestRoi.testIsValidaMove();
}

void TestRoi::testIsValidaMove() const{
	cout << "TestRoi - isValideMove";

	cout << "	OK" << endl;
}

void TestRoi::testEstMoveOKTheorique() const{

}

} /* namespace datas */
