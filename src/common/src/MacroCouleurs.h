/*
 * MacroCouleurs.h
 *
 *  Created on: 21 janv. 2017
 *      Author: le_e
 */

#ifndef COMMON_SRC_MACROCOULEURS_H_
#define COMMON_SRC_MACROCOULEURS_H_

#define NOIR 30
#define ROUGE 31
#define VERT 32
#define JAUNE 33
#define BLEU 34
#define MAGENTA 35
#define CYAN 36
#define BLANC 37

#define RESET 0

#define CHANGE_COULEUR(n)\
	std::cout << "\033[" << n << "m";\
	\

#define RESET_COLOR CHANGE_COULEUR(RESET)\

#endif /* COMMON_SRC_MACROCOULEURS_H_ */
