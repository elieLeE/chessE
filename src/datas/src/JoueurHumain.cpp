/*
 * JoueurHumain.cpp
 *
 *  Created on: 20 sept. 2016
 *      Author: le_e
 */

#include "JoueurHumain.h"
#include "../../game/src/EtatGame.h"
#include "../../gui/src/Display.h"

namespace datas {

JoueurHumain::JoueurHumain(EColor iColor, ETypePlayer iTypePlayer):Joueur(iColor, iTypePlayer)
{}

JoueurHumain::~JoueurHumain()
{}

MoveCSPtr JoueurHumain::nextMove(){
	MoveCSPtr aMove;

	do{
		aMove = gui::Display::nextMove();
	}while(!isValidatedMove(*(game::EtatGame::getInstance()), *aMove));

	return aMove;
}

} /* namespace datas */
