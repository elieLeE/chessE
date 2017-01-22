/*
 * Display.cpp
 *
 *  Created on: 25 sept. 2016
 *      Author: le_e
 */

#include "Display.h"
#include "../../datas/src/Move.h"
#include "TypeGui.h"

namespace gui{

Display Display::_display = Display();
ETypeGui Display::_typeGui = TERMINAL_GUI;

Display::Display():
		_pDisplayWindow(new DisplayWindow()),
		_pDisplayTerminal(new DisplayTerminal())
{}

Display::~Display()
{}

const Display& Display::getInstance(){
	return _display;
}

Display& Display::accessInstance(){
	return _display;
}

void Display::displayUpdated(const game::Echiquier& iEchiquier){
	if(_typeGui == TERMINAL_GUI){
		_pDisplayTerminal->displayPositionGameTerminal(iEchiquier);
	}
	else {
		_pDisplayWindow->displayUpdated(iEchiquier);
	}
}

boost::shared_ptr<datas::Move>  Display::nextMove() const{
	if(_typeGui == TERMINAL_GUI){
		return _pDisplayTerminal->nextMove();
	}
	else {
		return _pDisplayWindow->nextMove();
	}
}

void Display::setTypeGui(const ETypeGui iTypeGui){
	_typeGui = iTypeGui;
}

} /* namespace gui*/
