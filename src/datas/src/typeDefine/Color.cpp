/*
 * Color.cpp
 *
 *  Created on: 12 nov. 2016
 *      Author: le_e
 */

#include "Color.h"

namespace datas{

std::ostream& operator<<(std::ostream& os, const EColor iColor){
	switch(iColor){
	case WHITE:
		os << "WHITE";
		break;

	case BLACK:
		os << "BLACK";
		break;
	}
	return os;
}

}

