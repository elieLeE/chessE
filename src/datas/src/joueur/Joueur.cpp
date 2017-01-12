/*
 * Joueur.cpp
 *
 *  Created on: 18 sept. 2016
 *      Author: le_e
 */

#include "Joueur.h"
#include "../typeDefine/PieceValue.h"
#include "../piece/Roi.h"

namespace datas {

Joueur::Joueur(EColor iColor, ETypePlayer iTypePlayer):
		/*_alivePiece(std::vector<boost::shared_ptr<Piece> >(0)),*/
		_color(iColor),
		_typePlayer(iTypePlayer),
		_points(INIT_TOTAL_POINTS)
{
	//boost::shared_ptr<Piece> aPiece;

	//aPiece = new Roi(_color, Position(0, 5));
	/*boost::shared_ptr<Roi> aRoi (new Roi(_color, Position(0, 5)));
	_alivePiece.insert(_alivePiece.begin(), 0, aRoi);*/

	//_alivePiece.insert(_alivePiece.begin(), 1, boost::shared_ptr<new Roi(_color, Position(0, 5))>);
}

Joueur::~Joueur()
{}

void Joueur::setKing(const PiecePtr iRoi){
	_myKing = _myKing = std::static_pointer_cast<Roi, Piece>(iRoi);;
}

const std::weak_ptr<Roi> Joueur::getKing() const{
	return _myKing;
}

bool Joueur::hasLost(){
	return !_myKing.expired() && !_myKing.lock()->isAlive();
}

bool Joueur::kingCheck(){
	return !_myKing.expired() && _myKing.lock()->canBeKilled();
}

/*MovePtr Joueur::newMove(){
	MovePtr aMove = this->nextMove();

	if(aMove->hasCapturePiece()){
		game::Echiquier* aEchiquier = game::Echiquier::accessInstance();
		aEchiquier->getPiece(aMove->getEndPosition().getX(), aMove->getEndPosition().getY())->setDead();
	}

	return aMove;
}*/

} /* namespace datas */
