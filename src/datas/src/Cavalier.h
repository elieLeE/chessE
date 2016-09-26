/*
 * Cavalier.h
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#ifndef CAVALIER_H_
#define CAVALIER_H_

#include "Piece.h"
#include "Move.h"

namespace datas{

class Cavalier : public Piece {
public:
	Cavalier(EColor iColor, Position iPosition);
	virtual ~Cavalier();

	virtual bool isValidatedMove(const game::EtatGame& iEtatGame, const Move& iMove) const;
};

}

#endif /* CAVALIER_H_ */
