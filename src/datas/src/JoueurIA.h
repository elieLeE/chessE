/*
 * JoueurIA.h
 *
 *  Created on: 20 sept. 2016
 *      Author: le_e
 */

#ifndef JOUEURIA_H_
#define JOUEURIA_H_

#include "Joueur.h"

namespace datas {

class JoueurIA : public Joueur
{
public:
	JoueurIA(EColor iColor, ETypePlayer iTypePlayer);
	virtual ~JoueurIA();

	virtual MoveCSPtr nextMove();

private:
	JoueurIA(const JoueurIA&);
	JoueurIA& operator=(const JoueurIA&);
};

} /* namespace datas */
#endif /* JOUEURIA_H_ */
