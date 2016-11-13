/*
 * Tour.h
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#ifndef TOUR_H_
#define TOUR_H_

#include "Piece.h"
#include "../Move.h"

namespace datas{

#define NBRE_TOURS 2

class Tour : public Piece{
public:
	Tour(const EColor iColor, Position iPosition);
	virtual ~Tour();

	virtual bool isValideMove(const Move& iMove) const;

	virtual void movePiece(const Position& iPosition);

	virtual bool canAccessCase(const Position& iPosition) const;

	//virtual const std::list <boost::shared_ptr <Move> > getPossibleMoves() const;

	bool getHasAlreadyMoved() const;

private:
	bool _hasAlreadyMoved;
};

std::ostream& operator<<(std::ostream& os, const Tour& iTour);

}

#endif /* TOUR_H_ */
