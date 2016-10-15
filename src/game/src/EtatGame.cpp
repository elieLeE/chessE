/*
 * EtatGame.cpp
 *
 *  Created on: 20 sept. 2016
 *      Author: le_e
 */

#include "EtatGame.h"

namespace game{

EtatGame* EtatGame::_instance = 0;

EtatGame::EtatGame(): _possiblePriseEnPassant(false)
{}

EtatGame::~EtatGame()
{}

const EtatGame* EtatGame::getInstance() {
	_instance = new EtatGame();
	return _instance;
}

EtatGame* EtatGame::accessInstance() {
	_instance = new EtatGame();
	return _instance;
}

const datas::AlivePieceCSPtr& EtatGame::getAlivePiecesJ1() const{
	return _alivePiecesJ1;
}

void EtatGame::setAlivePiecesJ1(datas::AlivePieceCSPtr& iAllievePieces){
	_alivePiecesJ1 = iAllievePieces;
}

const datas::AlivePieceCSPtr& EtatGame::getAlivePiecesJ2() const{
	return _alivePiecesJ2;
}

void EtatGame::setAlivePiecesJ2(datas::AlivePieceCSPtr& iAllivePieces){
	_alivePiecesJ2 = iAllivePieces;
}

const datas::PlateauCSPtr& EtatGame::getPlateau() const{
	return _plateau;
}

void EtatGame::setPlateau(datas::PlateauCSPtr& iPlateau){
	_plateau = iPlateau;
}

bool EtatGame::getPossiblePriseEnPassant() const{
	return _possiblePriseEnPassant;
}

void EtatGame::setPossiblePriseEnPassant(bool iPossiblePriseEnPassant){
	_possiblePriseEnPassant = iPossiblePriseEnPassant;
}

} /* namespace game*/
