/*
 * EtatGame.h
 *
 *  Created on: 20 sept. 2016
 *      Author: le_e
 */

#ifndef ETATGAME_H_
#define ETATGAME_H_

#include <vector>

#include "../../datas/src/Piece.h"
#include "../../datas/src/Types.h"

namespace game{

class EtatGame {
public:
	virtual ~EtatGame();

	static const EtatGame* getInstance();
	//utile ?? => pour _possiblePriseEnPassant ? => passer par 1 pointeur de booleen ??
	static EtatGame* accessInstance();

	const AlivePieceCSPtr& getAlivePiecesJ1() const;
	void setAlivePiecesJ1(AlivePieceCSPtr& iAllivePieces);

	const AlivePieceCSPtr& getAlivePiecesJ2() const;
	void setAlivePiecesJ2(AlivePieceCSPtr& iAllivePieces);

	const PlateauCSPtr& getPlateau() const;
	void setPlateau(PlateauCSPtr& iPlateau);

	bool getPossiblePriseEnPassant() const;
	void setPossiblePriseEnPassant(bool iPossiblePriseEnPassant);

	//supprime toutes les pieces
	void reset();

	void setByFile(FILE* f);
	void resetByFile(FILE* f);
	void setBegginingGameWithoutHandicap();


private:
	EtatGame();
	EtatGame(const EtatGame&);
	EtatGame& operator=(const EtatGame&);

	static EtatGame* _instance;

	bool _possiblePriseEnPassant;

	AlivePieceCSPtr _alivePiecesJ1;
	AlivePieceCSPtr _alivePiecesJ2;
	PlateauCSPtr _plateau;

};

} /* namespace game*/
#endif /* ETATGAME_H_ */
