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
static datas::MoveCSPtr nextMoveIA(EtatGame* iEtatGame){
	datas::Position aPositionStart(4, 2);
	datas::Position aPositionEnd(4, 4);

	//datas::MoveCSPtr aMove = boost::shared_ptr<new datas::Move(aPositionStart, aPositionEnd);

	boost::shared_ptr<datas::Move> aMove(new datas::Move(aPositionStart, aPositionEnd));

	return aMove;
}

} /* namespace game*/
