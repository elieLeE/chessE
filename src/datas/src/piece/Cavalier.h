/*
 * Cavalier.h
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#ifndef CAVALIER_H_
#define CAVALIER_H_

#include "Piece.h"
#include "../Move.h"

namespace datas{

class Cavalier : public Piece {
public:
	Cavalier(const EColor iColor, Position iPosition);
	virtual ~Cavalier();

	virtual bool isValideMove(const Move& iMove) const;
};

}

#endif /* CAVALIER_H_ */
