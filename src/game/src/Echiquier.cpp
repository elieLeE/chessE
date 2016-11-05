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

Echiquier::Echiquier():
							_possiblePriseEnPassant(false),
							_hasAlreadyPiece(false)
{}

Echiquier::~Echiquier()
{}

void Echiquier::initEchiquier()
{}

const Echiquier& Echiquier::getInstance() {
	return _instance;
}

Echiquier& Echiquier::accessInstance() {
	return _instance;
}

const datas::AllPiecePtr& Echiquier::getAllPiecesJ1() const{
	return _allPiecesJoueurs[datas::JOUEUR_1];
}

const datas::AllPiecePtr& Echiquier::getAllPiecesJ2() const{
	return _allPiecesJoueurs[datas::JOUEUR_2];
}

bool Echiquier::getPossiblePriseEnPassant() const{
	return _possiblePriseEnPassant;
}

void Echiquier::setPossiblePriseEnPassant(bool iPossiblePriseEnPassant){
	_possiblePriseEnPassant = iPossiblePriseEnPassant;
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
	killPiece(iPositionEnd);
	datas::PiecePtr& aPiece = accessCase(iPositionStart).accessPiece();
	if(aPiece){
		aPiece->movePiece(iPositionEnd);
		setPiece(aPiece);
	}
}

void Echiquier::setPiece(datas::PiecePtr& iPiece){
	accessCase(iPiece->getPosition()).accessPiece() = std::move(iPiece);

}

void Echiquier::addPiece(datas::Piece* iPiece){
	datas::PiecePtr aPiecePtr(iPiece);
	addPiece(aPiecePtr);
}

void Echiquier::addPiece(datas::PiecePtr& iPiece){
	setPiece(iPiece);
	_hasAlreadyPiece = true;
	//addPiece iPiece in allPiece du joueur
}

void Echiquier::revivePiece(const datas::Position& iPosition){
	//pas excatement => prendre la derniere piece ajoute dans la liste des pieces morte de la case
	if(getCase(iPosition).hasPiece()){
		accessCase(iPosition).accessPiece()->setDead();
	}
}

void Echiquier::killPiece(const datas::Position& iPosition){
	if(getCase(iPosition).hasPiece()){
		accessCase(iPosition).accessPiece()->setDead();
	}
}

void Echiquier::reset(){
	if(_hasAlreadyPiece){
		_hasAlreadyPiece = false;
		/*for(auto it = _allPiecesJoueurs.begin(); it != _allPiecesJoueurs.end(); ++it){
			for(auto it2 = it->begin(); it2 != it->end(); ++it2){
				it2->reset();
			}
		}*/
		for(auto it = _echiquier.begin(); it != _echiquier.end(); ++it){
			for(auto it2 = it->begin(); it2 != it->end(); ++it2){
				if(it2->hasPiece()){
					it2->resetPiece();
				}
			}
		}
	}
}

void Echiquier::setBegginingGameWithoutHandicap(){
	datas::Position aPosition;

	//Pions
	for(int i = 0; i<NBRE_COLONNE; i++){
		aPosition.setPosition(1, i);
		datas::PiecePtr aPionWhite(new datas::Pion(datas::WHITE, aPosition, true));
		addPiece(aPionWhite);

		aPosition.setPosition(6, i);
		datas::PiecePtr aPionBlack(new datas::Pion(datas::BLACK, aPosition, false));
		addPiece(aPionBlack);
	}

	//Tours
	aPosition.setPosition(0, 0);
	datas::PiecePtr aTourWhiteLeft(new datas::Tour(datas::WHITE, aPosition));
	addPiece(aTourWhiteLeft);

	aPosition.setPosition(0, 7);
	datas::PiecePtr aTourWhiteRight(new datas::Tour(datas::WHITE, aPosition));
	addPiece(aTourWhiteRight);

	aPosition.setPosition(7, 0);
	datas::PiecePtr aTourBlackLeft(new datas::Tour(datas::BLACK, aPosition));
	addPiece(aTourBlackLeft);

	aPosition.setPosition(7, 7);
	datas::PiecePtr aTourBlackRight(new datas::Tour(datas::BLACK, aPosition));
	addPiece(aTourBlackRight);

	//Cavaliers
	aPosition.setPosition(0, 1);
	datas::PiecePtr aCavalierWhiteLeft(new datas::Cavalier(datas::WHITE, aPosition));
	addPiece(aCavalierWhiteLeft);

	aPosition.setPosition(0, 6);
	datas::PiecePtr aCavalierWhiteRight(new datas::Cavalier(datas::WHITE, aPosition));
	addPiece(aCavalierWhiteRight);

	aPosition.setPosition(7, 1);
	datas::PiecePtr aCavalierBlackLeft(new datas::Cavalier(datas::BLACK, aPosition));
	addPiece(aCavalierBlackLeft);

	aPosition.setPosition(7, 6);
	datas::PiecePtr aCavalierBlackRight(new datas::Cavalier(datas::BLACK, aPosition));
	addPiece(aCavalierBlackRight);

	//Fou
	aPosition.setPosition(0, 2);
	datas::PiecePtr aFouWhiteLeft(new datas::Fou(datas::WHITE, aPosition));
	addPiece(aFouWhiteLeft);

	aPosition.setPosition(0, 5);
	datas::PiecePtr aFouWhiteRight(new datas::Fou(datas::WHITE, aPosition));
	addPiece(aFouWhiteRight);

	aPosition.setPosition(7, 2);
	datas::PiecePtr aFouBlackLeft(new datas::Fou(datas::BLACK, aPosition));
	addPiece(aFouBlackLeft);

	aPosition.setPosition(7, 5);
	datas::PiecePtr aFouBlackRight(new datas::Fou(datas::BLACK, aPosition));
	addPiece(aFouBlackRight);

	//Dame
	aPosition.setPosition(0, 3);
	datas::PiecePtr aDameWhite(new datas::Dame(datas::WHITE, aPosition));
	addPiece(aDameWhite);

	aPosition.setPosition(7, 4);
	datas::PiecePtr aDameBlack(new datas::Dame(datas::WHITE, aPosition));
	addPiece(aDameBlack);

	//Roi
	aPosition.setPosition(0, 4);
	datas::PiecePtr aRoiWhite(new datas::Roi(datas::BLACK, aPosition));
	addPiece(aRoiWhite);

	aPosition.setPosition(7, 3);
	datas::PiecePtr aRoiBlack(new datas::Roi(datas::BLACK, aPosition));
	addPiece(aRoiBlack);

	_hasAlreadyPiece = true;
}

} /* namespace game*/

