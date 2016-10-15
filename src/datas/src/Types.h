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

	typedef boost::shared_ptr<Move> MoveCSPtr;

	typedef boost::shared_ptr<datas::Piece> PieceCSPtr;

	typedef std::vector<PieceCSPtr> AlivePiece;
	typedef boost::shared_ptr<AlivePiece> AlivePieceCSPtr;

	typedef std::vector<std::vector<PieceCSPtr> > Plateau;
	typedef boost::shared_ptr<Plateau> PlateauCSPtr;
}

#endif /* TYPES_H_ */
