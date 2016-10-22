/*
 * Move.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Move.h"
#include "../../game/src/EtatGame.h"

namespace datas{

Move::Move(Position& iPositionStart, Position& iPositionEnd, ETypePiece iCapturedPiece, bool iPriseEnPassant):
		_start(iPositionStart),
		_end(iPositionEnd),
		_priseEnPassant(iPriseEnPassant),
		_capturedPiece(iCapturedPiece)
{}

Move::~Move()
{}

const Position& Move::getStartPosition() const{
	return _start;
}

const Position& Move::getEndPosition() const{
	return _end;
}

bool Move::hasCapturePiece() const{
	return !(_capturedPiece == NO_TYPE);
}

int Move::evaluateDistance() const{
	return _start.evaluateDistance(_end);
}

bool Move::getPriseEnPassant() const{
	return _priseEnPassant;
}

void Move::setPriseEnPassant(bool iBool){
	_priseEnPassant = iBool;
}

bool Move::isValidateMove(const game::EtatGame& iEtatGame) const{
	bool aBool = false;

	if((this->getEndPosition().isValid()) && (this->getStartPosition() == this->getEndPosition())){
		//PiecePtr aPiece = iEtatGame.getCase(this->getStartPosition()).getPiece();
		if(iEtatGame.getCase(this->getStartPosition()).hasPiece()){
			const Piece* aPiece = &(iEtatGame.getCase(this->getStartPosition()).getPiece());
			aBool = aPiece->isValidateMove(iEtatGame, *this);
		}
	}

	return aBool;
}
}
