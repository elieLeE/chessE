/*
 * Pieces.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Piece.h"
#include "../../game/src/EtatGame.h"

namespace datas{

Piece::Piece(const EColor iColor, Position iPosition, ETypePiece iTypePiece, const int iValue):
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

bool Piece::isValidateMove(const game::EtatGame& iEtatGame, const Move& iMove) const{
	bool aBool = false;

	if(iMove.getStartPosition() != _position){
		// rejeter une exception
		std::cout << "position de depart du mouvement ne correspond pas a celle de la piece" << std::endl;
	}

	else if(!iMove.getEndPosition().isValid()){
		// rejeter une exception
		std::cout << "position finale du mouvement incorrecte" << std::endl;
	}

	else if(iMove.getEndPosition() == _position){
		// rejeter une exception
		//_position = getEndPosition
		std::cout << "position finale du mouvement correspond a la position initiale" << std::endl;
	}

	return aBool;
}

}

