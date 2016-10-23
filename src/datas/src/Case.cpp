/*
 * Case.cpp
 *
 *  Created on: 22 oct. 2016
 *      Author: le_e
 */

#include "Case.h"

namespace datas {

Case::Case()
{}

Case::~Case()
{}

bool Case::hasPiece() const{
	return (_piece?true:false);
}

const PiecePtr& Case::getPiece() const{
	return _piece;
}

PiecePtr& Case::accessPiece(){
	return _piece;
}

void Case::setPiece(Piece *iPiece){
	_piece.reset(iPiece);
}

void Case::resetPiece(){
	_piece.reset();
}

} /* namespace datas */
