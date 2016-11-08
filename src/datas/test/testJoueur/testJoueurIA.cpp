/*
 * testJoueurIA.cpp
 *
 *  Created on: 8 nov. 2016
 *      Author: le_e
 */

#include "testJoueurIA.h"
#include "../../../common/src/UnitTest.h"

using namespace datas;
using namespace common;

testJoueurIA::testJoueurIA()
{}

testJoueurIA::~testJoueurIA()
{}

void testJoueurIA::startTests(){
	UnitTest<testJoueurIA> unitT("TestJoueurHumain");

	unitT.launchMethods();
}
