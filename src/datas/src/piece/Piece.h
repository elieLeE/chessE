/*
 * Pieces.h
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#ifndef PIECE_H_
#define PIECE_H_

#include <list>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <math.h>

#include "../typeDefine/TypePiece.h"
#include "../typeDefine/Color.h"
#include "../Position.h"
#include "../Move.h"
#include "../typeDefine/TypePlayer.h"

namespace game{
class Echiquier;
}

namespace datas{

class Piece {
public:
	Piece(const EColor iColor, Position iPosition, ETypePiece iTypePiece, const int iValue);
	virtual ~Piece();

	virtual void movePiece(const Position& iPosition);

	/*
	 * quand les utilisées ?
	 * si dans nextMove => pas top niveau conception
	 * si apres, dans la fonction appelante => devra etre refait pour IA.
	 * => on passe par newMove => recupere le prochain movement donné par nextMove et
	 * 		newMove ne fait que mettre la piece en etat.
	 */
	void setDead();
	void setAlive();
	bool isAlive() const;

	/*
	 * use when a new move is played
	 */
	//virtual bool isValideMove(const game::Echiquier& iEchiquier, const Move& iMove) const = 0;
	virtual bool isValideMove(const Move& iMove) const;
	virtual bool canAccessCase(const Position& iPosition) const = 0;
	bool canTakeCase(const Position& iPosition) const;

	//bool firstMoveValidation(Move& iMove);

	/*
	 * needed for IA and display possible move before play
	 */
	//virtual const std::list <boost::shared_ptr <Move> > getPossibleMoves() const = 0;

	EColor getColor() const;

	ETypePiece getTypePiece() const;

	int getNumJoueur() const;

	const Position& getPosition() const;
	Position& accessPosition();

protected:
	bool _alive;
	const EColor _color;
	Position _position;
	const ENumPlayer _numJ;
	const int _value;
	const ETypePiece _typePiece;

private:
	Piece(const Piece&);
	Piece& operator=(const Piece&);

};

}
#endif /* PIECES_H_ */
