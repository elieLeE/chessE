/*
 * Roi.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */
#include <cmath>

#include "Roi.h"
#include "../typeDefine/TypePiece.h"
#include "../typeDefine/PieceValue.h"
#include "../../../game/src/Echiquier.h"
#include "Tour.h"
#include "Fou.h"

namespace datas{

Roi::Roi(const EColor iColor, Position iPosition):
									Piece(iColor, iPosition, ROI_TYPE, ROI_VALUE),
									_hasAlreadyMoved(false)
{}

Roi::~Roi()
{}

void Roi::movePiece(const Position& iPosition){
	Piece::movePiece(iPosition);
	_hasAlreadyMoved = true;
}

bool Roi::isValideMove(const Move& iMove) const{
	ETypeMove aTypeMove = estMoveOKTheorique(iMove);
	return estMoveOKPratique(iMove, aTypeMove);
}

//verifie que le movement est possible pour un Roi dans 1 cas general.
//ne verifie pas qu'il puisse mourir en jouant ainsi
ETypeMove Roi::estMoveOKTheorique(const Move& iMove) const{
	ETypeMove aTypeMove = INCORRECT_MOVE;

	aTypeMove=estNormalMoveTheorique(iMove)?NORMAL_MOVE:INCORRECT_MOVE;
	aTypeMove=(aTypeMove!=INCORRECT_MOVE)?aTypeMove:estPetitRockTheorique(iMove)?PETIT_ROCK:INCORRECT_MOVE;
	aTypeMove=(aTypeMove!=INCORRECT_MOVE)?aTypeMove:estGrandRockTheorique(iMove)?GRAND_ROCK:INCORRECT_MOVE;

	return aTypeMove;
}

bool Roi::estNormalMoveTheorique(const Move& iMove) const{
	return canAccessCase(iMove.getEndPosition());
}

bool Roi::estPetitRockTheorique(const Move& iMove) const{
	return estRockTheorique(iMove, PETIT_ROCK);
}

bool Roi::estGrandRockTheorique(const Move& iMove) const{
	return estRockTheorique(iMove, GRAND_ROCK);
}

bool Roi::estRockTheorique(const Move& iMove, ETypeMove iTypeMove) const{
	bool aBool = false;
	int diffExpected = (iTypeMove==PETIT_ROCK?2:3);

	if(iMove.getStartPosition().sameLigne(iMove.getEndPosition()) &&
			(iMove.getStartPosition().diffCol(iMove.getEndPosition()) == diffExpected) &&
			(!_hasAlreadyMoved)){
		int x = _position.getX();
		int y = (iTypeMove==PETIT_ROCK?(x==0?7:0):(x==0?0:7));
		const PiecePtr aPiece = game::Echiquier::getInstance().getCase(x, y).getPiece();

		if(aPiece && (aPiece->getTypePiece()==TOUR_TYPE)){
			const Tour* aTour = dynamic_cast<const Tour*>(aPiece.get());
			if(!aTour->getHasAlreadyMoved()){
				aBool = true;
			}
		}
	}

	return aBool;
}

//verifie que le Roi ne peux pas etre pris au coup suivant => validation pratique
bool Roi::estMoveOKPratique(const Move& iMove, const ETypeMove iTypeMove) const{
	bool aBool = false;

	switch(iTypeMove){
	case NORMAL_MOVE:
		aBool = estNormalMovePratique(iMove);
		break;

	case PETIT_ROCK:
		aBool = estRockPratique(iMove, PETIT_ROCK);
		break;

	case GRAND_ROCK:
		aBool = estRockPratique(iMove, GRAND_ROCK);
		break;

	case PRISE_EN_PASSANT:
	case INCORRECT_MOVE:
		break;
	}

	return aBool;
}

bool Roi::estNormalMovePratique(const Move& iMove) const{
	return canBeKilled(iMove.getEndPosition());
}

bool Roi::estRockPratique(const Move& iMove, ETypeMove iTypeMove) const{
	bool aBool = true;

	int x = _position.getX();
	int y = (iTypeMove==PETIT_ROCK?(x==0?6:1):(x==0?1:6));
	int deb = std::min(y, _position.getY());
	int end = std::max(y, _position.getY());
	Position aPosition(x, end);

	for(int i=deb; (i<=end) && aBool; i++){
		aBool = aBool && !game::Echiquier::getInstance().getCase(x, i).hasPiece();
	}

	for(int i=deb; aBool && (i<=end); i++){
		aPosition.setY(i);
		aBool = aBool && !canBeKilled(aPosition);
	}

	return false;
}

bool Roi::canBeKilled(const Position& iPosition) const{
	bool aBool = true;
	const game::Echiquier& aEchiquier = game::Echiquier::getInstance();

	for( auto it = aEchiquier.getAllPiecesJ1().begin(); aBool && (it != aEchiquier.getAllPiecesJ1().end()) ; ++it ){
		if(it->get()->isAlive()){
			aBool = aBool && it->get()->canAccessCase(iPosition);
		}
	}

	return aBool;
}

//TODO => a ameliorer ==> verifier piece couleur differente et pion dans le bon sens
bool Roi::pionPeuxTuerLeRoi(const Position& iPositionFinaleMove, const Position& iPositionPion) const{
	return (iPositionFinaleMove.evaluateDistance(iPositionPion) == 2);
}

bool Roi::canAccessCase(const Position& iPosition) const{
	return (_position.evaluateDistance(iPosition) < 2);
}

const std::list <boost::shared_ptr <Move> > Roi::getPossibleMoves() const {
	std::list<boost::shared_ptr<Move> >aList;

	return aList;
}

}
