/*
 * Dame.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Dame.h"
#include "TypePiece.h"
#include "PieceValue.h"

namespace datas{

Dame::Dame(EColor iColor, Position iPosition):Piece(iColor, iPosition, DAME_TYPE, DAME_VALUE)
{}

Dame::~Dame()
{}

bool Dame::isValidatedMove(const game::EtatGame& iEtatGame, const Move& iMove) const{
	return true;
}

}

