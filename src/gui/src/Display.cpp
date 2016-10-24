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

Display* Display::_display = 0;

#if DISPLAY_WINDOW
Display::Display():
		_pDisplayWindow(new DisplayWindow())
#else
Display::Display():
		_pDisplayTerminal(new DisplayTerminal())
#endif
{}

Display::~Display()
{}

const Display* Display::getInstance(){
	if(!_display){
		_display = new Display();
		/*if(DISPLAY_WINDOW == TERMINAL_GUI){
			//datas::Tour* aTour = dynamic_cast<datas::Tour*>(aPieceMove.get());
			_display = new DisplayTerminal();
		}*/
	}
	return _display;
}

Display* Display::accessInstance(){
	if(!_display){
		_display = new Display();
	}
	return _display;
}

void Display::displayPositionGame(const game::Echiquier& iEchiquier){
/*#if DISPLAY_WINDOW
	_pDisplayWindow.get()->displayPositionGameWindow(iEchiquier);
#else
	_pDisplayTerminal.get()->displayPositionGameTerminal(iEchiquier);
#endif*/
	std::cout << "rate" << std::endl;
}

datas::MoveCSPtr Display::nextMove(){
	std::cout << "Entrez votre movement" << std::endl;
	datas::Position aPositionStart(4, 2);
	datas::Position aPositionEnd(4, 4);

	datas::MoveCSPtr aMove(new datas::Move(aPositionStart, aPositionEnd));

	return aMove;
}

} /* namespace gui*/
