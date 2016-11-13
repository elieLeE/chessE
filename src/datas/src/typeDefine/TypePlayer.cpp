/*
 * TypePlayer.cpp
 *
 *  Created on: 12 nov. 2016
 *      Author: le_e
 */

#include "TypePlayer.h"

namespace datas{

std::ostream& operator<<(std::ostream& os, const ETypePlayer iTypePlayer){
	switch(iTypePlayer){
	case IA_PlAYER:
		os << "IA";
		break;

	case HUMAN_PLAYER:
		os << "HUMAN";
		break;
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const ENumPlayer iNumPlayer){
	switch(iNumPlayer){
	case JOUEUR_1:
		os << "JOUEUR_1";
		break;

	case JOUEUR_2:
		os << "JOUEUR_2";
		break;
	}
	return os;
}

}
