/*
 * DisplayTerminal.cpp
 *
 *  Created on: 15 oct. 2016
 *      Author: le_e
 */

#include <iostream>
#include <sstream>

#include "../../game/src/Echiquier.h"
#include "DisplayTerminal.h"
#include "../../datas/src/typeDefine/Dimension.h"
#include "ColorDisplay.h"

#include "../../datas/src/Move.h"

namespace gui {

DisplayTerminal::DisplayTerminal()
{}

DisplayTerminal::~DisplayTerminal()
{}

void DisplayTerminal::displayPositionGameTerminal(const game::Echiquier& iEchiquier){
	std::cout << iEchiquier << std::endl;
}

std::string DisplayTerminal::getColor(int color){
	std::string aResult("\033[31");
	/*aResult.append(FG_RED);
	+COLOR_SUFFIX);*/
	return aResult;
}

boost::shared_ptr<datas::Move> DisplayTerminal::nextMove() const{
	boost::shared_ptr<datas::Move> aMove(new datas::Move(datas::Position(1, 1), datas::Position(2, 2)));

	return aMove;
}

} /* namespace gui */

