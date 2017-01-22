/*
 * JoueurHumain.cpp
 *
 *  Created on: 20 sept. 2016
 *      Author: le_e
 */

#include "JoueurHumain.h"
#include "../../../game/src/Echiquier.h"
#include "../../../gui/src/Display.h"

namespace datas {

JoueurHumain::JoueurHumain(EColor iColor):Joueur(iColor, HUMAN_PLAYER)
{}

JoueurHumain::~JoueurHumain()
{}

MovePtr JoueurHumain::nextMove(){
	const game::Echiquier& aEchiquier = game::Echiquier::getInstance();
	const gui::Display& aDisplay = gui::Display::getInstance();
	boost::shared_ptr<datas::Move> aMove;

	do{
		aMove = aDisplay.nextMove();
	}while(aMove->isValid(aEchiquier));

	return aMove;
}

} /* namespace datas */
