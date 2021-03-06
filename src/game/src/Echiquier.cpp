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

#include "../../datas/src/typeDefine/TypePiece.h"

#include "../../datas/src/joueur/Joueur.h"
#include "../../datas/src/joueur/JoueurHumain.h"

namespace game{

Echiquier Echiquier::_instance = Echiquier();

Echiquier::Echiquier():_possiblePriseEnPassant(false),
		_hasAlreadyPiece(false)
{
	setAutomatiquejoueurs();
}

Echiquier::~Echiquier()
{}

const datas::Echiquier& Echiquier::getPlateau() const{
	return _echiquier;
}

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

const datas::Case& Echiquier::getCase(int ligne, int col) const{
	return _echiquier[col-1][ligne-1];
}

datas::Case& Echiquier::accessCase(int ligne, int col){
	return _echiquier[col-1][ligne-1];
}

const datas::Case& Echiquier::getCase(const datas::Position& iPosition) const{
	return _echiquier[iPosition.getY()-1][iPosition.getX()-1];
}

datas::Case& Echiquier::accessCase(const datas::Position& iPosition){
	return _echiquier[iPosition.getY()-1][iPosition.getX()-1];
}

const datas::Move& Echiquier::getLastMove() const{
	return _lastMove;
}

/*
 * passer par un move non constant ?? => pas top niveau conception
 * necessaire pour setter si move est un rock ou priseEnPassant
 * peux pas le faire dans validMove (encore moins bien dans conception)
 */
void Echiquier::doChangeMove(const datas::Move& iMove){
	_possiblePriseEnPassant = false;
	datas::PiecePtr& aPieceMove = this->accessCase(iMove.getStartPosition()).accessPiece();

	if(aPieceMove){
		if(aPieceMove->getTypePiece() == datas::PION_TYPE){
			if(iMove.getStartPosition().diffLigne(iMove.getEndPosition()) == datas::distanceMove(datas::PRISE_EN_PASSANT)){
				_possiblePriseEnPassant = true;
			}
		}
		_lastMove = iMove;
		aPieceMove->movePiece(iMove.getEndPosition());
	}
	else{
		//erreur ou debug
		std::cout << "Echiquier::doChangeMove - incorrecte Move" << std::endl;
	}



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
		setPiece(aPiece, iPositionEnd);
	}
}

void Echiquier::setPiece(datas::PiecePtr& iPiece, const datas::Position& iPosition){
	accessCase(iPosition).setPiece(iPiece);
}

void Echiquier::addPiece(datas::Piece* iPiece){
	datas::PiecePtr aPiecePtr(iPiece);
	addPiece(aPiecePtr);
}

void Echiquier::addPiece(datas::PiecePtr& iPiece){
	if(iPiece->getTypePiece() == datas::ROI_TYPE){
		_joueurs[iPiece->getNumJoueur()]->setKing(iPiece);
	}
	setPiece(iPiece, iPiece->getPosition());
	_hasAlreadyPiece = true;
	//addPiece iPiece in allPiece du joueur
}

void Echiquier::revivePiece(const datas::Position& iPosition){
	//pas excatement => prendre la derniere piece ajoute dans la liste des pieces morte de la case
	//ne peux faire hasPiece => car test _piece && _piece.isAlive... => pour l'instant on garde comme ça.
	if(getCase(iPosition).getPiece()){
		accessCase(iPosition).accessPiece()->setAlive();
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

		typedef std::array<datas::Case, NBRE_LIGNE> typeTab;

		for(typeTab& aValueTab : _echiquier){
			for(datas::Case& aValueCase : aValueTab){
				if(aValueCase.hasPiece()){
					aValueCase.resetPiece();
				}
			}
		}
	}
}

const std::shared_ptr<datas::Joueur> Echiquier::getJoueur(int numJ) const{
	return _joueurs[numJ];
}

/*std::shared_ptr<datas::Joueur> Echiquier::accessJoueur(int numJ) {
	return _joueurs[numJ];
}*/

void Echiquier::setBegginingGameWithoutHandicap(){
	//Pions
	setBegginingGameWithoutHandicapPion();

	//Tours
	setBegginingGameWithoutHandicapTour();

	//Cavaliers
	setBegginingGameWithoutHandicapCavalier();

	//Fou
	setBegginingGameWithoutHandicapFou();

	//Dame
	setBegginingGameWithoutHandicapDame();

	//Roi
	setBegginingGameWithoutHandicapRoi();

	_hasAlreadyPiece = true;
}

void Echiquier::setAutomatiquejoueurs(){
	if(!_joueurs[datas::JOUEUR_1]){
		_joueurs[datas::JOUEUR_1].reset(new datas::JoueurHumain(datas::WHITE));
	}

	if(!_joueurs[datas::JOUEUR_2]){
		_joueurs[datas::JOUEUR_2].reset(new datas::JoueurHumain(datas::BLACK));
	}
}

void Echiquier::setJoueurKing(const datas::PiecePtr iRoiJ1, const datas::PiecePtr iRoiJ2){
	_joueurs[datas::JOUEUR_1]->setKing(iRoiJ1);
	_joueurs[datas::JOUEUR_2]->setKing(iRoiJ2);
}

