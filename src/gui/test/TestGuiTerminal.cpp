/*
 * TestGuiTerminal.cpp
 *
 *  Created on: 16 oct. 2016
 *      Author: le_e
 */

#include "TestGuiTerminal.h"
#include "../src/DisplayTerminal.h"
#include "../../game/src/Echiquier.h"

using namespace gui;
using namespace game;


TestGuiTerminal::TestGuiTerminal()
{}

TestGuiTerminal::~TestGuiTerminal()
{}

void TestGuiTerminal::startTests() const{
	testDisplay();
}

void TestGuiTerminal::testDisplay() const{
	DisplayTerminal aDisplayTerminal;
	Echiquier& aEchiquier = game::Echiquier::accessInstance();

	aEchiquier.setBegginingGameWithoutHandicap();

	aDisplayTerminal.displayPositionGameTerminal(aEchiquier);

	aEchiquier.reset();
}

