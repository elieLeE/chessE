/*
 * Dame.h
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#ifndef DAME_H_
#define DAME_H_

#include "Piece.h"
#include "../Move.h"

namespace datas{

class Dame : public Piece{
public:
	Dame(const EColor iColor, Position iPosition);
	virtual ~Dame();

	virtual bool isValidateMove(const game::EtatGame& iEtatGame, const Move& iMove) const;
};

}

#endif /* DAME_H_ */
