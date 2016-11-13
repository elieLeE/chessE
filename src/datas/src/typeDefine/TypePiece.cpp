/*
 * TypePiece.cpp
 *
 *  Created on: 12 nov. 2016
 *      Author: le_e
 */

#include "TypePiece.h"

namespace datas {

std::ostream& operator<<(std::ostream& os, const ETypePiece iTypePiece){
	switch(iTypePiece){
	case PION_TYPE:
		os << "Pion";
		break;

	case CAVALIER_TYPE:
		os << "Cavalier";
		break;

	case FOU_TYPE:
		os << "Fou";
		break;

	case TOUR_TYPE:
		os << "Tour";
		break;

	case DAME_TYPE:
		os << "Dame";
		break;

	case ROI_TYPE:
		os << "Roi";
		break;

	case NO_TYPE:
		os << "No";
		break;
	}
	return os;
}

}




