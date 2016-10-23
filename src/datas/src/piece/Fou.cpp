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
#include "../../../game/src/EtatGame.h"


namespace datas{

Fou::Fou(const EColor iColor, Position iPosition):
		Piece(iColor, iPosition, FOU_TYPE, FOU_VALUE)
{}

Fou::~Fou()
{}

bool Fou::isValideMove(const Move& iMove) const{
	return true;
}

bool Fou::canAccessToCase(const Position& iPosition) const{
	bool aBool = true;

	if(_position.getColorCase() == iPosition.getColorCase()){
		aBool = true;
		int addLigne = (_position.getX()<iPosition.getX()?1:-1);
		int addCol = (_position.getY()<iPosition.getY()?1:-1);
		const game::EtatGame *aGame = game::EtatGame::getInstance();

		for(int i=_position.getX()+addLigne, j=_position.getY(); (i<NBRE_LIGNE) && (i>=0); i=i+addLigne, j=j+addCol){
			if(aGame->getCase(i, j).hasPiece()){
				aBool = false;
				break;
			}
		}
	}

	return aBool;
}

}

