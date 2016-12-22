/*
 * Cavalier.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Cavalier.h"
#include "../typeDefine/TypePiece.h"
#include "../typeDefine/TypeMove.h"
#include "../typeDefine/PieceValue.h"

namespace datas {

Cavalier::Cavalier(const EColor iColor, Position iPosition):
		Piece(iColor, iPosition, CAVALIER_TYPE, CAVALIER_VALUE)
{}

Cavalier::~Cavalier()
{}

bool Cavalier::isValideMove(const Move& iMove) const{
	return Piece::isValideMove(iMove) &&
			canAccessCase(iMove.getEndPosition());
}

bool Cavalier::canAccessCase(const Position& iPosition) const{
	return (_position.evaluateDistance(iPosition) == distanceMove(CAVALIER_MOVE));
}

}
