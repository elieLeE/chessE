/*
 * TestCavalier.cpp
 *
 *  Created on: 29 oct. 2016
 *      Author: le_e
 */
#include <boost/assert.hpp>

#include "TestCavalier.h"
#include "../../src/piece/Cavalier.h"
#include "../../../game/src/Echiquier.h"

using namespace std;
using namespace datas;

TestCavalier::TestCavalier()
{}

TestCavalier::~TestCavalier()
{}

void TestCavalier::startTests(void){
	TestCavalier aTourCavalier;

	aTourCavalier.testCanAccess();
	aTourCavalier.testIsValideMove();

	std::cout << std::endl;
}

void TestCavalier::testCanAccess(void) const{
	cout << "TestCavalier - testCanAccess";

	Position aPositionStart(2, 5);
	Position aPositionEnd(4, 4);
	Move aMove(aPositionStart, aPositionEnd);
	Cavalier aCavalier(WHITE, aPositionStart);

	//test mouvement OK
	BOOST_ASSERT_MSG(aCavalier.canAccessCase(aPositionEnd), "TestCavalier canAccess - test sameLigne");
	BOOST_ASSERT_MSG(aCavalier.isValideMove(aMove), "TestCavalier MovePiece - valide move");

	//test mouvement OK
	aPositionEnd.setPosition(0, 6);
	aMove.setPositionEnd(aPositionEnd);
	BOOST_ASSERT_MSG(aCavalier.canAccessCase(aPositionEnd), "TestCavalier canAccess - test sameCol");
	BOOST_ASSERT_MSG(aCavalier.isValideMove(aMove), "TestCavalier MovePiece - valide move");

	//test mouvement not OK
	aPositionEnd.setPosition(7, 3);
	aMove.setPositionEnd(aPositionEnd);
	BOOST_ASSERT_MSG(!aCavalier.canAccessCase(aPositionEnd), "TestCavalier canAccess - cannot access");
	BOOST_ASSERT_MSG(!aCavalier.isValideMove(aMove), "TestCavalier MovePiece - not valide move");

	cout << "	OK" << endl;
}

void TestCavalier::testIsValideMove(void) const{
	cout << "TestCavalier - testIsValideMove";

	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	aEchiquier.reset();

	Position aPositionStart(2, 5);
	Position aPositionEnd(4, 4);
	//Move aMove(Position(aPositionStart.getX()+1, aPositionStart.getY()), aPositionEnd);
	Move aMove(aPositionStart, aPositionEnd);
	PiecePtr aCavalier(new Cavalier(WHITE, aPositionStart));
	PiecePtr aCavalier2(new Cavalier(WHITE, aPositionEnd));

	aEchiquier.addPiece(aCavalier);
	aEchiquier.addPiece(aCavalier2);

	//test avec position de depart du mouvement differente de la position de la piece ==> rejet
	BOOST_ASSERT_MSG(!aCavalier->isValideMove(aMove), "TestCavalier MovePiece - not valide move");

	aMove.setPositionStart(aPositionStart);

	//test avec piece de meme couleur deja dans la case d'arrive ==> move non valide
	BOOST_ASSERT_MSG(!aCavalier->isValideMove(aMove), "TestCavalier MovePiece - not valide move");

	//test avec piece de couleur differente deja dans la case d'arrive ==> move valide
	PiecePtr aCavalier3(new Cavalier(BLACK, aPositionEnd));
	aEchiquier.addPiece(aCavalier3);
	BOOST_ASSERT_MSG(aCavalier->isValideMove(aMove), "TestCavalier MovePiece - valide move");

	cout << "	OK" << endl;
}
