/*
 * DisplayWindow.cpp
 *
 *  Created on: 15 oct. 2016
 *      Author: le_e
 */

#include "../../game/src/Echiquier.h"
#include "DisplayWindow.h"

#include "../../datas/src/Move.h"
#include "../../datas/src/Position.h"

namespace gui {

DisplayWindow::DisplayWindow()
{}

DisplayWindow::~DisplayWindow()
{}

void DisplayWindow::displayUpdated(const game::Echiquier& iEchiquier){
	//cout << "displayPositionGameTerminal NOT YET IMPLEMENTED";
}

const boost::shared_ptr<datas::Move> DisplayWindow::nextMove() const{
	boost::shared_ptr<datas::Move> aMove(new datas::Move(datas::Position(1, 1), datas::Position(2, 2)));

	return aMove;
}

} /* namespace gui */

