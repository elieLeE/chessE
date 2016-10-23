/*
 * Fou.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Fou.h"
#include "../typeDefine/PieceValue.h"
#include "../typeDefine/TypePiece.h"

namespace datas{

Fou::Fou(const EColor iColor, Position iPosition):
		Piece(iColor, iPosition, FOU_TYPE, FOU_VALUE)
{}

Fou::~Fou()
{}

bool Fou::isValideMove(const game::EtatGame& iEtatGame, const Move& iMove) const{
	return true;
}

bool Fou::canAccessToCase(const Position& iPosition) const{
	return true;
}

}

