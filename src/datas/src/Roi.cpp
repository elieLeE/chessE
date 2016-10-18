/*
 * Roi.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Roi.h"
#include "TypePiece.h"
#include "PieceValue.h"
#include "../../game/src/EtatGame.h"

namespace datas{

Roi::Roi(EColor iColor, Position iPosition):Piece(iColor, iPosition, ROI_TYPE, ROI_VALUE)
{}

Roi::~Roi()
{}

bool Roi::isValidatedMove(const game::EtatGame& iEtatGame, const Move& iMove) const{
	bool aBool = false;

	if(iMove.getStartPosition() != _position){
		// rejeter une exception
		std::cout << "position de depart du mouvement ne correspond pas a celle de la piece" << std::endl;
	}

	else if(!iMove.getEndPosition().isValid()){
		// rejeter une exception
		std::cout << "position finale du mouvement incorrecte" << std::endl;
	}

	else if(iMove.getEndPosition() == _position){
		// rejeter une exception
		std::cout << "position finale du mouvement correspond a la position initiale" << std::endl;
	}

	// d > 0 car on a verifie precedement que les position start et end n'etaient pas egales
	else if(iMove.evaluateDistance()<4){
		// rejeter une exception
		std::cout << "position finale inatteignable pour le Roi" << std::endl;
	}

	else {
		//on verifie que le roi ne peux pas se faire prendre au prochain coup par une piece adverse
	}

		return aBool;
}

const std::list <boost::shared_ptr <Move> > Roi::getPossibleMoves() const {
	std::list<boost::shared_ptr<Move> >aList;

	return aList;
}

}
