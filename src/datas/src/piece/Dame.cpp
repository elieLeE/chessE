/*
 * Dame.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Dame.h"
#include "../typeDefine/TypePiece.h"
#include "../typeDefine/PieceValue.h"
#include "../Move.h"
#include "Tour.h"
#include "Fou.h"

namespace datas{

Dame::Dame(const EColor iColor, Position iPosition):
		Piece(iColor, iPosition, DAME_TYPE, DAME_VALUE)
{}

Dame::~Dame()
{}

bool Dame::isValideMove(const Move& iMove) const{
	return Piece::isValideMove(iMove) &&
			canAccessCase(iMove.getEndPosition());
}

bool Dame::canAccessCase(const Position& iPosition) const{
	Tour aTour(_color, _position);
	Fou aFou(_color, _position);
	Move aMove(_position, iPosition);

	return aTour.isValideMove(aMove) &&
			aFou.isValideMove(aMove);
}

}

