/*
 * Roi.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */
#include <cmath>
#include <cstddef>

#include "Roi.h"
#include "../typeDefine/TypePiece.h"
#include "../typeDefine/PieceValue.h"
#include "../../../game/src/Echiquier.h"
#include "../../../common/src/DisplayType.h"
#include "Tour.h"

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
	bool aBool = Piece::isValideMove(iMove);

	if(aBool){
		ETypeMove aTypeMove = estMoveOKTheorique(iMove);
		aBool = estMoveOKPratique(iMove, aTypeMove);
	}

	return aBool;
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

bool Roi::estRockTheorique(const Move& iMove, const ETypeMove iTypeMove) const{
	bool aBool = false;

	if(iMove.getStartPosition().sameLigne(iMove.getEndPosition()) &&
			(iMove.evaluateDistance() == distanceMove(iTypeMove)) &&
			(!_hasAlreadyMoved)){
		int y = _position.getY();
		int x = (iMove.getEndPosition().getX()==7?8:iMove.getEndPosition().getX()==3?1:-1);

		if(((x == 8) && (iTypeMove == PETIT_ROCK)) || ((x == 1) && (iTypeMove == GRAND_ROCK))){
			const PiecePtr& aPiece = game::Echiquier::getInstance().getCase(x, y).getPiece();

			if(aPiece && (aPiece->getTypePiece()==TOUR_TYPE)){
				Tour* aTour = dynamic_cast<Tour*>(aPiece.get());
				if((aTour != nullptr) && !aTour->hasAlreadyMoved()){
					aBool = true;
				}
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
		aBool = estRockPratique(PETIT_ROCK);
		break;

	case GRAND_ROCK:
		aBool = estRockPratique(GRAND_ROCK);
		break;

	case INCORRECT_MOVE:
		break;

	default:
		break;
	}

	return aBool;
}

bool Roi::estNormalMovePratique(const Move& iMove) const{
	return !canBeKilledAtPosition(iMove.getEndPosition());
}

bool Roi::estRockPratique(const ETypeMove iTypeMove) const{
	bool aBool = true;

	//not take initial position for end or deb because has obviously piece...
	int y = _position.getY();
	int deb = (iTypeMove==PETIT_ROCK?_position.getX()+1:POS_X_END_GRAND_ROCK);
	int end = (iTypeMove==PETIT_ROCK?POS_X_END_PETIT_ROCK:_position.getX()-1);

	Position aPosition(deb, y);

	//impossible de rocket quand en situation d'echec mais peux bouger le roi avec un mouvement normal
	aBool = !canBeKilled();

	for(int i=deb; (i<=end) && aBool; i++){
		aBool = !game::Echiquier::getInstance().getCase(i, y).hasPiece();
	}

	for(int i=deb; aBool && (i<=end); i++){
		aPosition.setX(i);
		aBool = !canBeKilledAtPosition(aPosition);
	}

	return aBool;
}

bool Roi::canBeKilled() const{
	return canBeKilledAtPosition(_position);
}

bool Roi::canBeKilledAtPosition(const Position& iPosition) const{
	bool aBool = false;
	const game::Echiquier& aEchiquier = game::Echiquier::getInstance();

	for(auto it = aEchiquier.getPlateau().begin(); !aBool && (it != aEchiquier.getPlateau().end()) ; ++it){
		for(auto it2 = it->begin(); !aBool && (it2 != it->end()); ++it2){
			if(it2->hasPiece() && (it2->getPiece()->getColor() != _color)){
				aBool = it2->getPiece()->canKillCasePiece(iPosition);
			}
		}
	}

	return aBool;
}

bool Roi::canAccessCase(const Position& iPosition) const{
	return (_position.evaluateDistance(iPosition) <= distanceMove(SIMPLE_MOVE_ROI_MAX));
}

/*const std::list <boost::shared_ptr <Move> > Roi::getPossibleMoves() const {
	std::list<boost::shared_ptr<Move> >aList;

	return aList;
}*/

bool Roi::hasAlreadyMoved(void) const{
	return _hasAlreadyMoved;
}

std::ostream& operator<<(std::ostream& os, const Roi& iRoi){
	os << *((Piece*)&iRoi) <<
			"already moved ? " << boolToString(iRoi.hasAlreadyMoved()) << std::endl;

	return os;
}

}
