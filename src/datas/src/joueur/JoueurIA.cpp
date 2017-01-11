/*
 * JoueurIA.cpp
 *
 *  Created on: 20 sept. 2016
 *      Author: le_e
 */

#include "JoueurIA.h"
#include "../../../game/src/Echiquier.h"
#include "../../../game/src/IA.h"

namespace datas {

JoueurIA::JoueurIA(EColor iColor):Joueur(iColor, IA_PlAYER)
{}

JoueurIA::~JoueurIA()
{}

MovePtr JoueurIA::nextMove(){
	const game::Echiquier& aEchiquier = game::Echiquier::getInstance();
	MovePtr aMove;

	do{
		//aMove = game::nextMoveIA(aEchiquier);
	}while(aMove->isValidateMove(aEchiquier));

	return aMove;
}

} /* namespace datas */