void Echiquier::setBegginingGameWithoutHandicapRoi(){
	datas::Position aPosition;

	aPosition.setPosition(5, 1);
	datas::Roi *aRoi(new datas::Roi(datas::WHITE, aPosition));
	datas::PiecePtr aRoiWhite(aRoi);

	aPosition.setPosition(5, 8);
	datas::Roi *aRoi2(new datas::Roi(datas::BLACK, aPosition));
	datas::PiecePtr aRoiBlack(aRoi2);

	setJoueurKing(aRoiWhite, aRoiBlack);

	addPiece(aRoiWhite);
	addPiece(aRoiBlack);
}

void Echiquier::setBegginingGameWithoutHandicapDame(){
	datas::Position aPosition;

	aPosition.setPosition(4, 1);
	datas::PiecePtr aDameWhite(new datas::Dame(datas::WHITE, aPosition));
	addPiece(aDameWhite);

	aPosition.setPosition(4, 8);
	datas::PiecePtr aDameBlack(new datas::Dame(datas::BLACK, aPosition));
	addPiece(aDameBlack);
}

void Echiquier::setBegginingGameWithoutHandicapFou(){
	datas::Position aPosition;

	aPosition.setPosition(3, 1);
	datas::PiecePtr aFouWhiteLeft(new datas::Fou(datas::WHITE, aPosition));
	addPiece(aFouWhiteLeft);

	aPosition.setPosition(6, 1);
	datas::PiecePtr aFouWhiteRight(new datas::Fou(datas::WHITE, aPosition));
	addPiece(aFouWhiteRight);

	aPosition.setPosition(3, 8);
	datas::PiecePtr aFouBlackLeft(new datas::Fou(datas::BLACK, aPosition));
	addPiece(aFouBlackLeft);

	aPosition.setPosition(6, 8);
	datas::PiecePtr aFouBlackRight(new datas::Fou(datas::BLACK, aPosition));
	addPiece(aFouBlackRight);
}

void Echiquier::setBegginingGameWithoutHandicapCavalier(){
	datas::Position aPosition;

	aPosition.setPosition(2, 1);
	datas::PiecePtr aCavalierWhiteLeft(new datas::Cavalier(datas::WHITE, aPosition));
	addPiece(aCavalierWhiteLeft);

	aPosition.setPosition(7, 1);
	datas::PiecePtr aCavalierWhiteRight(new datas::Cavalier(datas::WHITE, aPosition));
	addPiece(aCavalierWhiteRight);

	aPosition.setPosition(2, 8);
	datas::PiecePtr aCavalierBlackLeft(new datas::Cavalier(datas::BLACK, aPosition));
	addPiece(aCavalierBlackLeft);

	aPosition.setPosition(7, 8);
	datas::PiecePtr aCavalierBlackRight(new datas::Cavalier(datas::BLACK, aPosition));
	addPiece(aCavalierBlackRight);
}

void Echiquier::setBegginingGameWithoutHandicapTour(){
	datas::Position aPosition;

	aPosition.setPosition(1, 1);
	datas::PiecePtr aTourWhiteLeft(new datas::Tour(datas::WHITE, aPosition));
	addPiece(aTourWhiteLeft);

	aPosition.setPosition(8, 1);
	datas::PiecePtr aTourWhiteRight(new datas::Tour(datas::WHITE, aPosition));
	addPiece(aTourWhiteRight);

	aPosition.setPosition(1, 8);
	datas::PiecePtr aTourBlackLeft(new datas::Tour(datas::BLACK, aPosition));
	addPiece(aTourBlackLeft);

	aPosition.setPosition(8, 8);
	datas::PiecePtr aTourBlackRight(new datas::Tour(datas::BLACK, aPosition));
	addPiece(aTourBlackRight);
}

void Echiquier::setBegginingGameWithoutHandicapPion(){
	datas::Position aPosition;

	for(int i = 1; i<=NBRE_COLONNE; i++){
		aPosition.setPosition(i, 2);
		datas::PiecePtr aPionWhite(new datas::Pion(datas::WHITE, aPosition, true));
		addPiece(aPionWhite);

		aPosition.setPosition(i, 7);
		datas::PiecePtr aPionBlack(new datas::Pion(datas::BLACK, aPosition, false));
		addPiece(aPionBlack);
	}
}

void Echiquier::toStream(std::ostream& os) const{
	os << std::endl << "echiquier : " << std::endl;

	for(int j=NBRE_LIGNE; j>0; --j){
		os << " " << j << "|";
		for(int i=1; i<=NBRE_COLONNE; i++){
			os << " ";
			if(getCase(i, j).hasPiece()){
				os << typePieceToString(getCase(i, j).getPiece()->getTypePiece(), true);
			}
			else{
				os << " ";
			}
			os << " ";
			os << "|";
		}
		os << std::endl;
	}
	os << "  --------------------------------" << std::endl;
	os << "    a   b   c   d   e   f   g   h" << std::endl;
	os << "    1   2   3   4   5   6   7   8" << std::endl;
	os << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Echiquier& iEchiquier){
	iEchiquier.toStream(os);

	return os;
}

} /* namespace game*/


