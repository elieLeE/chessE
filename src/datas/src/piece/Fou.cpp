/*
 * Fou.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */
#include <cmath>

#include "Fou.h"
#include "../typeDefine/Dimension.h"
#include "../typeDefine/PieceValue.h"
#include "../typeDefine/TypePiece.h"
#include "../../../game/src/Echiquier.h"


namespace datas{

Fou::Fou(const EColor iColor, Position iPosition):
		Piece(iColor, iPosition, FOU_TYPE, FOU_VALUE)
{}

Fou::~Fou()
{}

bool Fou::isValideMove(const Move& iMove) const{
	return Piece::isValideMove(iMove) &&
			canAccessCase(iMove.getEndPosition());
}

bool Fou::canAccessCase(const Position& iPosition) const{
	bool aBool = false;

	if(_position.getColorCase() == iPosition.getColorCase()){
		aBool = true;
		int addLigne = (_position.getX()<iPosition.getX()?1:-1);
		int addCol = (_position.getY()<iPosition.getY()?1:-1);
		int diffLigne = _position.diffLigne(iPosition);
		int diffCol = _position.diffCol(iPosition);
		const game::Echiquier& aEchiquier = game::Echiquier::getInstance();

		aBool = (diffLigne == diffCol);

		for(int i=_position.getX()+addLigne, j=_position.getY()+addCol, n=0; (n<diffLigne-1) && aBool; i=i+addLigne, j=j+addCol, n++){
			aBool = !aEchiquier.getCase(i, j).hasPiece();
		}
	}

	return aBool;
}

}

