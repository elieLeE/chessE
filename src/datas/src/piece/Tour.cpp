/*
 * Tour.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Tour.h"
#include "../typeDefine/TypePiece.h"
#include "../typeDefine/PieceValue.h"
#include "../Position.h"

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

bool Tour::isValideMove(const game::EtatGame& iEtatGame, const Move& iMove) const{
	return true;
}

bool Tour::canAccessToCase(const Position& iPosition) const{
	bool aBool = false;

	if(iPosition.sameLigne(_position)){

	}

	return aBool;
}

/*const std::list <boost::shared_ptr <Move> > getPossibleMoves() const{
	std::list <boost::shared_ptr <Move> > aList;

	return aList;
}*/

}
