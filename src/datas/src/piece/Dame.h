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

	virtual bool isValideMove(const Move& iMove) const;

	bool canAccessToCase(const Position& iPosition) const;
};

}

#endif /* DAME_H_ */
