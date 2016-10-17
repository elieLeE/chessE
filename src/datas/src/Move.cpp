/*
 * Move.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Move.h"

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

bool Move::hasCapturePiece(){
	return !(_capturedPiece == NO_TYPE);
}

}
