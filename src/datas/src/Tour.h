/*
 * Tour.h
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#ifndef TOUR_H_
#define TOUR_H_

#include "Piece.h"
#include "Move.h"

namespace datas{

class Tour : public Piece{
public:
	Tour(EColor iColor, Position iPosition);
	virtual ~Tour();

	virtual bool isValidatedMove(const game::EtatGame& iEtatGame, const Move iMove) const;
};

}

#endif /* TOUR_H_ */
