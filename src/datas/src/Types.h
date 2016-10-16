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

namespace datas{
	class Piece;
	class Move;

	typedef boost::shared_ptr<Move> MovePtr;

	typedef boost::shared_ptr<datas::Piece> PiecePtr;

	typedef std::vector<PiecePtr> AlivePiece;
	typedef boost::shared_ptr<AlivePiece> AlivePiecePtr;

	typedef std::vector<std::vector<PiecePtr> > Plateau;
	typedef boost::shared_ptr<Plateau> PlateauPtr;
}

#endif /* TYPES_H_ */
