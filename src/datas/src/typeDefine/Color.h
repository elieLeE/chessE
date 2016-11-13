/*
 * Color.h
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#ifndef COLOR_H_
#define COLOR_H_

#include <ostream>

namespace datas{

typedef enum EColor {
	WHITE,
	BLACK
}EColor;

std::ostream& operator<<(std::ostream& os, const EColor iColor);

}

#endif /* COLOR_H_ */
