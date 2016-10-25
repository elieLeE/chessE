/*
 * Roi.h
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#ifndef ROI_H_
#define ROI_H_

#include "Piece.h"
#include "../Move.h"

namespace datas{

class Tour;

class Roi : public Piece{
public:
	Roi(EColor iColor, Position iPosition);
	virtual ~Roi();

	virtual bool isValideMove(const Move& iMove) const;

	virtual void movePiece(const Position& iPosition);

	bool estMoveOKTheorique(const Move& iMove) const;
	bool estMoveOKPratique(const Move& iMove) const;
	bool pionPeuxTuerLeRoi(const Position& iPositionFinaleMove, const Position& iPositionPion) const;
	bool cavalierPeuxTuerLeRoi(const Position& iPositionFinaleMove, const Position& iPositionCavalier) const;
	bool fouPeuxTuerLeRoi(const Position& iPositionFinaleMove, const Position& iPositionFou) const;
	bool tourPeuxTuerLeRoi(const Position& iPositionFinaleMove, const Position& iPositionTour) const;
	bool damePeuxTuerLeRoi(const Position& iPositionFinaleMove, const Position& iPositionDame) const;
	bool secondRoiColle(const Position& iPositionFinaleMove, const Position& iPositionRoi) const;

	virtual const std::list <boost::shared_ptr <Move> >getPossibleMoves() const ;

private:
	bool _hasAlreadyMoved;
};

}

#endif /* ROI_H_ */
