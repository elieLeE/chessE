/*
 * JoueurIA.cpp
 *
 *  Created on: 20 sept. 2016
 *      Author: le_e
 */

#include "JoueurIA.h"
#include "../../game/src/EtatGame.h"
#include "../../game/src/IA.h"

namespace datas {

JoueurIA::JoueurIA(EColor iColor, ETypePlayer iTypePlayer):Joueur(iColor, iTypePlayer)
{}

JoueurIA::~JoueurIA()
{}

MovePtr JoueurIA::nextMove(){
	const game::EtatGame& aEtatGame = game::EtatGame::getInstance();
	MovePtr aMove;

	do{
		//aMove = game::nextMoveIA(aEtatGame);
	}while(aMove->isValidateMove(aEtatGame));

	return aMove;
}

} /* namespace datas */
