/*
 * Pion.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Pion.h"
#include "../typeDefine/TypePiece.h"
#include "../typeDefine/PieceValue.h"
#include "../../../game/src/Echiquier.h"
#include "../typeDefine/Types.h"

namespace datas{

Pion::Pion(const EColor iColor, Position iPosition, const bool iSens):
		Piece(iColor, iPosition, PION_TYPE, PION_VALUE),
		_hasAlreadyMoved(false),
		_sensCroissant(iSens)
{}

Pion::~Pion()
{}

bool Pion::isValideMove(const Move& iMove) const{
	bool aBool = false;

	//aBool = (Piece*)this->isValidateMove(iEchiquier, iMove);

	if(((Piece*)this)->isValideMove(iMove)){
		/*
		 * verifier que la position finale du movement est accessible a partir
		 * de la position courante de la piece et de son type.
		 * verifier egalement qu'une autre piece de la meme couleur n'y est pas deja
		 * */
		const game::Echiquier& aEchiquier = game::Echiquier::getInstance();
		//PiecePtr aPiece = aPlateau->at(iMove.getEndPosition().getX()).at(iMove.getEndPosition().getY());
		const PiecePtr& aPiece = aEchiquier.getCase(iMove.getEndPosition()).getPiece();
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
		else if(!_hasAlreadyMoved && aEchiquier.getPossiblePriseEnPassant()){
			//a gauche
			//PieceCSPtr aSecondPiece = aPlateau->at(_position.getX()-1).at(_position.getY());
			//boost::shared_ptr<Piece> aSecondPiece = aPlateau->at(_position.getX()-1).at(_position.getY());
			const PiecePtr& aSecondPiece = aEchiquier.getCase(_position.getX()-1, _position.getY()).getPiece();
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
				const PiecePtr& aSecondPiece2 = aEchiquier.getCase(_position.getX()+1, _position.getY()).getPiece();
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
