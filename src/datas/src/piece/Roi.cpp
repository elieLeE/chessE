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
#include "Tour.h"
#include "Fou.h"

namespace datas{

Roi::Roi(const EColor iColor, Position iPosition):
		Piece(iColor, iPosition, ROI_TYPE, ROI_VALUE)
{}

Roi::~Roi()
{}

bool Roi::isValideMove(const game::EtatGame& iEtatGame, const Move& iMove) const{
	return (estMoveOKTheorique(iEtatGame, iMove) &&
			estMoveOKPratique(iEtatGame, iMove));
}

//verifie que le movement est possible pour un Roi dans 1 cas general.
//ne verifie pas qu'il puisse mourir en jouant ainsi
bool Roi::estMoveOKTheorique(const game::EtatGame& iEtatGame, const Move& iMove) const{
	bool aBool = false;

	//aBool = this->isValideMove(iMove.getStartPosition());

	if(((Piece*)this)->isValideMove(iMove.getStartPosition())){
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
	Position aPositionFinale = iMove.getEndPosition();

	for( auto it = iEtatGame.getAllPiecesJ1().begin(); it != iEtatGame.getAllPiecesJ1().end(); ++it ){
		switch(it->get()->getTypePiece()){
		if(it->get()->isAlive()){
			case PION_TYPE:
				aBool = pionPeuxTuerLeRoi(aPositionFinale, it->get()->getPosition());
				break;

			case CAVALIER_TYPE:
				aBool = cavalierPeuxTuerLeRoi(aPositionFinale, it->get()->getPosition());
				break;

			case FOU_TYPE:
				aBool = fouPeuxTuerLeRoi(aPositionFinale, it->get()->getPosition());
				break;

			case TOUR_TYPE:
				aBool = tourPeuxTuerLeRoi(aPositionFinale, it->get()->getPosition());
				break;

			case DAME_TYPE:
				aBool = damePeuxTuerLeRoi(aPositionFinale, it->get()->getPosition());
				break;

			case ROI_TYPE:
				aBool = secondRoiColle(aPositionFinale, it->get()->getPosition());
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

bool Roi::pionPeuxTuerLeRoi(const Position& iPositionFinaleMove, const Position& iPositionPion) const{
	return (iPositionFinaleMove.evaluateDistance(iPositionPion) == 2);
}

bool Roi::cavalierPeuxTuerLeRoi(const Position& iPositionFinaleMove, const Position& iPositionCavalier) const{
	return (iPositionFinaleMove.evaluateDistance(iPositionCavalier) == 5);
}

bool Roi::fouPeuxTuerLeRoi(const Position& iPositionFinaleMove, const Position& iPositionFou) const{
	const Fou *aFou = dynamic_cast<const datas::Fou*>(&(game::EtatGame::getInstance()->getCase(iPositionFou).getPiece()));
	return aFou->canAccessToCase(iPositionFinaleMove);
}

bool Roi::tourPeuxTuerLeRoi(const Position& iPositionFinaleMove, const Position& iPositionTour) const{
	const Tour *aTour = dynamic_cast<const datas::Tour*>(&(game::EtatGame::getInstance()->getCase(iPositionTour).getPiece()));
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
