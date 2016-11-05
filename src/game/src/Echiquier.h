/*
 * Echiquier.h
 *
 *  Created on: 20 sept. 2016
 *      Author: le_e
 */

#ifndef Echiquier_H_
#define Echiquier_H_

#include <array>

#include "../../datas/src/piece/Piece.h"
#include "../../datas/src/typeDefine/Types.h"
#include "../../datas/src/piece/Tour.h"
#include "../../datas/src/Position.h"
#include "../../datas/src/typeDefine/Dimension.h"
#include "../../datas/src/Case.h"
#include "../../datas/src/Move.h"
#include "../../datas/src/typeDefine/TypePlayer.h"

namespace game{

class Echiquier{
public:
	virtual ~Echiquier();

	static const Echiquier& getInstance();
	//utile ?? => pour _possiblePriseEnPassant ? => passer par 1 pointeur de booleen ??
	static Echiquier& accessInstance();

	void initEchiquier();

	void movePiece(const datas::Position& iPositionStart, const datas::Position& iPositionEnd);

	//a etudier mais a priori pas une bonne chose => serait 1 pb de conception
	/*const datas::PiecePtr& getPieceCaseXY(datas::Position& iPosition) const;
	datas::PiecePtr& accessPieceCaseXY(datas::Position& iPosition);
	bool hasPieceCaseXY(datas::Position& iPosition) const;*/

	//indispensable car sinon, ne sait pas si a deja des pieces ou pas
	void addPiece(datas::Piece* iPiece);
	void addPiece(datas::PiecePtr& iPiece);
	void setPiece(datas::PiecePtr& iPiece);

	void killPiece(const datas::Position& iPosition);
	void revivePiece(const datas::Position& iPosition);

	const datas::Case& getCase(int ligne, int col) const;
	datas::Case& accessCase(int ligne, int col);

	const datas::Case& getCase(const datas::Position& iPosition) const;
	datas::Case& accessCase(const datas::Position& iPosition);

	const datas::AllPiecePtr& getAllPiecesJ1() const;
	void setAllPiecesJ1(datas::AllPiecePtr& iAllPieces);

	const datas::AllPiecePtr& getAllPiecesJ2() const;
	void setAllPiecesJ2(datas::AllPiecePtr& iAllPieces);

	const datas::Echiquier& getEchiquier() const;
	void setEchiquier(datas::Echiquier& iEchiquier);

	bool getPossiblePriseEnPassant() const;

	datas::Move& accessLastMove();
	const datas::Move& getLastMove() const;

	void setChangeMove(const datas::Move& iMove);

	//supprime toutes les pieces
	void reset();

	void setByFile(FILE* f);
	void resetByFile(FILE* f);
	void setBegginingGameWithoutHandicap();


private:
	Echiquier();
	Echiquier(const Echiquier&);
	Echiquier& operator=(const Echiquier&);

	void setPossiblePriseEnPassant(bool iPossiblePriseEnPassant);

	//static Echiquier* _instance;
	static Echiquier _instance;

	//std::array<std::array<datas::Case, NBRE_LIGNE>, NBRE_COLONNE> echiquier;
	datas::Echiquier _echiquier;

	std::array <std::array<bool, NBRE_JOUEURS>, NBRE_TOURS> _tourAlreadyMoved;

	bool _possiblePriseEnPassant;
	//utiliser enum + pour les deux joueurs
	std::array <bool, NBRE_JOUEURS> _rockPossible;

	std::array <datas::AllPiecePtr, 2> _allPiecesJoueurs;

	datas::Move _lastMove;

	bool _hasAlreadyPiece;

};

} /* namespace game*/
#endif /* Echiquier_H_ */
