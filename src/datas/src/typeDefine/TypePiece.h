/*
 * ETypePiece.h
 *
 *  Created on: 18 sept. 2016
 *      Author: le_e
 */

#ifndef ETYPEPIECE_H_
#define ETYPEPIECE_H_

#include <ostream>

namespace datas{

typedef enum ETypePiece{
	PION_TYPE,
	CAVALIER_TYPE,
	FOU_TYPE,
	TOUR_TYPE,
	DAME_TYPE,
	ROI_TYPE,
	NO_TYPE
}ETypePiece;

std::string typePieceToString(const ETypePiece iTypePiece, const bool oneLetter);

void test();

}


#endif /* ETYPEPIECE_H_ */
