/*
 * TestGuiTerminal.cpp
 *
 *  Created on: 16 oct. 2016
 *      Author: le_e
 */

#include "TestGuiTerminal.h"
#include "../src/DisplayTerminal.h"
#include "../../game/src/Echiquier.h"
#include "../../common/src/UnitTest.h"

using namespace gui;
using namespace game;
using namespace common;

TestGuiTerminal::TestGuiTerminal()
{}

TestGuiTerminal::~TestGuiTerminal()
{}

void TestGuiTerminal::startTests() const{
	UnitTest<TestGuiTerminal> unitT("TestGuiTerminal");

	unitT.addMethod("testDisplay", &gui::TestGuiTerminal::testDisplay);

	unitT.launchMethods();
}

void TestGuiTerminal::testDisplay() const{
	DisplayTerminal aDisplayTerminal;
	Echiquier& aEchiquier = game::Echiquier::accessInstance();

	aEchiquier.setBegginingGameWithoutHandicap();

	aDisplayTerminal.displayPositionGameTerminal(aEchiquier);

	aEchiquier.reset();


}

