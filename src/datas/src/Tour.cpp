/*
 * Tour.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Tour.h"
#include "TypePiece.h"
#include "PieceValue.h"

namespace datas{

Tour::Tour(EColor iColor, Position iPosition):Piece(iColor, iPosition, TOUR_TYPE, TOUR_VALUE)
{}

Tour::~Tour()
{}

bool Tour::isValidatedMove(const game::EtatGame& iEtatGame, const Move iMove) const{
	return true;
}

}
