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

bool Roi::isValideMove(const Move& iMove) const{
	return (estMoveOKTheorique(iMove) &&
			estMoveOKPratique(iMove));
}

void Roi::movePiece(const Position& iPosition){
	Piece::movePiece(iPosition);
	_hasAlreadyMoved = true;
}

//verifie que le movement est possible pour un Roi dans 1 cas general.
//ne verifie pas qu'il puisse mourir en jouant ainsi
bool Roi::estMoveOKTheorique(const Move& iMove) const{
	return estNormalMove(iMove) ||
			estPetitRock(iMove) ||
			estGrandRock(iMove);
}

bool Roi::estNormalMove(const Move& iMove) const{
	return (iMove.evaluateDistance() < 4);
}

bool Roi::estPetitRock(const Move& iMove) const{
	return estRock(iMove, PETIT_ROCK);
}

bool Roi::estGrandRock(const Move& iMove) const{
	return estRock(iMove, GRAND_ROCK);
}

bool Roi::estRock(const Move& iMove, ETypeMove iTypeMove) const{
	bool aBool = false;
	int diffExpected = (iTypeMove==PETIT_ROCK?3:4);

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
bool Roi::estMoveOKPratique(const Move& iMove) const{
	bool aBool = true;
	Position aPositionFinale = iMove.getEndPosition();
	const game::Echiquier& aEchiquier = game::Echiquier::getInstance();

	for( auto it = aEchiquier.getAllPiecesJ1().begin(); it != aEchiquier.getAllPiecesJ1().end(); ++it ){
		switch(it->get()->getTypePiece()){
		if(it->get()->isAlive()){
		case PION_TYPE:
			aBool = !pionPeuxTuerLeRoi(aPositionFinale, it->get()->getPosition());
			break;

		case CAVALIER_TYPE:
			aBool = !cavalierPeuxTuerLeRoi(aPositionFinale, it->get()->getPosition());
			break;

		case FOU_TYPE:
			aBool = !fouPeuxTuerLeRoi(aPositionFinale, it->get()->getPosition());
			break;

		case TOUR_TYPE:
			aBool = !tourPeuxTuerLeRoi(aPositionFinale, it->get()->getPosition());
			break;

		case DAME_TYPE:
			aBool = !damePeuxTuerLeRoi(aPositionFinale, it->get()->getPosition());
			break;

		case ROI_TYPE:
			aBool = !secondRoiColle(aPositionFinale, it->get()->getPosition());
			break;

		case NO_TYPE:
			break;
		}
		if(!aBool){
			break;
		}
		}
	}
	return aBool;
}

//TODO => a ameliorer ==> verifier piece couleur differente et pion dans le bon sens
bool Roi::pionPeuxTuerLeRoi(const Position& iPositionFinaleMove, const Position& iPositionPion) const{
	return (iPositionFinaleMove.evaluateDistance(iPositionPion) == 2);
}

bool Roi::cavalierPeuxTuerLeRoi(const Position& iPositionFinaleMove, const Position& iPositionCavalier) const{
	return (iPositionFinaleMove.evaluateDistance(iPositionCavalier) == 5);
}

bool Roi::fouPeuxTuerLeRoi(const Position& iPositionFinaleMove, const Position& iPositionFou) const{
	const Fou *aFou = dynamic_cast<const datas::Fou*>(game::Echiquier::getInstance().getCase(iPositionFou).getPiece().get());
	return aFou->canAccessToCase(iPositionFinaleMove);
}

bool Roi::tourPeuxTuerLeRoi(const Position& iPositionFinaleMove, const Position& iPositionTour) const{
	const Tour *aTour = dynamic_cast<const datas::Tour*>(game::Echiquier::getInstance().getCase(iPositionTour).getPiece().get());
	return aTour->canAccessToCase(iPositionFinaleMove);
}

bool Roi::damePeuxTuerLeRoi(const Position& iPositionFinaleMove, const Position& iPositionDame) const{
	return (fouPeuxTuerLeRoi(iPositionFinaleMove, iPositionDame) &&
			tourPeuxTuerLeRoi(iPositionFinaleMove, iPositionDame));
}

bool Roi::secondRoiColle(const Position& iPositionFinaleMove, const Position& iPositionRoi) const{
	return (iPositionFinaleMove.evaluateDistance(iPositionRoi) <= 2);
}

const std::list <boost::shared_ptr <Move> > Roi::getPossibleMoves() const {
	std::list<boost::shared_ptr<Move> >aList;

	return aList;
}

}
