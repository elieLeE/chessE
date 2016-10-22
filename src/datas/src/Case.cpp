/*
 * Case.cpp
 *
 *  Created on: 22 oct. 2016
 *      Author: le_e
 */

#include "Case.h"
#include "Roi.h"

namespace datas {

Case::Case()
{}

Case::~Case()
{}

bool Case::hasPiece() const{
	return (_piece?true:false);
}

const Piece& Case::getPiece() const{
	return *(_piece.get());
}

Piece& Case::accessPiece(){
	return *(_piece.get());
}

void Case::setPiece(Piece *iPiece){
	_piece.reset(iPiece);
}

void Case::resetPiece(){
	_piece.reset();
}

} /* namespace datas */
