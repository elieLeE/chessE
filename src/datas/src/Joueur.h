/*
 * Joueur.h
 *
 *  Created on: 18 sept. 2016
 *      Author: le_e
 */

#ifndef JOUEUR_H_
#define JOUEUR_H_

#include <boost/shared_ptr.hpp>
#include <vector>

#include "Piece.h"
#include "Color.h"
#include "TypePlayer.h"
#include "Move.h"
#include "Types.h"

namespace datas {

class Joueur {
public:
	Joueur(EColor iColor, ETypePlayer iTypePlauer);
	virtual ~Joueur();

	/*
	 * ne prends pas etat de la partie en paramatre => sera recupere via une instance
	 */
	virtual MovePtr nextMove() = 0;

	MovePtr newMove();


private:
	Joueur(const Joueur&);
	Joueur& operator=(const Joueur&);

	std::vector<boost::shared_ptr<Piece> > _alivePiece;
	const EColor _color;
	const ETypePlayer _typePlayer;
	int _points;
};

} /* namespace datas */
#endif /* JOUEUR_H_ */
