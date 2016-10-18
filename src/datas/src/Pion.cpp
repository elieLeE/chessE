/*
 * Pion.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Pion.h"
#include "TypePiece.h"
#include "PieceValue.h"
#include "../../game/src/EtatGame.h"
#include "Types.h"

namespace datas{

Pion::Pion(EColor iColor, Position iPosition, bool iSens):
		Piece(iColor, iPosition, PION_TYPE, PION_VALUE),
		_hasAlreadyMoved(false),
		_sensCroissant(iSens)
{}

Pion::~Pion()
{}

bool Pion::isValidatedMove(const game::EtatGame& iEtatGame, const Move& iMove) const{
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
		std::cout << "position finale du mouvement correspond a la position initiale" << std::endl;
	}

	else {
		/*
		 * verifier que la position finale du movement est accessible a partir
		 * de la position courante de la piece et de son type.
		 * verifier egalement qu'une autre piece de la meme couleur n'y est pas deja
		 * */
		Plateau aPlateau = iEtatGame.getPlateau();
		//PiecePtr aPiece = aPlateau->at(iMove.getEndPosition().getX()).at(iMove.getEndPosition().getY());
		PiecePtr aPiece = iEtatGame.getPiece(iMove.getEndPosition());
		//boost::shared_ptr<Piece> aPiece = aPlateau->at(iMove.getEndPosition().getX()).at(iMove.getEndPosition().getY());
		int moreOrLess = _sensCroissant?1:-1;

		//n'a pas encore bouge
		if((!_hasAlreadyMoved) && (iMove.getEndPosition().getX()==_position.getX()) &&
				((iMove.getEndPosition().getY() == _position.getY()+moreOrLess) || (iMove.getEndPosition().getY() == _position.getY()+moreOrLess*2))){
			if(aPiece && (aPiece->getColor() == this->getColor())){
				//retourne une exception
			}
			else{
				//mouvement OK
				aBool = true;
			}
		}
		//avance d'une case
		else if((iMove.getEndPosition().getX()==_position.getX()) && (iMove.getEndPosition().getY() == _position.getY()+moreOrLess)){
			if(aPiece && (aPiece->getColor() == this->getColor())){
				//retourne une exception
			}
			else{
				//mouvement OK
				aBool = true;
			}
		}

		//prise a droite
		else if((iMove.getEndPosition().getX()==_position.getX()+1) && (iMove.getEndPosition().getY() == _position.getY())){
			if(aPiece && (aPiece->getColor() != this->getColor())){
				//mouvement OK
				aBool = true;
			}
			else{
				//retourne une exception
			}
		}

		//prise a gauche
		else if((iMove.getEndPosition().getX()==_position.getX()-1) && (iMove.getEndPosition().getY() == _position.getY())){
			if(aPiece && (aPiece->getColor() != this->getColor())){
				//mouvement OK
				aBool = true;
			}
			else{
				//retourne une exception
			}
		}

		//prise en passant
		else if(!_hasAlreadyMoved && iEtatGame.getPossiblePriseEnPassant()){
			//a gauche
			//PieceCSPtr aSecondPiece = aPlateau->at(_position.getX()-1).at(_position.getY());
			//boost::shared_ptr<Piece> aSecondPiece = aPlateau->at(_position.getX()-1).at(_position.getY());
			PiecePtr aSecondPiece = iEtatGame.getPiece(_position.getX()-1, _position.getY());
			if(aSecondPiece && (aSecondPiece->getTypePiece() == PION_TYPE) && (aSecondPiece->getColor() != getColor()) &&
					((iMove.getEndPosition().getX()==_position.getX()-1) && (iMove.getEndPosition().getY() == _position.getY()+moreOrLess))){
				//il ne doit y avoir aucune piece car le mouvement de l'autre joueur avec le pion doit etre celui juste avant
				if(!aPiece){
					//mouvement OK
					aBool = true;
				}
				else{
					//retourne une exception
				}
			}
			//a droite
			else {
				//aSecondPiece = aPlateau->at(_position.getX()+1).at(_position.getY());
				aSecondPiece = iEtatGame.getPiece(_position.getX()+1, _position.getY());
				if(aSecondPiece && (aSecondPiece->getTypePiece()==PION_TYPE) && (aSecondPiece->getColor() != getColor()) &&
						((iMove.getEndPosition().getX()==_position.getX()+1) && (iMove.getEndPosition().getY() == _position.getY()+moreOrLess))){
					if(!aPiece){
						//mouvement OK
						aBool = true;
					}
					else{
						//retourne une exception
					}
				}
			}
		}
	}

	return aBool;
}

/*const std::list <boost::shared_ptr <Move> > Pion::getPossibleMoves() const{
	std::list <boost::shared_ptr <Move> > aList;

	return aList;
}*/

}
