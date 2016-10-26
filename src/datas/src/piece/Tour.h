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
	typedef enum ENumTour{
		TOUR_1,
		TOUR_2
	}ENumTour;

	Tour(const EColor iColor, Position iPosition);
	virtual ~Tour();

	virtual bool isValideMove(const Move& iMove) const;

	virtual void movePiece(const Position& iPosition);

	bool canAccessToCase(const Position& iPosition) const;

	//virtual const std::list <boost::shared_ptr <Move> > getPossibleMoves() const;

	bool getHasAlreadyMoved() const;

private:
	bool _hasAlreadyMoved;
};

}

#endif /* TOUR_H_ */
