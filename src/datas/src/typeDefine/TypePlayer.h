/*
 * TypePlayer.h
 *
 *  Created on: 18 sept. 2016
 *      Author: le_e
 */

#ifndef TYPEPLAYER_H_
#define TYPEPLAYER_H_

#include <ostream>

namespace datas{

#define NBRE_JOUEURS 2

typedef enum ETypePlayer{
	HUMAN_PLAYER,
	IA_PlAYER
}ETypePlayer;

//JOUEUR 1 = 0 !!
typedef enum ENumPlayer{
	JOUEUR_1 = 0,
	JOUEUR_2
}ENumPlayer;

std::ostream& operator<<(std::ostream& os, const ETypePlayer iTypePlayer);
std::ostream& operator<<(std::ostream& os, const ENumPlayer iNumPlayer);

}

#endif /* TYPEPLAYER_H_ */
