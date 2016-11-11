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

#include "../../../common/src/DisplayType.h"

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

/* a corriger => ne fonctionne pas car quand appel aFou.isValideMove => Piece.isValideMove => une piece est trouve dans la case...
 * ou pas => canTakeCase sur la position finale, non initiale...
 */
bool Dame::canAccessCase(const Position& iPosition) const{
	Tour aTour(_color, _position);
	Fou aFou(_color, _position);
	Move aMove(_position, iPosition);

	return aTour.isValideMove(aMove) ||
			aFou.isValideMove(aMove);
}

}

