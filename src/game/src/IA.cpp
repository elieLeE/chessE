/*
 * IA.cpp
 *
 *  Created on: 25 sept. 2016
 *      Author: le_e
 */

#include "IA.h"
#include <boost/shared_ptr.hpp>

namespace game{

//algorithme => minmax en attendant mieux...!
static datas::MovePtr nextMoveIA(EtatGame* iEtatGame){
	datas::Position aPositionStart(4, 2);
	datas::Position aPositionEnd(4, 4);

	//datas::MoveCSPtr aMove = boost::shared_ptr<new datas::Move(aPositionStart, aPositionEnd);

	datas::MovePtr aMove(new datas::Move(aPositionStart, aPositionEnd));

	return aMove;
}

/*
 * call newMove de Joueur qui appelle nextMove !
 * recupere le move et l'ajoute/l'effectue
 * retourne le move associe ??
 */
void addMove(EtatGame* iEtatGame){

}

void removeMove(EtatGame* iEtatGame){

}

} /* namespace game*/
