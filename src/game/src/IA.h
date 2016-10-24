/*
 * IA.h
 *
 *  Created on: 25 sept. 2016
 *      Author: le_e
 */

#ifndef IA_H_
#define IA_H_

#include "Echiquier.h"
#include "../../datas/src/Move.h"

namespace game{

	static datas::MovePtr nextMoveIA(Echiquier* iEchiquier);

	static void addMove(Echiquier* iEchiquier);
	static void removeMove(Echiquier* iEchiquier);

} /* namespace game*/
#endif /* IA_H_ */
