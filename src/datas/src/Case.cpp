/*
 * Case.cpp
 *
 *  Created on: 22 oct. 2016
 *      Author: le_e
 */

#include "Case.h"
#include "iostream"

namespace datas {

Case::Case()
{}

Case::~Case()
{
	/*std::cout << "~Case " << a << ", " << b << std::endl;
	b = (b+1)%8;
	if(b==0){
		a++;
	}*/
}

bool Case::hasPiece() const{
	return (_piece && _piece->isAlive());
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
	if(_piece){
		_piece.reset();
	}
}

} /* namespace datas */
