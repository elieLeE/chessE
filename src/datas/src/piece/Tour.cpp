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
#include "../../../game/src/Echiquier.h"

#include "../../../common/src/DisplayType.h"

namespace datas{

Tour::Tour(const EColor iColor, Position iPosition):
								Piece(iColor, iPosition, TOUR_TYPE, TOUR_VALUE),
								_hasAlreadyMoved(false)
{}

Tour::~Tour()
{}

void Tour::movePiece(const 	Position& iPosition){
	Piece::movePiece(iPosition);
	_hasAlreadyMoved = true;
}

bool Tour::isValideMove(const Move& iMove) const{
	return Piece::isValideMove(iMove) &&
			canAccessCase(iMove.getEndPosition());
}

bool Tour::canAccessCase(const Position& iPosition) const{
	bool aBool = false;

	if(iPosition.sameLigne(_position)){
		int aDebut = std::min(iPosition.getX(), _position.getX());
		int aEnd = std::max(iPosition.getX(), _position.getX());
		int aCol = _position.getY();
		const game::Echiquier& aGame = game::Echiquier::getInstance();

		aBool = true;
		for(int i=aDebut+1; aBool && (i<aEnd); ++i){
			aBool = !aGame.getCase(i, aCol).hasPiece();
		}
	}
	else if(iPosition.sameCol(_position)){
		int aDebut = std::min(iPosition.getY(), _position.getY());
		int aEnd = std::max(iPosition.getY(), _position.getY());
		int aLigne = _position.getX();
		const game::Echiquier& aGame = game::Echiquier::getInstance();

		aBool = true;
		for(int j=aDebut+1; aBool && (j<aEnd); ++j){
			aBool = !aGame.getCase(aLigne, j).hasPiece();
		}
	}

	return aBool;
}

bool Tour::hasAlreadyMoved() const{
	return _hasAlreadyMoved;
}

/*const std::list <boost::shared_ptr <Move> > getPossibleMoves() const{
	std::list <boost::shared_ptr <Move> > aList;

	return aList;
}*/

void Tour::toStream(std::ostream& os) const{
	Piece::toStream(os);
	os << "already moved ? " << boolToString(_hasAlreadyMoved) << std::endl;

	//return os;
}

std::ostream& operator<<(std::ostream& os, const Tour& iTour){
	iTour.toStream(os);

	return os;
}

}
