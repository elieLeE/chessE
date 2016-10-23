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
#include <cmath>
#include "../../../game/src/EtatGame.h"

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

bool Tour::isValideMove(const Move& iMove) const{
	return true;
}

bool Tour::canAccessToCase(const Position& iPosition) const{
	bool aBool = true;

	if(iPosition.sameLigne(_position)){
		int aDebut = std::min(iPosition.getY(), _position.getY());
		int aEnd = std::max(iPosition.getY(), _position.getY());
		int aLigne = _position.getX();
		const game::EtatGame& aGame = game::EtatGame::getInstance();

		for(int i=aDebut+1; i<aEnd; i++){
			if(aGame.getCase(aLigne, i).hasPiece()){
				aBool = false;
				break;
			}
		}
	}
	else if(iPosition.sameCol(_position)){
		int aDebut = std::min(iPosition.getX(), _position.getX());
		int aEnd = std::max(iPosition.getX(), _position.getX());
		int aCol = _position.getY();
		const game::EtatGame& aGame = game::EtatGame::getInstance();

		for(int i=aDebut+1; i<aEnd; i++){
			if(aGame.getCase(i, aCol).hasPiece()){
				aBool = false;
				break;
			}
		}
	}

	return aBool;
}

/*const std::list <boost::shared_ptr <Move> > getPossibleMoves() const{
	std::list <boost::shared_ptr <Move> > aList;

	return aList;
}*/

}
