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

	Tour(const EColor iColor, Position iPosition, const int iNumTour);
	virtual ~Tour();

	virtual bool isValideMove(const game::EtatGame& iEtatGame, const Move& iMove) const;

	bool canAccessToCase(const Position& iPosition) const;

	//virtual const std::list <boost::shared_ptr <Move> > getPossibleMoves() const;

	int getNumTour(void) const;

private:
	const int _numTour;
};

}

#endif /* TOUR_H_ */
