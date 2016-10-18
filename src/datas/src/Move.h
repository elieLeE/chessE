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

namespace datas{

class Move {
public:
	Move(Position& iPositionStart, Position& iPositionEnd,
			ETypePiece iCapturedPiece = NO_TYPE, bool iPriseEnPassant = false);
	virtual ~Move();

	const Position& getStartPosition() const ;

	const Position& getEndPosition() const ;

	bool hasCapturePiece() const;

	int evaluateDistance() const;

	bool getPriseEnPassant() const;
	void setPriseEnPassant(bool iBool);


private:
	Position _start;
	Position _end;
	//necessaire pour la prise en passant => meme si peux retrouver a partir de la position finale et d'un booleen
	//les autres prises sont forcements a la position finale
	//Position _capturedPiecePosition;

	bool _priseEnPassant;
	const ETypePiece _capturedPiece;

};

}

#endif /* MOVE_H_ */
