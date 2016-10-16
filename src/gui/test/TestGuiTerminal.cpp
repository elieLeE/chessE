/*
 * TestGuiTerminal.cpp
 *
 *  Created on: 16 oct. 2016
 *      Author: le_e
 */

#include "TestGuiTerminal.h"
#include "../src/DisplayTerminal.h"
#include "../../game/src/EtatGame.h"

using namespace gui;
using namespace game;


TestGuiTerminal::TestGuiTerminal()
{}

TestGuiTerminal::~TestGuiTerminal()
{}

void TestGuiTerminal::startTests(){
	DisplayTerminal aDisplayTerminal;
	EtatGame *aEtatGame = game::EtatGame::accessInstance();

	aEtatGame->setBegginingGameWithoutHandicap();

	aDisplayTerminal.displayPositionGameTerminal(*aEtatGame);
}

