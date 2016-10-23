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

class Roi : public Piece{
public:
	Roi(EColor iColor, Position iPosition);
	virtual ~Roi();

	virtual bool isValidateMove(const game::EtatGame& iEtatGame, const Move& iMove) const;
	bool estMoveOKTheorique(const game::EtatGame& iEtatGame, const Move& iMove) const;
	bool estMoveOKPratique(const game::EtatGame& iEtatGame, const Move& iMove) const;
	bool pionPeuxTuerLeRoi(const Position& iposition) const;
	bool cavalierPeuxTuerLeRoi(const Position& iposition) const;
	bool fouPeuxTuerLeRoi(const Position& iposition) const;
	bool tourPeuxTuerLeRoi(const Position& iposition) const;
	bool damePeuxTuerLeRoi(const Position& iposition) const;

	virtual const std::list <boost::shared_ptr <Move> >getPossibleMoves() const ;

private:
	Roi(const Roi&);
	Roi& operator=(const Roi&);
};

}

#endif /* ROI_H_ */
