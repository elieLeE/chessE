/*
 * DisplayTerminal.cpp
 *
 *  Created on: 15 oct. 2016
 *      Author: le_e
 */

#include <iostream>

#include "../../game/src/EtatGame.h"
#include "DisplayTerminal.h"

namespace gui {

DisplayTerminal::DisplayTerminal()
{}

DisplayTerminal::~DisplayTerminal()
{}

void DisplayTerminal::displayPositionGameTerminal(const game::EtatGame& iEtatGame){
	std::cout << "displayPositionGameTerminal NOT YET IMPLEMENTED" << std::endl;
}

/*const Display* DisplayTerminal::getInstance(){
	_display = new DisplayTerminal();
	return _display;
}

Display* DisplayTerminal::accessInstance(){
	_display = new DisplayTerminal();
	return _display;
}*/

/*void DisplayTerminal::displayPositionGame(const game::EtatGame& iEtatGame){
	std::cout << "To Implemeted";
}*/

} /* namespace gui */

