/*
 * Types.h
 *
 *  Created on: 25 sept. 2016
 *      Author: le_e
 */

#ifndef TYPES_H_
#define TYPES_H_

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <array>
#include "Dimension.h"
#include "PieceValue.h"

namespace datas{
	class Piece;
	class Move;
	class Case;

	typedef boost::shared_ptr<Move> MovePtr;

	typedef boost::shared_ptr<datas::Piece> PiecePtr;

	typedef std::array<PiecePtr, NBRE_PIECE_INIT> AllPiecePtr;

	typedef std::array<std::array<datas::Case, NBRE_LIGNE>, NBRE_COLONNE> Echiquier;
}

#endif /* TYPES_H_ */
