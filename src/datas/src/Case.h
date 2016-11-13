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

	const PiecePtr& getPiece() const;
	PiecePtr& accessPiece();

	void setPiece(PiecePtr& iPiece);
	void resetPiece();

private:
	PiecePtr _piece;
	//add liste de piede morte capture dans cette case => pour les retour en arrieres)
	// A etudiier !
};

} /* namespace datas */
#endif /* CASE_H_ */
