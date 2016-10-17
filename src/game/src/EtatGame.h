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

	void initEtatGame();

	const datas::PiecePtr& getPiece(int ligne, int col) const;
	datas::PiecePtr& accessPiece(int ligne, int col);

	const datas::AllPiece& getAllPiecesJ1() const;
	void setAllPiecesJ1(datas::AllPiece& iAllPieces);

	const datas::AllPiece& getAllPiecesJ2() const;
	void setAllPiecesJ2(datas::AllPiece& iAllPieces);

	const datas::Plateau& getPlateau() const;
	void setPlateau(datas::Plateau& iPlateau);

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

	datas::AllPiece _allPiecesJ1;
	datas::AllPiece _allPiecesJ2;
	datas::Plateau _plateau;



	datas::MovePtr lastMove;

};

} /* namespace game*/
#endif /* ETATGAME_H_ */
