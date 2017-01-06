/*
 * ETypeMove.h
 *
 *  Created on: 23 oct. 2016
 *      Author: le_e
 */

#ifndef ETYPEMOVE_H_
#define ETYPEMOVE_H_

#include <ostream>

namespace datas{

#define POS_X_END_PETIT_ROCK 7
#define POS_X_END_GRAND_ROCK 3

typedef enum ETypeMove{
	NORMAL_MOVE = 0,
	PRISE_EN_PASSANT,
	SIMPLE_CAPTURE_PION,
	SIMPLE_MOVE_PION,
	DOUBLE_MOVE_PION,
	PETIT_ROCK,
	GRAND_ROCK,
	SIMPLE_MOVE_ROI_MAX, 	//en diagonale
	CAVALIER_MOVE,
	INCORRECT_MOVE
}ETypeMove;

int distanceMove(const ETypeMove iTypeMove);

std::ostream& operator<<(std::ostream& os, const ETypeMove iTypeMove);

/*std::ostream& operator<<(std::ostream& os, const ETypeMove iTypeMove){
	os << "test OK";
	return os;
}*/

}

#endif /* ETYPEMOVE_H_ */
