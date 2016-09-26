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

MoveCSPtr JoueurIA::nextMove(){
	const game::EtatGame* aEtatGame = game::EtatGame::getInstance();
	MoveCSPtr aMove;

	do{
		//aMove = game::nextMoveIA(aEtatGame);
	}while(isValidatedMove(*aEtatGame, *aMove));

	return aMove;
}

} /* namespace datas */
