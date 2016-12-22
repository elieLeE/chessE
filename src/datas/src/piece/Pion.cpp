/*
 * Pion.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Pion.h"
#include "../typeDefine/TypePiece.h"
#include "../typeDefine/PieceValue.h"
#include "../../../game/src/Echiquier.h"
#include "../typeDefine/Types.h"
#include "../../../common/src/DisplayType.h"

namespace datas{

Pion::Pion(const EColor iColor, Position iPosition, const bool iSens):
										Piece(iColor, iPosition, PION_TYPE, PION_VALUE),
										_hasAlreadyMoved(false),
										_sensCroissant(iSens)
{}

Pion::~Pion()
{}

void Pion::movePiece(const Position& iPosition){
	Piece::movePiece(iPosition);
	_hasAlreadyMoved = true;
}

bool Pion::isValideMove(const Move& iMove) const{
	bool aBool = false;

	aBool = Piece::isValideMove(iMove) &&
			canAccessCase(iMove.getEndPosition());

	return aBool;
}

bool Pion::canAccessCase(const Position& iPosition) const{
	const game::Echiquier& aEchiquier = game::Echiquier::getInstance();
	bool aBool = false;

	//verifSensMove est fait ici et non dans les methodes isSimpleMove, isSimpleCapture, isPassantCapture
	aBool = verifSensMove(iPosition) &&
			(isSimpleMove(iPosition, aEchiquier) || isSimpleCapture(iPosition, aEchiquier) || isPassantCapture(iPosition, aEchiquier));

	return aBool;

}

bool Pion::isSimpleMove(const Position& iPosition, const game::Echiquier& iEchiquier) const{
	return ((_position.evaluateDistance(iPosition) == distanceMove(SIMPLE_MOVE_PION))
					|| ((_position.evaluateDistance(iPosition) == distanceMove(DOUBLE_MOVE_PION)) && !_hasAlreadyMoved)) &&
			_position.sameLigne(iPosition) &&
			(!iEchiquier.getCase(iPosition).hasPiece());
}

bool Pion::isSimpleCapture(const Position& iPosition, const game::Echiquier& iEchiquier) const{
	return (_position.evaluateDistance(iPosition) == distanceMove(SIMPLE_CAPTURE_PION)) && iEchiquier.getCase(iPosition).hasPiece();
}

bool Pion::isPassantCapture(const Position& iPosition, const game::Echiquier& iEchiquier) const{
	bool aBool = false;

	//hasPiece has to be false => finale destnation
	aBool = iEchiquier.getPossiblePriseEnPassant() &&
			!iEchiquier.getCase(iPosition).hasPiece();

	if(aBool){
		const PiecePtr& aSecondPiece = iEchiquier.getCase(iPosition.getX(), _position.getY()).getPiece();

		//on ne verifie pas le sens du mouvement => fait dans canAccessCase
		aBool = aSecondPiece &&
				(aSecondPiece->getTypePiece() == PION_TYPE) &&
				(aSecondPiece->getColor() != getColor()) &&
				(_position.evaluateDistance(iPosition) == distanceMove(PRISE_EN_PASSANT)) &&
				(iPosition.getX() == iEchiquier.getLastMove().getEndPosition().getX());
	}

	return aBool;
}

bool Pion::canKillCasePiece(const Position& iPosition) const{
	return (_position.evaluateDistance(iPosition) == distanceMove(SIMPLE_CAPTURE_PION)) && verifSensMove(iPosition);
}

bool Pion::verifSensMove(const Position& iPositionEnd) const{
	return (_sensCroissant && _position.getY() < iPositionEnd.getY()) ||
			(!_sensCroissant && _position.getY() > iPositionEnd.getY());
}

bool Pion::hasAlreadyMoved(void) const{
	return _hasAlreadyMoved;
}

bool Pion::getSensCroissant(void) const{
	return _sensCroissant;
}

/*const std::list <boost::shared_ptr <Move> > Pion::getPossibleMoves() const{
	std::list <boost::shared_ptr <Move> > aList;

	return aList;
}*/

std::ostream& operator<<(std::ostream& os, const Pion& iPion){
	os << *((Piece*)&iPion) <<
			"sens croissant ? " << boolToString(iPion.getSensCroissant()) << std::endl <<
			"already moved ? " << boolToString(iPion.hasAlreadyMoved()) << std::endl;

	return os;
}

}
