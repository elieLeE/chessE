/*
 * Pieces.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Piece.h"
#include "../../game/src/EtatGame.h"

namespace datas{

Piece::Piece(EColor iColor, Position iPosition, ETypePiece iTypePiece, int iValue):
		_alive(true),
		_color(iColor),
		_position(iPosition),
		_value(iValue),
		_typePiece(iTypePiece)
{}

Piece::~Piece()
{}

void Piece::movePiece(Position& iPosition){
	_position = iPosition;
}

void Piece::setDead(){
	_alive = false;
}

void Piece::setAlive(){
	_alive = true;
}

/*bool Piece::firstMoveValidation(Move& iMove){
	if(iMove.getStartPosition() != _position){
		// rejeter une exception
		std::cout << "position de depart du mouvement ne correspond pas a celle de la piece" << std::endl;
	}

	else if(iMove.getEndPosition().isValid()){
		// rejeter une exception
		std::cout << "position finale du mouvement incorrecte" << std::endl;
	}
	else if{
		iM
	}
}*/

EColor Piece::getColor() const{
	return _color;
}

ETypePiece Piece::getTypePiece() const{
	return _typePiece;
}

const Position& Piece::getPosition() const{
	return _position;
}

Position& Piece::accessPosition(){
	return _position;
}

int Piece::evaluateDistance(const Move& iMove) const{
	int x2 = std::abs(iMove.getEndPosition().getX() - iMove.getEndPosition().getX());
	x2 = x2 * x2;

	int y2 = std::abs(iMove.getEndPosition().getY() - iMove.getEndPosition().getY());
	y2 = y2 * y2;

	return (x2 + y2);
}

}

