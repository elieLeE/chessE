/*
 * IA.h
 *
 *  Created on: 25 sept. 2016
 *      Author: le_e
 */

#ifndef IA_H_
#define IA_H_

#include "EtatGame.h"
#include "../../datas/src/Move.h"

namespace game{

	static datas::MovePtr nextMoveIA(EtatGame* iEtatGame);

	static void addMove(EtatGame* iEtatGame);
	static void removeMove(EtatGame* iEtatGame);

} /* namespace game*/
#endif /* IA_H_ */
