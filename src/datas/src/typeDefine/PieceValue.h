/*
 * PieceValue.h
 *
 *  Created on: 18 sept. 2016
 *      Author: le_e
 */

#ifndef PIECEVALUE_H_
#define PIECEVALUE_H_

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

#define INIT_TOTAL_POINTS (ROI_VALUE + DAME_VALUE + 2*TOUR_VALUE + 2*FOU_VALUE + 2*CAVALIER_VALUE + 10*PION_VALUE)

#define NBRE_PIECE_INIT 18

}

#endif /* PIECEVALUE_H_ */
