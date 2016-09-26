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

Roi::Roi(EColor iColor, Position iPosition):Piece(iColor, iPosition, ROI_TYPE, ROI_VALUE)
{}

Roi::~Roi()
{}

bool Roi::isValidatedMove(const game::EtatGame& iEtatGame, const Move& iMove) const{
	return true;
}

const std::list <boost::shared_ptr <Move> > Roi::getPossibleMoves() const {
	std::list<boost::shared_ptr<Move> >aList;

	return aList;
}

}
