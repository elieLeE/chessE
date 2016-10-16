/*
 * EtatGame.cpp
 *
 *  Created on: 20 sept. 2016
 *      Author: le_e
 */

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

EtatGame::EtatGame(): _possiblePriseEnPassant(false),
		_plateau(new std::vector< std::vector< datas::PiecePtr> >(NBRE_LIGNE, std::vector< datas::PiecePtr>(NBRE_COLONNE, 0) ))
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

const datas::AlivePiecePtr& EtatGame::getAlivePiecesJ1() const{
	return _alivePiecesJ1;
}

void EtatGame::setAlivePiecesJ1(datas::AlivePiecePtr& iAllievePieces){
	_alivePiecesJ1 = iAllievePieces;
}

const datas::AlivePiecePtr& EtatGame::getAlivePiecesJ2() const{
	return _alivePiecesJ2;
}

void EtatGame::setAlivePiecesJ2(datas::AlivePiecePtr& iAllivePieces){
	_alivePiecesJ2 = iAllivePieces;
}

const datas::PlateauPtr& EtatGame::getPlateau() const{
	return _plateau;
}

void EtatGame::setPlateau(datas::PlateauPtr& iPlateau){
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
		accessPiece(aPosition.getX(), aPosition.getY()).reset(aPionWhite);

		aPosition.setPosition(6, i);
		datas::Pion *aPionBlack = new datas::Pion(datas::BLACK, aPosition, false);
		accessPiece(aPosition.getX(), aPosition.getY()).reset(aPionBlack);
	}

	//Tours
	aPosition.setPosition(0, 0);
	datas::Tour *aTourWhiteLeft = new datas::Tour(datas::WHITE, aPosition);
	accessPiece(aPosition.getX(), aPosition.getY()).reset(aTourWhiteLeft);

	aPosition.setPosition(0, 7);
	datas::Tour *aTourWhiteRight = new datas::Tour(datas::WHITE, aPosition);
	accessPiece(aPosition.getX(), aPosition.getY()).reset(aTourWhiteRight);

	aPosition.setPosition(7, 0);
	datas::Tour *aTourBlackLeft = new datas::Tour(datas::BLACK, aPosition);
	accessPiece(aPosition.getX(), aPosition.getY()).reset(aTourBlackLeft);

	aPosition.setPosition(7, 7);
	datas::Tour *aTourBlackRight = new datas::Tour(datas::BLACK, aPosition);
	accessPiece(aPosition.getX(), aPosition.getY()).reset(aTourBlackRight);

	//Cavaliers
	aPosition.setPosition(0, 1);
	datas::Cavalier *aCavalierWhiteLeft = new datas::Cavalier(datas::WHITE, aPosition);
	accessPiece(aPosition.getX(), aPosition.getY()).reset(aCavalierWhiteLeft);

	aPosition.setPosition(0, 6);
	datas::Cavalier *aCavalierWhiteRight = new datas::Cavalier(datas::WHITE, aPosition);
	accessPiece(aPosition.getX(), aPosition.getY()).reset(aCavalierWhiteRight);

	aPosition.setPosition(7, 1);
	datas::Cavalier *aCavalierBlackLeft = new datas::Cavalier(datas::BLACK, aPosition);
	accessPiece(aPosition.getX(), aPosition.getY()).reset(aCavalierBlackLeft);

	aPosition.setPosition(7, 6);
	datas::Cavalier *aCavalierBlackRight = new datas::Cavalier(datas::BLACK, aPosition);
	accessPiece(aPosition.getX(), aPosition.getY()).reset(aCavalierBlackRight);

	//Fou
	aPosition.setPosition(0, 2);
	datas::Fou *aFouWhiteLeft = new datas::Fou(datas::WHITE, aPosition);
	accessPiece(aPosition.getX(), aPosition.getY()).reset(aFouWhiteLeft);

	aPosition.setPosition(0, 5);
	datas::Fou *aFouWhiteRight = new datas::Fou(datas::WHITE, aPosition);
	accessPiece(aPosition.getX(), aPosition.getY()).reset(aFouWhiteRight);

	aPosition.setPosition(7, 2);
	datas::Fou *aFouBlackLeft = new datas::Fou(datas::BLACK, aPosition);
	accessPiece(aPosition.getX(), aPosition.getY()).reset(aFouBlackLeft);

	aPosition.setPosition(7, 5);
	datas::Fou *aFouBlackRight = new datas::Fou(datas::BLACK, aPosition);
	accessPiece(aPosition.getX(), aPosition.getY()).reset(aFouBlackRight);

	//Dame
	aPosition.setPosition(0, 3);
	datas::Dame *aDameWhite = new datas::Dame(datas::WHITE, aPosition);
	accessPiece(aPosition.getX(), aPosition.getY()).reset(aDameWhite);

	aPosition.setPosition(7, 4);
	datas::Dame *aDameBlack = new datas::Dame(datas::WHITE, aPosition);
	accessPiece(aPosition.getX(), aPosition.getY()).reset(aDameBlack);

	//Roi
	aPosition.setPosition(0, 4);
	datas::Roi *aRoiWhite = new datas::Roi(datas::BLACK, aPosition);
	accessPiece(aPosition.getX(), aPosition.getY()).reset(aRoiWhite);

	aPosition.setPosition(7, 3);
	datas::Roi *aRoiBlack = new datas::Roi(datas::BLACK, aPosition);
	accessPiece(aPosition.getX(), aPosition.getY()).reset(aRoiBlack);
}

const datas::PiecePtr& EtatGame::getPiece(int ligne, int col) const{
	/*datas::Plateau* aPlateau = _plateau.get();
	std::vector<datas::PiecePtr>* aVector = &(aPlateau->at(ligne));
	datas::PiecePtr *aPiece = &(aVector->at(col));*/
	//return *aPiece;
	//_plateau->at(ligne).at(col)(new datas::Pion());
	return _plateau->at(ligne).at(col);
}

datas::PiecePtr& EtatGame::accessPiece(int ligne, int col){
	return _plateau->at(ligne).at(col);
}

} /* namespace game*/
