/*
 * Roi.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Roi.h"
#include "TypePiece.h"
#include "PieceValue.h"
#include "../../game/src/EtatGame.h"

namespace datas{

Roi::Roi(const EColor iColor, Position iPosition):
		Piece(iColor, iPosition, ROI_TYPE, ROI_VALUE)
{}

Roi::~Roi()
{}

bool Roi::isValidateMove(const game::EtatGame& iEtatGame, const Move& iMove) const{
	bool aBool = false;

	//aBool = automaticValidationMove(iMove);

	//aBool = (Piece*)this->isValidateMove(iEtatGame, iMove);

	if(((Piece*)this)->isValidateMove(iEtatGame, iMove)){
		int dist = iMove.evaluateDistance();
		// d > 0 car on a verifie precedement que les position start et end n'etaient pas egales
		if(dist<=9){
			if(dist == 9){
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
			//movement normal
			else if(dist < 4){
				aBool = true;
			}
		}

		if(aBool){
			//on verifie que le roi ne peux pas se faire prendre au prochain coup par une piece adverse
		}
	}

	return aBool;
}

const std::list <boost::shared_ptr <Move> > Roi::getPossibleMoves() const {
	std::list<boost::shared_ptr<Move> >aList;

	return aList;
}

}
