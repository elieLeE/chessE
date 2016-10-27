/*
 * ETypeMove.h
 *
 *  Created on: 23 oct. 2016
 *      Author: le_e
 */

#ifndef ETYPEMOVE_H_
#define ETYPEMOVE_H_

namespace datas{

typedef enum ETypeMove{
	NORMAL_MOVE = 0,
	PRISE_EN_PASSANT,
	PETIT_ROCK = 4,
	GRAND_ROCK = 9,
	INCORRECT_MOVE
}ETypeMove;

}

#endif /* ETYPEMOVE_H_ */
