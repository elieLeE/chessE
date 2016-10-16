/*
 * ColorDisplay.h
 *
 *  Created on: 16 oct. 2016
 *      Author: le_e
 */

#ifndef COLORDISPLAY_H_
#define COLORDISPLAY_H_

#include <iostream>

namespace gui{

#define COLOR_PREFIX "\033["
#define COLOR_SUFFIX "m"

typedef enum ColorDisplay{
	FG_RED      = 31
	/*FG_RED      = "\033[31",
	FG_GREEN    = "\033[32",
	FG_BLUE     = "\033[34",
	FG_DEFAULT  = "\033[39",

	BG_RED      = "\033[41",
	BG_GREEN    = "\033[42",
	BG_BLUE     = "\033[44",
	BG_DEFAULT  = "\033[49"*/
}ColorDisplay;

}

#endif /* COLORDISPLAY_H_ */
