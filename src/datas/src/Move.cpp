/*
 * Move.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Move.h"
#include "../../game/src/Echiquier.h"

namespace datas{

Move::Move():
				_capturedPiece(NO_TYPE),
				_typeMove(NORMAL_MOVE)
{}

Move::Move(const Position& iPositionStart, const Position& iPositionEnd, ETypePiece iCapturedPiece, ETypeMove iTypeMove):
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

void Move::setPositionStart(const Position& iPosition){
	_start = iPosition;
}

const Position& Move::getEndPosition() const{
	return _end;
}

void Move::setPositionEnd(const Position& iPosition){
	_end = iPosition;
}

bool Move::hasCapturePiece() const{
	return !(_capturedPiece == NO_TYPE);
}

int Move::evaluateDistance() const{
	return _start.evaluateDistance(_end);
}

ETypePiece Move::getCapturedPiece() const{
	return _capturedPiece;
}
void Move::setCapturedPiece(ETypePiece iCapturedPiece){
	_capturedPiece = iCapturedPiece;
}

ETypeMove Move::getTypeMove() const{
	return _typeMove;
}

void Move::setTypeMove(ETypeMove iTypeMove){
	_typeMove = iTypeMove;
}

bool Move::isValidateMove(const game::Echiquier& iEchiquier) const{
	bool aBool = false;

	if((getStartPosition().isValid()) && (getEndPosition().isValid()) && (this->getStartPosition() != this->getEndPosition())){
		if(iEchiquier.getCase(this->getStartPosition()).hasPiece()){
			const PiecePtr& aPiece = iEchiquier.getCase(this->getStartPosition()).getPiece();
			aBool = aPiece->isValideMove(*this);
		}
	}

	return aBool;
}

void Move::setMoveProperties(){
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	const PiecePtr& aPiece = aEchiquier.getCase(_start).getPiece();

	_typeMove = NORMAL_MOVE;
	_capturedPiece = NO_TYPE;

	if(aPiece){
		if((aPiece->getTypePiece() == PION_TYPE) &&
				(evaluateDistance() ==  PRISE_EN_PASSANT) &&
				!aEchiquier.getCase(_end).hasPiece()){
			_typeMove = PRISE_EN_PASSANT;
			_capturedPiece = PION_TYPE;
		}
		else if(aPiece->getTypePiece() == ROI_TYPE){
			int dist = evaluateDistance();
			if(dist == PETIT_ROCK){
				_typeMove = PETIT_ROCK;
			}
			else if(dist == GRAND_ROCK){
				_typeMove = GRAND_ROCK;
			}
		}
	}
	if(aEchiquier.getCase(_end).hasPiece()){
		_capturedPiece = aEchiquier.getCase(_end).getPiece()->getTypePiece();
	}
	aEchiquier.setChangeMove(*this);
}

void Move::operator=(const Move& iMove){
	_start = iMove.getStartPosition();
	_end = iMove.getEndPosition();
	_capturedPiece = iMove.getCapturedPiece();
	_typeMove = iMove.getTypeMove();
}

//utilise des enums class ??
std::ostream& operator<<(std::ostream& os, const Move& iMove){
	os << "start : " << iMove.getStartPosition() << " / end : " << iMove.getEndPosition() << std::endl;
	os << "type : " << iMove.getTypeMove() << " / capturedPiece : " << iMove.getCapturedPiece() << std::endl;

	return os;
}
}
