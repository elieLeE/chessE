/*
 * TestOptionsGame.cpp
 *
 *  Created on: 25 nov. 2016
 *      Author: le_e
 */

#include "TestOptionsGame.h"

#include "../../common/src/UnitTest.h"
#include "../src/OptionsGame.h"

using namespace std;
using namespace datas;
using namespace common;
using namespace datas;

TestOptionsGame::TestOptionsGame()
{}

TestOptionsGame::~TestOptionsGame()
{}

void TestOptionsGame::startTests(void){
	UnitTest<TestOptionsGame> unitT("TestOptionsGame", true);

	unitT.launchMethods();
}
