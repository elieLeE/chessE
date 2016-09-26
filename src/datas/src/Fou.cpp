/*
 * Fou.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Fou.h"
#include "PieceValue.h"
#include "TypePiece.h"

namespace datas{

Fou::Fou(EColor iColor, Position iPosition):Piece(iColor, iPosition, FOU_TYPE, FOU_VALUE)
{}

Fou::~Fou()
{}

bool Fou::isValidatedMove(const game::EtatGame& iEtatGame, const Move& iMove) const{
	return true;
}

}

