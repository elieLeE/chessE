/*
 * Move.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Move.h"
#include "../../game/src/EtatGame.h"

namespace datas{

Move::Move()
{}

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

ETypePiece Move::getHasCapturedPiece() const{
	return _capturedPiece;
}
void Move::setHasCapturedPiece(ETypePiece iCapturedPiece){
	_capturedPiece = iCapturedPiece;
}

ETypeMove Move::getTypeMove() const{
	return _typeMove;
}

void Move::setTypeMove(ETypeMove iTypeMove){
	_typeMove = iTypeMove;
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

void Move::operator=(const Move& iMove){
	_start = iMove.getStartPosition();
	_end = iMove.getEndPosition();
	_priseEnPassant = iMove.getPriseEnPassant();
	_capturedPiece = iMove.getHasCapturedPiece();
	_typeMove = iMove.getTypeMove();
}
}
