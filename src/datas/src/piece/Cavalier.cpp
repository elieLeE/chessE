/*
 * Cavalier.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Cavalier.h"
#include "../typeDefine/TypePiece.h"
#include "../typeDefine/PieceValue.h"

namespace datas {

Cavalier::Cavalier(const EColor iColor, Position iPosition):
		Piece(iColor, iPosition, CAVALIER_TYPE, CAVALIER_VALUE)
{}

Cavalier::~Cavalier()
{}

bool Cavalier::isValideMove(const game::EtatGame &iEtatGame, const Move& iMove) const{
	if(iMove.getStartPosition() != _position){
		// rejeter une exception
		std::cout << "position de depart du mouvement ne correspond pas a celle de la piece" << std::endl;
	}

	else if(iMove.getEndPosition().isValid()){
		// rejeter une exception
		std::cout << "position finale du mouvement incorrecte" << std::endl;
	}

	else {
		/*
		 * verifier que la position finale du movement est accessible a partir
		 * de la position courante de la piece et de son type.
		 * verifier egalement qu'une autre piece de la meme couleur n'y est pas deja
		 * */

	}

	return true;
}

}
