/*
 * JoueurHumain.h
 *
 *  Created on: 20 sept. 2016
 *      Author: le_e
 */

#ifndef JOUEURHUMAIN_H_
#define JOUEURHUMAIN_H_

#include "Joueur.h"

namespace datas {

class JoueurHumain : public Joueur
{
public:
	JoueurHumain(EColor iColor, ETypePlayer iTypePlayer);
	virtual ~JoueurHumain();

	virtual MovePtr nextMove();

private:
	JoueurHumain(const JoueurHumain&);
	JoueurHumain& operator=(const JoueurHumain&);
};

} /* namespace datas */
#endif /* JOUEURHUMAIN_H_ */
