/*
 * Pieces.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Piece.h"
#include "../../../game/src/Echiquier.h"

namespace datas{

Piece::Piece(const EColor iColor, Position iPosition, ETypePiece iTypePiece, const int iValue):
				_alive(true),
				_color(iColor),
				_position(iPosition),
				_numJ(iColor==WHITE?JOUEUR_1:JOUEUR_2),
				_value(iValue),
				_typePiece(iTypePiece)
{}

Piece::~Piece()
{}

void Piece::movePiece(const Position& iPosition){
	game::Echiquier::accessInstance().movePiece(_position, iPosition);
	_position = iPosition;
}

void Piece::setDead(){
	_alive = false;
}

void Piece::setAlive(){
	_alive = true;
}

bool Piece::isAlive() const{
	return _alive;
}

EColor Piece::getColor() const{
	return _color;
}

ETypePiece Piece::getTypePiece() const{
	return _typePiece;
}

int Piece::getNumJoueur() const{
	return _numJ;
}

const Position& Piece::getPosition() const{
	return _position;
}

Position& Piece::accessPosition(){
	return _position;
}

bool Piece::isValideMove(const Move& iMove) const{
	return (iMove.getStartPosition() == _position) &&
			canTakeCase(iMove.getEndPosition());
}

bool Piece::canTakeCase(const Position& iPosition) const{
	const game::Echiquier& aEchiquier = game::Echiquier::getInstance();

	//si on va a l'etape 2, c qu'on a une piece
	return (!aEchiquier.getCase(iPosition).hasPiece()) ||
			(aEchiquier.getCase(iPosition).getPiece()->getColor() != _color);
}

}

