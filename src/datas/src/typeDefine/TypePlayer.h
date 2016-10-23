/*
 * TypePlayer.h
 *
 *  Created on: 18 sept. 2016
 *      Author: le_e
 */

#ifndef TYPEPLAYER_H_
#define TYPEPLAYER_H_

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

}

#endif /* TYPEPLAYER_H_ */
