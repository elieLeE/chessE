/*
 * Move.h
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#ifndef MOVE_H_
#define MOVE_H_

#include "Position.h"
#include "typeDefine/TypePiece.h"
#include "typeDefine/TypeMove.h"

namespace game{
class Echiquier;
}

namespace datas{

class Move {
public:
	Move();
	Move(const Position& iPositionStart, const Position& iPositionEnd,
			ETypePiece iCapturedPiece = NO_TYPE, ETypeMove iTypeMove = NORMAL_MOVE);
	virtual ~Move();

	void setPositions(const Position& iPositionStart, const Position& iPositionEnd);

	const Position& getStartPosition() const ;
	void setPositionStart(const Position& iPosition);

	const Position& getEndPosition() const ;
	void setPositionEnd(const Position& iPosition);

	bool hasCapturePiece() const;

	int evaluateDistance() const;

	bool isValide(const game::Echiquier& iEchiquier) const;

	ETypePiece getCapturedPiece() const;
	void setCapturedPiece(ETypePiece iCapturedPiece);

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

std::ostream& operator<<(std::ostream& os, const Move& iMove);

}

#endif /* MOVE_H_ */
