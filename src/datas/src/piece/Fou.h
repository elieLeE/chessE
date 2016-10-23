/*
 * Fou.h
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#ifndef FOU_H_
#define FOU_H_

#include "Piece.h"
#include "../Move.h"

namespace datas{

class Fou : public Piece{
public:
	Fou(const EColor iColor, Position iPosition);
	virtual ~Fou();

	virtual bool isValideMove(const game::EtatGame& iEtatGame, const Move& iMove) const;

	bool canAccessToCase(const Position& iPosition) const;
};

}

#endif /* FOU_H_ */
