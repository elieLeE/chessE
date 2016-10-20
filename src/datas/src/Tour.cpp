/*
 * Tour.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Tour.h"
#include "TypePiece.h"
#include "PieceValue.h"

namespace datas{

Tour::Tour(const EColor iColor, Position iPosition, const int iNumTour):
		Piece(iColor, iPosition, TOUR_TYPE, TOUR_VALUE),
		_numTour(iNumTour)
{}

Tour::~Tour()
{}

int Tour::getNumTour(void) const{
	return _numTour;
}

bool Tour::isValidateMove(const game::EtatGame& iEtatGame, const Move& iMove) const{
	return true;
}

/*const std::list <boost::shared_ptr <Move> > getPossibleMoves() const{
	std::list <boost::shared_ptr <Move> > aList;

	return aList;
}*/

}
