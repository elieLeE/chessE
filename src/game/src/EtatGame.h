/*
 * EtatGame.h
 *
 *  Created on: 20 sept. 2016
 *      Author: le_e
 */

#ifndef ETATGAME_H_
#define ETATGAME_H_

#include <array>

#include "../../datas/src/Piece.h"
#include "../../datas/src/Types.h"
#include "../../datas/src/Tour.h"
#include "../../datas/src/Position.h"
#include "../../datas/src/Dimension.h"
#include "../../datas/src/Case.h"

namespace game{

class EtatGame {
public:
	virtual ~EtatGame();

	static const EtatGame* getInstance();
	//utile ?? => pour _possiblePriseEnPassant ? => passer par 1 pointeur de booleen ??
	static EtatGame* accessInstance();

	void initEtatGame();

	void movePiece(datas::Position& iPositionStart, datas::Position& iPositionEnd);

	const datas::Case& getCase(int ligne, int col) const;
	datas::Case& accessCase(int ligne, int col);

	const datas::Case& getCase(const datas::Position& iPosition) const;
	datas::Case& accessCase(const datas::Position& iPosition);

	const datas::AllPiece& getAllPiecesJ1() const;
	void setAllPiecesJ1(datas::AllPiece& iAllPieces);

	const datas::AllPiece& getAllPiecesJ2() const;
	void setAllPiecesJ2(datas::AllPiece& iAllPieces);

	const datas::Echiquier& getEchiquier() const;
	void setEchiquier(datas::Echiquier& iEchiquier);

	bool getPossiblePriseEnPassant() const;
	void setPossiblePriseEnPassant(bool iPossiblePriseEnPassant);

	datas::Move& accessLastMove();
	const datas::Move& getLastMove() const;

	void setChangeMove(const datas::Move& iMove);

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

	//std::array<std::array<datas::Case, NBRE_LIGNE>, NBRE_COLONNE> echiquier;
	datas::Echiquier _echiquier;

	bool tourAlreadyMoved[NBRE_TOURS] = {false};

	bool _possiblePriseEnPassant;
	//utiliser enum + pour les deux joueurs
	bool rockPossible;

	datas::AllPiece _allPiecesJ1;
	datas::AllPiece _allPiecesJ2;
	//datas::Plateau _plateau;

	datas::MovePtr _lastMove;

	bool _hasAlreadyPiece;

};

} /* namespace game*/
#endif /* ETATGAME_H_ */
