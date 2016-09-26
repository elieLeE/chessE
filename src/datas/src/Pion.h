/*
 * Pion.h
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#ifndef PION_H_
#define PION_H_

#include "Piece.h"
#include "Move.h"

namespace datas{

class Pion : public Piece{
public:
	Pion(EColor iColor, Position iPosition, bool iSens);
	virtual ~Pion();

	virtual bool isValidatedMove(const game::EtatGame& iEtatGame, const Move& iMove) const;

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
