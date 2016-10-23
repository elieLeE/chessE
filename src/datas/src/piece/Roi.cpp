/*
 * Roi.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Roi.h"
#include "../typeDefine/TypePiece.h"
#include "../typeDefine/PieceValue.h"
#include "../../../game/src/EtatGame.h"

namespace datas{

Roi::Roi(const EColor iColor, Position iPosition):
		Piece(iColor, iPosition, ROI_TYPE, ROI_VALUE)
{}

Roi::~Roi()
{}

bool Roi::isValidateMove(const game::EtatGame& iEtatGame, const Move& iMove) const{
	return (estMoveOKTheorique(iEtatGame, iMove) &&
			estMoveOKPratique(iEtatGame, iMove));
}

//verifie que le movement est possible pour un Roi dans 1 cas general.
//ne verifie pas qu'il puisse mourir en jouant ainsi
bool Roi::estMoveOKTheorique(const game::EtatGame& iEtatGame, const Move& iMove) const{
	bool aBool = false;

	if(((Piece*)this)->isValidateMove(iEtatGame, iMove)){
		int dist = iMove.evaluateDistance();
		// d > 0 car on a verifie precedement que les position start et end n'etaient pas egales
		//movement normal
		if(dist < 4){
			aBool = true;
		}
		else if(dist == 9){
			//ca doit etre 1 grand rock
			if(iMove.getStartPosition().sameLigne(iMove.getEndPosition())){
				//ok => grandrock
				aBool = true;
			}
		}
		else if(dist == 4){
			//ca doit etre 1 petit rock
			if(iMove.getStartPosition().sameLigne(iMove.getEndPosition())){
				//ok => grandrock
				aBool = true;
			}
		}
	}

	return aBool;
}

//verifie que le Roi ne peux pas etre pris au coup suivant => validation pratique
bool Roi::estMoveOKPratique(const game::EtatGame& iEtatGame, const Move& iMove) const{
	bool aBool = true;
	for( auto it = iEtatGame.getAllPiecesJ1().begin(); it != iEtatGame.getAllPiecesJ1().end(); ++it ){
		switch(it->get()->getTypePiece()){
		case PION_TYPE:
			aBool = pionPeuxTuerLeRoi(it->get()->getPosition());
			break;

		case CAVALIER_TYPE:
			aBool = cavalierPeuxTuerLeRoi(it->get()->getPosition());
			break;

		case FOU_TYPE:
			aBool = fouPeuxTuerLeRoi(it->get()->getPosition());
			break;

		case TOUR_TYPE:
			aBool = tourPeuxTuerLeRoi(it->get()->getPosition());
			break;

		case DAME_TYPE:
			aBool = damePeuxTuerLeRoi(it->get()->getPosition());
			break;
		}
		if(!aBool){
			break;
		}
	}
	return aBool;
}

bool Roi::pionPeuxTuerLeRoi(const Position& iposition) const{
	return true;
}

bool Roi::cavalierPeuxTuerLeRoi(const Position& iposition) const{
	return true;
}

bool Roi::fouPeuxTuerLeRoi(const Position& iposition) const{
	return true;
}

bool Roi::tourPeuxTuerLeRoi(const Position& iposition) const{
	return true;
}

bool Roi::damePeuxTuerLeRoi(const Position& iposition) const{
	return true;
}

const std::list <boost::shared_ptr <Move> > Roi::getPossibleMoves() const {
	std::list<boost::shared_ptr<Move> >aList;

	return aList;
}

}
