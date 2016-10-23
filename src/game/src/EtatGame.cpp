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

namespace game{

EtatGame* EtatGame::_instance = 0;

EtatGame::EtatGame():
		_possiblePriseEnPassant(false),
		_hasAlreadyPiece(false)
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

const datas::Echiquier& EtatGame::getEchiquier() const{
	return _echiquier;
}

void EtatGame::setEchiquier(datas::Echiquier& iEchiquier){
	_echiquier = iEchiquier;
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
		accessCase(aPosition).setPiece(aPionWhite);

		aPosition.setPosition(6, i);
		datas::Pion *aPionBlack = new datas::Pion(datas::BLACK, aPosition, false);
		accessCase(aPosition).setPiece(aPionBlack);
	}

	//Tours
	aPosition.setPosition(0, 0);
	datas::Tour *aTourWhiteLeft = new datas::Tour(datas::WHITE, aPosition, datas::Tour::TOUR_1);
	accessCase(aPosition).setPiece(aTourWhiteLeft);

	aPosition.setPosition(0, 7);
	datas::Tour *aTourWhiteRight = new datas::Tour(datas::WHITE, aPosition, datas::Tour::TOUR_2);
	accessCase(aPosition).setPiece(aTourWhiteRight);

	aPosition.setPosition(7, 0);
	datas::Tour *aTourBlackLeft = new datas::Tour(datas::BLACK, aPosition, datas::Tour::TOUR_1);
	accessCase(aPosition).setPiece(aTourBlackLeft);

	aPosition.setPosition(7, 7);
	datas::Tour *aTourBlackRight = new datas::Tour(datas::BLACK, aPosition, datas::Tour::TOUR_2);
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

const datas::Case& EtatGame::getCase(int ligne, int col) const{
	return _echiquier[ligne][col];
}

datas::Case& EtatGame::accessCase(int ligne, int col){
	return _echiquier[ligne][col];
}

const datas::Case& EtatGame::getCase(const datas::Position& iPosition) const{
	return _echiquier[iPosition.getX()][iPosition.getY()];
}

datas::Case& EtatGame::accessCase(const datas::Position& iPosition){
	return _echiquier[iPosition.getX()][iPosition.getY()];
}

datas::Move& EtatGame::accessLastMove(){
	return _lastMove;
}

const datas::Move& EtatGame::getLastMove() const{
	return _lastMove;
}

/*
 * passer par un move non constant ?? => pas top niveau conception
 * necessaire pour setter si move est un rock ou priseEnPassant
 * peux pas le faire dans validMove (encore moins bien dans conception)
 */
void EtatGame::setChangeMove(const datas::Move& iMove){
	setPossiblePriseEnPassant(false);
	const datas::Piece* aPieceMove = &(this->getCase(iMove.getStartPosition()).getPiece());
	if(aPieceMove->getTypePiece() == datas::PION_TYPE){
		if(std::abs(iMove.getStartPosition().getY() - iMove.getEndPosition().getY()) == 2){
			this->setPossiblePriseEnPassant(true);
		}
	}

	int numJ = aPieceMove->getNumJoueur();
	if(_rockPossible[numJ]){
		if(aPieceMove->getTypePiece() == datas::ROI_TYPE){
			_rockPossible[numJ] = false;
		}

		if(aPieceMove->getTypePiece() == datas::TOUR_TYPE){
			//si les deux tours ont bougés ou le roi => plus de rock possible
			//boost::shared_ptr<datas::Tour> aTour = std::dynamic_pointer_cast<datas::Tour>(aPieceMove);
			const datas::Tour* aTour = dynamic_cast<const datas::Tour*>(aPieceMove);
			int numTour = aTour->getNumTour();
			tourAlreadyMoved[numJ][numTour];
			if(tourAlreadyMoved[numJ][(numTour+1)%2]){
				_rockPossible[numJ] = false;
			}
		}
	}

	if(std::abs(iMove.getStartPosition().getX() - iMove.getEndPosition().getX())){
		setPossiblePriseEnPassant(true);
	}

	if(iMove.hasCapturePiece()){
		this->accessCase(iMove.getEndPosition()).accessPiece().setDead();
	}

	this->accessLastMove() = iMove;

	//ou ??
	/*this->accessPiece(iMove.getEndPosition()) = this->getPiece(iMove.getStartPosition()).get();
	this->accessPiece(iMove.getStartPosition()) = 0;*/
	//to study ==> non car on prends alors la valeur de la case du tableau
	//on veux prednre vers quoi pointe

	//this->getPiece(iMove.get)
	movePiece(iMove.getStartPosition(), iMove.getEndPosition());
}

void EtatGame::movePiece(const datas::Position& iPositionStart, const datas::Position& iPositionEnd){
	this->accessCase(iPositionEnd).setPiece(&(this->accessCase(iPositionStart).accessPiece()));
	this->accessCase(iPositionStart).resetPiece();
}

} /* namespace game*/
