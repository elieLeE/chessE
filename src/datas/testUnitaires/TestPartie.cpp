/*
 * TestPartie.cpp
 *
 *  Created on: 24 nov. 2016
 *      Author: le_e
 */

#include "TestPartie.h"

#include "../../common/src/UnitTest.h"
#include "../src/Partie.h"

using namespace std;
using namespace datas;
using namespace common;
using namespace datas;

TestPartie::TestPartie()
{}

TestPartie::~TestPartie()
{}

void TestPartie::startTests(void){
	UnitTest<TestPartie> unitT("TestPartie", true);

	unitT.launchMethods();
}
