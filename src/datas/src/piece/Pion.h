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

	virtual bool isValideMove(const Move& iMove) const;
	bool isSimpleMove(const Position& iPosition, const game::Echiquier& iEchiquier) const;
	bool isSimpleCapture(const Position& iPosition, const game::Echiquier& iEchiquier) const;
	bool isPassantCapture(const Position& iPosition, const game::Echiquier& iEchiquier) const;
	bool verifSensMove(const Position& iPosition) const;

	virtual void movePiece(const Position& iPosition);

	virtual bool canKillCasePiece(const Position& iPosition) const;
	virtual bool canAccessCase(const Position& iPosition) const;

	bool hasAlreadyMoved(void) const;
	bool getSensCroissant(void) const;

	//virtual const std::list <boost::shared_ptr <Move> > getPossibleMoves() const;

	void toStream(std::ostream& os) const;

private:
	bool _hasAlreadyMoved;
	/*
	 * les pions ont un sens de deplacement different selon leurs couleurs
	 * => sens croissant : le nombre de la position du pion augmente celui se deplace
	 */
	bool _sensCroissant;
};

std::ostream& operator<<(std::ostream& os, const Pion& iPion);

}

#endif /* PION_H_ */
