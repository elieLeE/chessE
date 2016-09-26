/*
 * Display.cpp
 *
 *  Created on: 25 sept. 2016
 *      Author: le_e
 */

#include "Display.h"
#include "../../datas/src/Move.h"

namespace gui{

Display* Display::_display = 0;

Display::Display()
{}

Display::~Display()
{}

const Display* Display::getInstance(){
	_display = new Display();
	return _display;
}

Display* Display::accessInstance(){
	_display = new Display();
	return _display;
}

datas::MoveCSPtr Display::nextMove(){
	std::cout << "Entrez votre movement" << std::endl;
	datas::Position aPositionStart(4, 2);
	datas::Position aPositionEnd(4, 4);

	datas::MoveCSPtr aMove(new datas::Move(aPositionStart, aPositionEnd));

	return aMove;
}

} /* namespace gui*/
