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

//#include "../../game/src/EtatGame.h"
#include "TypePiece.h"
#include "Color.h"
#include "Position.h"
#include "Move.h"

namespace game{
class EtatGame;
}

namespace datas{

class Piece {
public:
	Piece(EColor iColor, Position iPosition, ETypePiece iTypePiece, int iValue);
	virtual ~Piece();

	void movePiece(Position& iPosition);

	/*
	 * quand les utilisées ?
	 * si dans nextMove => pas top niveau conception
	 * si apres, dans la fonction appelante => devra etre refait pour IA.
	 * => on passe par newMove => recupere le prochain movement donné par nextMove et
	 * 		newMove ne fait que mettre la piece en etat.
	 */
	void setDead();
	void setAlive();

	/*
	 * use when a new move is played
	 */
	virtual bool isValidatedMove(const game::EtatGame& iEtatGame, const Move& iMove) const = 0;

	//bool firstMoveValidation(Move& iMove);

	/*
	 * needed for IA and display possible move before play
	 */
	//virtual const std::list <boost::shared_ptr <Move> > getPossibleMoves() const = 0;

	EColor getColor() const;

	ETypePiece getTypePiece() const;

	const Position& getPosition() const;
	Position& accessPosition();

	int evaluateDistance(const Move& iMove) const;

protected:
	bool _alive;
	const EColor _color;
	Position _position;

	const int _value;
	const ETypePiece _typePiece;

private:
	Piece(const Piece&);
	Piece& operator=(const Piece&);

};

}
#endif /* PIECES_H_ */
