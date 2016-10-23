/*
 * Fichier.h
 *
 *  Created on: 15 oct. 2016
 *      Author: le_e
 */

#ifndef FICHIER_H_
#define FICHIER_H_

#include <string>
#include <fstream>

#include "typeDefine/TypePiece.h"
#include "typeDefine/TypePlayer.h"
#include "Move.h"

namespace datas {

class Fichier {
public:
	Fichier(std::string s);
	virtual ~Fichier();

	bool lecturePosition(ENumPlayer *oNumPlayer, ETypePiece *oTypePiece, int *oPosX, int *oPosY);
	bool lectureMove(Move & oMove);

private:
	std::fstream FILE;
};

} /* namespace datas */
#endif /* FICHIER_H_ */
