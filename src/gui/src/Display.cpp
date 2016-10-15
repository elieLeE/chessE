/*
 * Display.cpp
 *
 *  Created on: 25 sept. 2016
 *      Author: le_e
 */

#include "Display.h"
#include "../../datas/src/Move.h"
#include "TypeGui.h"
#include "Test.h"

namespace gui{

Display* Display::_display = 0;

#if DISPLAY_WINDOW
Display::Display():_pDisplayWindow(new DisplayWindow())
#else
Display::Display():_pDisplayTerminal(new DisplayTerminal())
#endif
{}

Display::~Display()
{}

void Test::test(){

}

const Display* Display::getInstance(){
	if(!_display){
		_display = new Display();
	}
	return _display;
}

Display* Display::accessInstance(){
	if(!_display){
		_display = new Display();
	}
	return _display;
}

void Display::displayPositionGame(const game::EtatGame& iEtatGame){
#if DISPLAY_WINDOW
	_pDisplayWindow.get()->displayPositionGameWindow(iEtatGame);
#else
	_pDisplayTerminal.get()->displayPositionGameTerminal(iEtatGame);
#endif
}

/*void Display::displayPositionGameTerminal(const game::EtatGame& iEtatGame){
	std::cout << "displayPositionGameTerminal NOT YET IMPLEMENTED";
}*/

datas::MoveCSPtr Display::nextMove(){
	std::cout << "Entrez votre movement" << std::endl;
	datas::Position aPositionStart(4, 2);
	datas::Position aPositionEnd(4, 4);

	datas::MoveCSPtr aMove(new datas::Move(aPositionStart, aPositionEnd));

	return aMove;
}

} /* namespace gui*/
