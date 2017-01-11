/*
 * PieceValue.h
 *
 *  Created on: 18 sept. 2016
 *      Author: le_e
 */

#ifndef PIECEVALUE_H_
#define PIECEVALUE_H_

#include "NbrePiece.h"

namespace datas{

/*
 * obligatoire car cavalier et fou ont la meme valeur => ne peux pas passer par un un enum => meme valeur
 * mais piece differentes ==> mouvements differents...
 */
#define ROI_VALUE 100
#define DAME_VALUE 9
#define TOUR_VALUE 5
#define CAVALIER_VALUE 3
#define FOU_VALUE 3
#define PION_VALUE 1

#define INIT_TOTAL_POINTS (ROI_VALUE * NBRE_ROI + DAME_VALUE * NBRE_DAME + NBRE_TOUR * TOUR_VALUE +\
NBRE_FOU * FOU_VALUE + NBRE_CAVALIER * CAVALIER_VALUE + NBRE_PION * PION_VALUE )

#define NBRE_PIECE_INIT 18

}

#endif /* PIECEVALUE_H_ */
