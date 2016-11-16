/*
 * TypePiece.cpp
 *
 *  Created on: 12 nov. 2016
 *      Author: le_e
 */

#include "TypePiece.h"

namespace datas {

std::string typePieceToString(const ETypePiece iTypePiece, const bool oneLetter){
	std::string aStr;
	switch(iTypePiece){
	case datas::ROI_TYPE:
		aStr.assign(oneLetter?"R":"Roi");
		break;
	case datas::DAME_TYPE:
		aStr.assign(oneLetter?"D":"Dame");
		break;

	case datas::TOUR_TYPE:
		aStr.assign(oneLetter?"T":"Tour");
		break;

	case datas::CAVALIER_TYPE:
		aStr.assign(oneLetter?"C":"Cavalier");
		break;

	case datas::FOU_TYPE:
		aStr.assign(oneLetter?"F":"Fou");
		break;

	case datas::PION_TYPE:
		aStr.assign(oneLetter?"P":"Pion");
		break;

	case datas::NO_TYPE:
		aStr.assign(oneLetter?" ":"No Type");
		break;
	}
	return aStr;
}

}




