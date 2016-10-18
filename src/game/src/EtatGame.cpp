/*
 * EtatGame.cpp
 *
 *  Created on: 20 sept. 2016
 *      Author: le_e
 */

#include <cmath>
#include <memory>
#include <iostream>

#include "EtatGame.h"
#include "../../datas/src/Pion.h"
#include "../../datas/src/Tour.h"
#include "../../datas/src/Cavalier.h"
#include "../../datas/src/Fou.h"
#include "../../datas/src/Roi.h"
#include "../../datas/src/Dame.h"
#include "../../datas/src/Dimension.h"


namespace game{

EtatGame* EtatGame::_instance = 0;

EtatGame::EtatGame():
		_possiblePriseEnPassant(false),
		_plateau(std::vector< std::vector< datas::PiecePtr> >(NBRE_LIGNE, std::vector< datas::PiecePtr>(NBRE_COLONNE, 0) ))
{}

EtatGame::~EtatGame()
{}

void EtatGame::initEtatGame(){
	/*std::
	for(int i=0; i<NBRE_LIGNE; i++){
		for(int j=0; j<NBRE_LIGNE; j++){

		}
	}*/
}

const EtatGame* EtatGame::getInstance() {
	_instance = new EtatGame();
	return _instance;
}

EtatGame* EtatGame::accessInstance() {
	_instance = new EtatGame();
	return _instance;
}

const datas::AllPiece& EtatGame::getAllPiecesJ1() const{
	return _allPiecesJ1;
}

void EtatGame::setAllPiecesJ1(datas::AllPiece& iAllPieces){
	_allPiecesJ1 = iAllPieces;
}

const datas::AllPiece& EtatGame::getAllPiecesJ2() const{
	return _allPiecesJ2;
}

void EtatGame::setAllPiecesJ2(datas::AllPiece& iAllPieces){
	_allPiecesJ2 = iAllPieces;
}

const datas::Plateau& EtatGame::getPlateau() const{
	return _plateau;
}

void EtatGame::setPlateau(datas::Plateau& iPlateau){
	_plateau = iPlateau;
}

bool EtatGame::getPossiblePriseEnPassant() const{
	return _possiblePriseEnPassant;
}

void EtatGame::setPossiblePriseEnPassant(bool iPossiblePriseEnPassant){
	_possiblePriseEnPassant = iPossiblePriseEnPassant;
}

void EtatGame::setBegginingGameWithoutHandicap(){
	datas::Position aPosition;

	//Pions
	for(int i = 0; i<NBRE_COLONNE; i++){
		aPosition.setPosition(1, i);
		datas::Pion *aPionWhite = new datas::Pion(datas::WHITE, aPosition, true);
		accessPiece(aPosition).reset(aPionWhite);

		aPosition.setPosition(6, i);
		datas::Pion *aPionBlack = new datas::Pion(datas::BLACK, aPosition, false);
		accessPiece(aPosition).reset(aPionBlack);
	}

	//Tours
	aPosition.setPosition(0, 0);
	datas::Tour *aTourWhiteLeft = new datas::Tour(datas::WHITE, aPosition);
	accessPiece(aPosition).reset(aTourWhiteLeft);

	aPosition.setPosition(0, 7);
	datas::Tour *aTourWhiteRight = new datas::Tour(datas::WHITE, aPosition);
	accessPiece(aPosition).reset(aTourWhiteRight);

	aPosition.setPosition(7, 0);
	datas::Tour *aTourBlackLeft = new datas::Tour(datas::BLACK, aPosition);
	accessPiece(aPosition).reset(aTourBlackLeft);

	aPosition.setPosition(7, 7);
	datas::Tour *aTourBlackRight = new datas::Tour(datas::BLACK, aPosition);
	accessPiece(aPosition).reset(aTourBlackRight);

	//Cavaliers
	aPosition.setPosition(0, 1);
	datas::Cavalier *aCavalierWhiteLeft = new datas::Cavalier(datas::WHITE, aPosition);
	accessPiece(aPosition).reset(aCavalierWhiteLeft);

	aPosition.setPosition(0, 6);
	datas::Cavalier *aCavalierWhiteRight = new datas::Cavalier(datas::WHITE, aPosition);
	accessPiece(aPosition).reset(aCavalierWhiteRight);

	aPosition.setPosition(7, 1);
	datas::Cavalier *aCavalierBlackLeft = new datas::Cavalier(datas::BLACK, aPosition);
	accessPiece(aPosition).reset(aCavalierBlackLeft);

	aPosition.setPosition(7, 6);
	datas::Cavalier *aCavalierBlackRight = new datas::Cavalier(datas::BLACK, aPosition);
	accessPiece(aPosition).reset(aCavalierBlackRight);

	//Fou
	aPosition.setPosition(0, 2);
	datas::Fou *aFouWhiteLeft = new datas::Fou(datas::WHITE, aPosition);
	accessPiece(aPosition).reset(aFouWhiteLeft);

	aPosition.setPosition(0, 5);
	datas::Fou *aFouWhiteRight = new datas::Fou(datas::WHITE, aPosition);
	accessPiece(aPosition).reset(aFouWhiteRight);

	aPosition.setPosition(7, 2);
	datas::Fou *aFouBlackLeft = new datas::Fou(datas::BLACK, aPosition);
	accessPiece(aPosition).reset(aFouBlackLeft);

	aPosition.setPosition(7, 5);
	datas::Fou *aFouBlackRight = new datas::Fou(datas::BLACK, aPosition);
	accessPiece(aPosition).reset(aFouBlackRight);

	//Dame
	aPosition.setPosition(0, 3);
	datas::Dame *aDameWhite = new datas::Dame(datas::WHITE, aPosition);
	accessPiece(aPosition).reset(aDameWhite);

	aPosition.setPosition(7, 4);
	datas::Dame *aDameBlack = new datas::Dame(datas::WHITE, aPosition);
	accessPiece(aPosition).reset(aDameBlack);

	//Roi
	aPosition.setPosition(0, 4);
	datas::Roi *aRoiWhite = new datas::Roi(datas::BLACK, aPosition);
	accessPiece(aPosition).reset(aRoiWhite);

	aPosition.setPosition(7, 3);
	datas::Roi *aRoiBlack = new datas::Roi(datas::BLACK, aPosition);
	accessPiece(aPosition).reset(aRoiBlack);
}

const datas::PiecePtr& EtatGame::getPiece(int ligne, int col) const{
	return _plateau.at(ligne).at(col);
}

datas::PiecePtr& EtatGame::accessPiece(int ligne, int col){
	return _plateau.at(ligne).at(col);
}

const datas::PiecePtr& EtatGame::getPiece(const datas::Position& iPosition) const{
	return _plateau.at(iPosition.getX()).at(iPosition.getY());
}

datas::PiecePtr& EtatGame::accessPiece(const datas::Position& iPosition){
	return _plateau.at(iPosition.getX()).at(iPosition.getY());
}

void EtatGame::setChangeMove(const datas::Move& iMove){
	this->setPossiblePriseEnPassant(false);
	datas::PiecePtr aPieceMove = this->getPiece(iMove.getStartPosition());
	if(aPieceMove->getTypePiece() == datas::PION_TYPE){
		if(std::abs(iMove.getStartPosition().getY() - iMove.getEndPosition().getY()) == 2){
			this->setPossiblePriseEnPassant(true);
		}
	}

	if(aPieceMove->getTypePiece() == datas::TOUR_TYPE){
		//si les deux tours ont bougés ou le roi => plus de rock possible
		//boost::shared_ptr<datas::Tour> aTour = std::dynamic_pointer_cast<datas::Tour>(aPieceMove);
	}

	//iMove.setPriseEnPassant(this->getPossiblePriseEnPassant());
	//iMove.setPriseEnPassant(true);

	if(iMove.hasCapturePiece()){
		this->accessPiece(iMove.getEndPosition())->setDead();
	}
	this->accessPiece(iMove.getEndPosition()).reset(this->getPiece(iMove.getStartPosition()).get());
	this->accessPiece(iMove.getStartPosition()) = 0;

	//ou ??
	/*this->accessPiece(iMove.getEndPosition()) = this->getPiece(iMove.getStartPosition()).get();
	this->accessPiece(iMove.getStartPosition()) = 0;*/
	//to study ==> non car on prends alors la valeur de la case du tableau
	//on veux prednre vers quoi pointe

	//this->getPiece(iMove.get)
}

} /* namespace game*/
