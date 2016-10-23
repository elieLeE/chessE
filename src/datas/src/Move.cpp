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

Move::Move(Position& iPositionStart, Position& iPositionEnd, ETypePiece iCapturedPiece, ETypeMove iTypeMove):
		_start(iPositionStart),
		_end(iPositionEnd),
		_capturedPiece(iCapturedPiece),
		_typeMove(iTypeMove)
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
	return (_typeMove == PRISE_EN_PASSANT);
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
			aBool = aPiece->isValideMove(*this);
		}
	}

	return aBool;
}

void Move::setMoveProperties(){
	game::EtatGame& aEtatGame = game::EtatGame::accessInstance();
	Piece* aPiece = &(aEtatGame.accessCase(_start).accessPiece());

	aPiece->movePiece(_end);

	if((aPiece->getTypePiece() == PION_TYPE) &&
			!_start.sameCol(_end) &&
			!aEtatGame.getCase(_end).hasPiece()){
		_typeMove = PRISE_EN_PASSANT;
		_capturedPiece = PION_TYPE;
	}
	else if(!aEtatGame.getCase(_end).hasPiece()){
		_capturedPiece = aEtatGame.getCase(_end).getPiece().getTypePiece();
	}
	else if(aPiece->getTypePiece() == ROI_TYPE){
		if(_start.evaluateDistance(_end) == PETIT_ROCK){
			_typeMove = PETIT_ROCK;
		}
		else if(_start.evaluateDistance(_end) == GRAND_ROCK){
			_typeMove = GRAND_ROCK;
		}
	}
}

void Move::operator=(const Move& iMove){
	_start = iMove.getStartPosition();
	_end = iMove.getEndPosition();
	_capturedPiece = iMove.getHasCapturedPiece();
	_typeMove = iMove.getTypeMove();
}
}
