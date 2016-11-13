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

typedef enum ETypeMove{
	NORMAL_MOVE = 0,
	PRISE_EN_PASSANT = 2,
	PETIT_ROCK = 4,
	GRAND_ROCK = 9,
	INCORRECT_MOVE
}ETypeMove;

std::ostream& operator<<(std::ostream& os, const ETypeMove iTypeMove);

/*std::ostream& operator<<(std::ostream& os, const ETypeMove iTypeMove){
	os << "test OK";
	return os;
}*/

}

#endif /* ETYPEMOVE_H_ */
