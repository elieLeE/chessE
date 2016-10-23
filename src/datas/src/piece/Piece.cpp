/*
 * Pieces.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Piece.h"
#include "../../../game/src/EtatGame.h"

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

void Piece::movePiece(Position& iPosition){
	_position = iPosition;
}

void Piece::setDead(){
	_alive = false;
}

void Piece::setAlive(){
	_alive = true;
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

bool Piece::isValidateMove(const game::EtatGame& iEtatGame, const Move& iMove) const{
	bool aBool = false;

	if(iMove.getStartPosition() == _position){
		aBool = true;
	}

	return aBool;
}

}

