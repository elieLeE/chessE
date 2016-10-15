/*
 * DisplayWindow.cpp
 *
 *  Created on: 15 oct. 2016
 *      Author: le_e
 */

#include "../../game/src/EtatGame.h"
#include "DisplayWindow.h"

namespace gui {

DisplayWindow::DisplayWindow()
{}

DisplayWindow::~DisplayWindow()
{}

void DisplayWindow::displayPositionGameWindow(const game::EtatGame& iEtatGame){
	//cout << "displayPositionGameTerminal NOT YET IMPLEMENTED";
}

/*const Display* DisplayWindow::getInstance(){
	_display = new DisplayWindow();
	return _display;
}

Display* DisplayWindow::accessInstance(){
	_display = new DisplayWindow();
	return _display;
}*/

} /* namespace gui */

