/*
 * Case.h
 *
 *  Created on: 22 oct. 2016
 *      Author: le_e
 */

#ifndef CASE_H_
#define CASE_H_

#include "typeDefine/Types.h"
#include "piece/Piece.h"

namespace datas {

class Case {
public:
	Case();
	virtual ~Case();

	bool hasPiece() const;

	const Piece& getPiece() const;
	Piece& accessPiece();

	void setPiece(Piece* iPiece);
	void resetPiece();

private:
	PiecePtr _piece;
};

} /* namespace datas */
#endif /* CASE_H_ */
