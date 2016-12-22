/*
 * TypeMove.cpp
 *
 *  Created on: 12 nov. 2016
 *      Author: le_e
 */

#include "TypeMove.h"

namespace datas {

int distanceMove(const ETypeMove iTypeMove){
	int dist = 0;

	switch(iTypeMove){
	case NORMAL_MOVE:
		break;

	case INCORRECT_MOVE:
		dist = -1;
		break;

	case SIMPLE_MOVE_PION:
		dist = 1;
		break;

	case PRISE_EN_PASSANT:
	case SIMPLE_CAPTURE_PION:
		dist = 2;
		break;

	case PETIT_ROCK:
	case DOUBLE_MOVE_PION:
		dist = 4;
		break;

	case CAVALIER_MOVE:
		dist = 5;
		break;

	case GRAND_ROCK:
		dist = 9;
		break;
	}

	return dist;
}

std::ostream& operator<<(std::ostream& os, const ETypeMove iTypeMove){
	switch(iTypeMove){
	case NORMAL_MOVE:
	case SIMPLE_MOVE_PION:
	case SIMPLE_CAPTURE_PION:
	case DOUBLE_MOVE_PION:
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

