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
	MoveCSPtr aMove;

	do{
		aMove = gui::Display::nextMove();
	}while(aMove->isValide((game::Echiquier::getInstance())));

	return aMove;
}

} /* namespace datas */
