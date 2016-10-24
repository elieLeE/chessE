/*
 * Partie.h
 *
 *  Created on: 20 sept. 2016
 *      Author: le_e
 */

#ifndef PARTIE_H_
#define PARTIE_H_

#include <boost/shared_ptr.hpp>
#include <array>

#include "Move.h"
#include "typeDefine/Types.h"
#include "typeDefine/TypePlayer.h"

namespace datas {

#define NBRE_COUP_MIN 5

class Partie {
public:
	Partie();
	virtual ~Partie();

	const std::vector<boost::shared_ptr<Move> >& getAllMoves() const;

	void addMove(Move &iMove, ENumPlayer iNumPlayer);

private:
	Partie(const Partie&);
	Partie& operator=(const Partie&);

	std::array<std::array <MovePtr, NBRE_COUP_MIN>, NBRE_JOUEURS> _moves;

};

} /* namespace datas */
#endif /* PARTIE_H_ */
