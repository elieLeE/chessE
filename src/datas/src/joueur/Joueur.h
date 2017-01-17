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

#include "../typeDefine/Types.h"
#include "../piece/Piece.h"
#include "../typeDefine/Color.h"
#include "../typeDefine/TypePlayer.h"
#include "../Move.h"

namespace datas {

class Roi;

class Joueur {
public:
	Joueur(EColor iColor, ETypePlayer iTypePlauer);
	virtual ~Joueur();

	/*
	 * ne prends pas etat de la partie en paramatre => sera recupere via une instance
	 */
	virtual MovePtr nextMove() = 0;

	MovePtr newMove();

	void setKing(const PiecePtr iRoi);
	const std::weak_ptr<Roi> getKing() const;

	int getNbrePts();

	bool hasLost();
	bool kingChessCheck();


private:
	Joueur(const Joueur&);
	Joueur& operator=(const Joueur&);

	//std::vector<boost::shared_ptr<Piece> > _alivePiece;
	std::weak_ptr<Roi> _myKing;

	const EColor _color;
	const ETypePlayer _typePlayer;
	int _points;
};

} /* namespace datas */

#endif /* JOUEUR_H_ */

