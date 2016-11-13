/*
 * TypeMove.cpp
 *
 *  Created on: 12 nov. 2016
 *      Author: le_e
 */

#include "TypeMove.h"

namespace datas {

std::ostream& operator<<(std::ostream& os, const ETypeMove iTypeMove){
	switch(iTypeMove){
	case NORMAL_MOVE:
		os << "NORMAL_MOVE";
		break;

	case PRISE_EN_PASSANT:
		os << "PRISE_EN_PASSANT";
		break;

	case PETIT_ROCK:
		os << "PETIT_ROCK";
		break;

	case GRAND_ROCK:
		os << "GRAND_ROCK";
		break;

	case INCORRECT_MOVE:
		os << "INCORRECT_MOVE";
		break;
	}
	return os;
}

}

