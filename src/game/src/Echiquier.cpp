/*
 * Echiquier.cpp
 *
 *  Created on: 20 sept. 2016
 *      Author: le_e
 */

#include <cmath>
#include <memory>
#include <iostream>

#include "Echiquier.h"
#include "../../datas/src/piece/Pion.h"
#include "../../datas/src/piece/Tour.h"
#include "../../datas/src/piece/Cavalier.h"
#include "../../datas/src/piece/Fou.h"
#include "../../datas/src/piece/Roi.h"
#include "../../datas/src/piece/Dame.h"

namespace game{

Echiquier Echiquier::_instance = Echiquier();
//Echiquier* Echiquier::_instance = 0;

Echiquier::Echiquier():
				_possiblePriseEnPassant(false),
				_hasAlreadyPiece(false)
{}

Echiquier::~Echiquier()
{}

void Echiquier::initEchiquier(){
	/*std::
	for(int i=0; i<NBRE_LIGNE; i++){
		for(int j=0; j<NBRE_LIGNE; j++){

		}
	}*/
}

const Echiquier& Echiquier::getInstance() {
	return _instance;
}

Echiquier& Echiquier::accessInstance() {
	return _instance;
}

const datas::AllPiecePtr& Echiquier::getAllPiecesJ1() const{
	return _allPiecesJoueurs[datas::JOUEUR_1];
}

void Echiquier::setAllPiecesJ1(datas::AllPiecePtr& iAllPieces){
	_allPiecesJoueurs[datas::JOUEUR_1] = iAllPieces;
}

const datas::AllPiecePtr& Echiquier::getAllPiecesJ2() const{
	return _allPiecesJoueurs[datas::JOUEUR_2];
}

void Echiquier::setAllPiecesJ2(datas::AllPiecePtr& iAllPieces){
	_allPiecesJoueurs[datas::JOUEUR_2] = iAllPieces;
}

bool Echiquier::getPossiblePriseEnPassant() const{
	return _possiblePriseEnPassant;
}

void Echiquier::setPossiblePriseEnPassant(bool iPossiblePriseEnPassant){
	_possiblePriseEnPassant = iPossiblePriseEnPassant;
}

void Echiquier::setBegginingGameWithoutHandicap(){
	datas::Position aPosition;

	//Pions
	for(int i = 0; i<NBRE_COLONNE; i++){
		aPosition.setPosition(1, i);
		datas::Pion *aPionWhite = new datas::Pion(datas::WHITE, aPosition, true);
		accessCase(aPosition).setPiece(aPionWhite);

		aPosition.setPosition(6, i);
		datas::Pion *aPionBlack = new datas::Pion(datas::BLACK, aPosition, false);
		accessCase(aPosition).setPiece(aPionBlack);
	}

	//Tours
	aPosition.setPosition(0, 0);
	datas::Tour *aTourWhiteLeft = new datas::Tour(datas::WHITE, aPosition);
	accessCase(aPosition).setPiece(aTourWhiteLeft);

	aPosition.setPosition(0, 7);
	datas::Tour *aTourWhiteRight = new datas::Tour(datas::WHITE, aPosition);
	accessCase(aPosition).setPiece(aTourWhiteRight);

	aPosition.setPosition(7, 0);
	datas::Tour *aTourBlackLeft = new datas::Tour(datas::BLACK, aPosition);
	accessCase(aPosition).setPiece(aTourBlackLeft);

	aPosition.setPosition(7, 7);
	datas::Tour *aTourBlackRight = new datas::Tour(datas::BLACK, aPosition);
	accessCase(aPosition).setPiece(aTourBlackRight);

	//Cavaliers
	aPosition.setPosition(0, 1);
	datas::Cavalier *aCavalierWhiteLeft = new datas::Cavalier(datas::WHITE, aPosition);
	accessCase(aPosition).setPiece(aCavalierWhiteLeft);

	aPosition.setPosition(0, 6);
	datas::Cavalier *aCavalierWhiteRight = new datas::Cavalier(datas::WHITE, aPosition);
	accessCase(aPosition).setPiece(aCavalierWhiteRight);

	aPosition.setPosition(7, 1);
	datas::Cavalier *aCavalierBlackLeft = new datas::Cavalier(datas::BLACK, aPosition);
	accessCase(aPosition).setPiece(aCavalierBlackLeft);

	aPosition.setPosition(7, 6);
	datas::Cavalier *aCavalierBlackRight = new datas::Cavalier(datas::BLACK, aPosition);
	accessCase(aPosition).setPiece(aCavalierBlackRight);

	//Fou
	aPosition.setPosition(0, 2);
	datas::Fou *aFouWhiteLeft = new datas::Fou(datas::WHITE, aPosition);
	accessCase(aPosition).setPiece(aFouWhiteLeft);

	aPosition.setPosition(0, 5);
	datas::Fou *aFouWhiteRight = new datas::Fou(datas::WHITE, aPosition);
	accessCase(aPosition).setPiece(aFouWhiteRight);

	aPosition.setPosition(7, 2);
	datas::Fou *aFouBlackLeft = new datas::Fou(datas::BLACK, aPosition);
	accessCase(aPosition).setPiece(aFouBlackLeft);

	aPosition.setPosition(7, 5);
	datas::Fou *aFouBlackRight = new datas::Fou(datas::BLACK, aPosition);
	accessCase(aPosition).setPiece(aFouBlackRight);

	//Dame
	aPosition.setPosition(0, 3);
	datas::Dame *aDameWhite = new datas::Dame(datas::WHITE, aPosition);
	accessCase(aPosition).setPiece(aDameWhite);

	aPosition.setPosition(7, 4);
	datas::Dame *aDameBlack = new datas::Dame(datas::WHITE, aPosition);
	accessCase(aPosition).setPiece(aDameBlack);

	//Roi
	aPosition.setPosition(0, 4);
	datas::Roi *aRoiWhite = new datas::Roi(datas::BLACK, aPosition);
	accessCase(aPosition).setPiece(aRoiWhite);

	aPosition.setPosition(7, 3);
	datas::Roi *aRoiBlack = new datas::Roi(datas::BLACK, aPosition);
	accessCase(aPosition).setPiece(aRoiBlack);

	_hasAlreadyPiece = true;
}

const datas::Case& Echiquier::getCase(int ligne, int col) const{
	return _echiquier[ligne][col];
}

datas::Case& Echiquier::accessCase(int ligne, int col){
	return _echiquier[ligne][col];
}

const datas::Case& Echiquier::getCase(const datas::Position& iPosition) const{
	return _echiquier[iPosition.getX()][iPosition.getY()];
}

datas::Case& Echiquier::accessCase(const datas::Position& iPosition){
	return _echiquier[iPosition.getX()][iPosition.getY()];
}

datas::Move& Echiquier::accessLastMove(){
	return _lastMove;
}

const datas::Move& Echiquier::getLastMove() const{
	return _lastMove;
}

/*
 * passer par un move non constant ?? => pas top niveau conception
 * necessaire pour setter si move est un rock ou priseEnPassant
 * peux pas le faire dans validMove (encore moins bien dans conception)
 */
void Echiquier::setChangeMove(const datas::Move& iMove){
	setPossiblePriseEnPassant(false);
	const datas::Piece* aPieceMove = this->getCase(iMove.getStartPosition()).getPiece().get();
	if(aPieceMove->getTypePiece() == datas::PION_TYPE){
		if(std::abs(iMove.getStartPosition().getY() - iMove.getEndPosition().getY()) == 2){
			this->setPossiblePriseEnPassant(true);
		}
	}

	if(std::abs(iMove.getStartPosition().getX() - iMove.getEndPosition().getX())){
		setPossiblePriseEnPassant(true);
	}

	if(iMove.hasCapturePiece()){
		this->accessCase(iMove.getEndPosition()).accessPiece()->setDead();
	}

	this->accessLastMove() = iMove;

	//ou ??
	/*this->accessPiece(iMove.getEndPosition()) = this->getPiece(iMove.getStartPosition()).get();
	this->accessPiece(iMove.getStartPosition()) = 0;*/
	//to study ==> non car on prends alors la valeur de la case du tableau
	//on veux prednre vers quoi pointe

	//this->getPiece(iMove.get)
	//movePiece(iMove.getStartPosition(), iMove.getEndPosition());
}

void Echiquier::movePiece(const datas::Position& iPositionStart, const datas::Position& iPositionEnd){
	this->accessCase(iPositionEnd).accessPiece()->movePiece(iPositionEnd);
	this->accessCase(iPositionStart).resetPiece();
}

void Echiquier::setPieceCaseXY(datas::Position& iPosition, datas::Piece* iPiece){
	accessCase(iPosition).setPiece(iPiece);
	_hasAlreadyPiece = true;
}

void Echiquier::reset(){
	if(_hasAlreadyPiece){
		_hasAlreadyPiece = false;
		for(auto it = _allPiecesJoueurs.begin(); it != _allPiecesJoueurs.end(); ++it){
			for(auto it2 = it->begin(); it2 != it->end(); ++it2){
				it2->reset();
			}
		}
	}
}

} /* namespace game*/
