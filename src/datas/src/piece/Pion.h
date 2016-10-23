/*
 * Pion.h
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#ifndef PION_H_
#define PION_H_

#include "Piece.h"
#include "../Move.h"

namespace datas{

class Pion : public Piece{
public:
	Pion(const EColor iColor, Position iPosition, const bool iSens);
	virtual ~Pion();

	virtual bool isValidateMove(const game::EtatGame& iEtatGame, const Move& iMove) const;

	//virtual const std::list <boost::shared_ptr <Move> > getPossibleMoves() const;

private:
	bool _hasAlreadyMoved;
	/*
	 * les pions ont un sens de deplacement different selon leurs couleurs
	 * => sens croissant : le nombre de la position du pion augmente celui se deplace
	 */
	bool _sensCroissant;
};

}

#endif /* PION_H_ */