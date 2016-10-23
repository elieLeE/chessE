/*
 * Move.h
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#ifndef MOVE_H_
#define MOVE_H_

#include "Position.h"
#include "TypePiece.h"
#include "TypeMove.h"

namespace game{
class EtatGame;
}

namespace datas{

class Move {
public:
	Move();
	Move(Position& iPositionStart, Position& iPositionEnd,
			ETypePiece iCapturedPiece = NO_TYPE, ETypeMove iTypeMove = NORMALLY_MOVE);
	virtual ~Move();

	const Position& getStartPosition() const ;
	const Position& getEndPosition() const ;

	bool hasCapturePiece() const;

	int evaluateDistance() const;

	bool getPriseEnPassant() const;
	void setPriseEnPassant(bool iBool);

	bool isValidateMove(const game::EtatGame& iEtatGame) const;

	ETypePiece getHasCapturedPiece() const;
	void setHasCapturedPiece(ETypePiece iCapturedPiece);

	ETypeMove getTypeMove() const;
	void setTypeMove(ETypeMove iTypeMove);

	void operator=(const Move& iMove);

	void setMoveProperties();

	//add prise en passant and remove bool priseEnPAssant

private:
	Position _start;
	Position _end;
	//necessaire pour la prise en passant => meme si peux retrouver a partir de la position finale et d'un booleen
	//les autres prises sont forcements a la position finale
	//Position _capturedPiecePosition;

	ETypePiece _capturedPiece;
	ETypeMove _typeMove;
};

}

#endif /* MOVE_H_ */
