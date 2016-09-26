/*
 * Partie.h
 *
 *  Created on: 20 sept. 2016
 *      Author: le_e
 */

#ifndef PARTIE_H_
#define PARTIE_H_

#include <boost/shared_ptr.hpp>
#include <vector>

#include "Move.h"
#include "Types.h"

namespace datas {

class Partie {
public:
	Partie();
	virtual ~Partie();

	const std::vector<boost::shared_ptr<Move> >& getAllMoves() const;

	void addMove(Move &iMove);

private:
	Partie(const Partie&);
	Partie& operator=(const Partie&);

	std::vector <MoveCSPtr >_moves;

};

} /* namespace datas */
#endif /* PARTIE_H_ */
