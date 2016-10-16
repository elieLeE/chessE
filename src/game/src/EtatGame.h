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

	const datas::AlivePiecePtr& getAlivePiecesJ1() const;
	void setAlivePiecesJ1(datas::AlivePiecePtr& iAllivePieces);

	const datas::AlivePiecePtr& getAlivePiecesJ2() const;
	void setAlivePiecesJ2(datas::AlivePiecePtr& iAllivePieces);

	const datas::PlateauPtr& getPlateau() const;
	void setPlateau(datas::PlateauPtr& iPlateau);

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

	datas::AlivePiecePtr _alivePiecesJ1;
	datas::AlivePiecePtr _alivePiecesJ2;
	datas::PlateauPtr _plateau;



	datas::MovePtr lastMove;

};

} /* namespace game*/
#endif /* ETATGAME_H_ */
