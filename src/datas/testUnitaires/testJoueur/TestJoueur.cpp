/*
 * TestJoueur.cpp
 *
 *  Created on: 8 nov. 2016
 *      Author: le_e
 */

#include "../testJoueur/TestJoueur.h"

#include "../../../common/src/UnitTest.h"

using namespace datas;
using namespace common;

TestJoueur::TestJoueur()
{}

TestJoueur::~TestJoueur()
{}

void TestJoueur::startTests(){
	UnitTest<TestJoueur> unitT("TestJoueur");

	unitT.launchMethods();
}
