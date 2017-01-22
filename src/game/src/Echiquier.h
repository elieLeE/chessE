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
#include "../../datas/src/Position.h"
#include "../../datas/src/typeDefine/Dimension.h"
#include "../../datas/src/Case.h"
#include "../../datas/src/Move.h"
#include "../../datas/src/typeDefine/TypePlayer.h"
#include "../../datas/src/typeDefine/NbrePiece.h"

namespace datas{
class Roi;
class Joueur;
}

namespace game{

class Echiquier{
public:
	virtual ~Echiquier();

	static const Echiquier& getInstance();
	//utile ?? => pour _possiblePriseEnPassant ? => passer par 1 pointeur de booleen ??
	static Echiquier& accessInstance();

	const datas::Echiquier& getPlateau() const;

	void initEchiquier();

	void movePiece(const datas::Position& iPositionStart, const datas::Position& iPositionEnd);

	//a etudier mais a priori pas une bonne chose => serait 1 pb de conception
	/*const datas::PiecePtr& getPieceCaseXY(datas::Position& iPosition) const;
	datas::PiecePtr& accessPieceCaseXY(datas::Position& iPosition);
	bool hasPieceCaseXY(datas::Position& iPosition) const;*/

	//indispensable car sinon, ne sait pas si a deja des pieces ou pas
	void addPiece(datas::Piece* iPiece);
	void addPiece(datas::PiecePtr& iPiece);
	void setPiece(datas::PiecePtr& iPiece, const datas::Position& iPosition);

	void killPiece(const datas::Position& iPosition);
	void revivePiece(const datas::Position& iPosition);

	const datas::Case& getCase(int ligne, int col) const;
	datas::Case& accessCase(int ligne, int col);

	const datas::Case& getCase(const datas::Position& iPosition) const;
	datas::Case& accessCase(const datas::Position& iPosition);

	const datas::AllPiecePtr& getAllPiecesJ1() const;
	//a terme a partager entre classe joueur et cette classe => avec deux shared_ptr...
	//void setAllPiecesJ1(datas::AllPiecePtr& iAllPieces);

	const datas::AllPiecePtr& getAllPiecesJ2() const;
	//void setAllPiecesJ2(datas::AllPiecePtr& iAllPieces);

	bool getPossiblePriseEnPassant() const;

	const datas::Move& getLastMove() const;

	void doChangeMove(const datas::Move& iMove);

	//methode pour les tests qaund la flemme d'initialiser...
	void setAutomatiquejoueurs();
	const std::shared_ptr <datas::Joueur> getJoueur(int numJ) const;
	//std::shared_ptr<datas::Joueur> accessJoueur(int numJ) ;

	//supprime toutes les pieces
	void reset();

	void setByFile(FILE* f);
	void resetByFile(FILE* f);

	void setBegginingGameWithoutHandicap();
	void setBegginingGameWithoutHandicapRoi();
	void setBegginingGameWithoutHandicapDame();
	void setBegginingGameWithoutHandicapFou();
	void setBegginingGameWithoutHandicapCavalier();
	void setBegginingGameWithoutHandicapTour();
	void setBegginingGameWithoutHandicapPion();

	void toStream(std::ostream& os) const;

private:
	Echiquier();
	Echiquier(const Echiquier&);
	Echiquier& operator=(const Echiquier&);

	//void setJoueurKing(const std::shared_ptr<datas::Roi> iRoiJoueur1, const std::shared_ptr<datas::Roi> iRoiJoueur2);
	void setJoueurKing(const datas::PiecePtr iRoiJoueur1, const datas::PiecePtr iRoiJoueur2);

	static Echiquier _instance;

	datas::Echiquier _echiquier;

	bool _possiblePriseEnPassant;

	std::array <datas::AllPiecePtr, 2> _allPiecesJoueurs;

	datas::Move _lastMove;

	bool _hasAlreadyPiece;

	std::array<std::shared_ptr<datas::Joueur>, NBRE_JOUEURS> _joueurs;
};

std::ostream& operator<<(std::ostream& os, const Echiquier& iEchiquier);

} /* namespace game*/
#endif /* Echiquier_H_ */
