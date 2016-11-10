/*
 * TestCavalier.cpp
 *
 *  Created on: 29 oct. 2016
 *      Author: le_e
 */
#include <boost/assert.hpp>

#include "../../../common/src/UnitTest.h"
#include "TestCavalier.h"
#include "../../src/piece/Cavalier.h"
#include "../../../game/src/Echiquier.h"

using namespace std;
using namespace datas;
using namespace common;

TestCavalier::TestCavalier()
{}

TestCavalier::~TestCavalier()
{}

void TestCavalier::startTests(void){
	UnitTest<TestCavalier> unitT("TestCavalier");

	unitT.addMethod("testCanAccess", &datas::TestCavalier::testCanAccess);
	unitT.addMethod("testIsValideMove", &datas::TestCavalier::testIsValideMove);

	unitT.launchMethods();
}

void TestCavalier::testCanAccess(void) const{
	Position aPositionStart(2, 5);
	Position aPositionEnd(4, 4);
	Move aMove(aPositionStart, aPositionEnd);
	Cavalier aCavalier(WHITE, aPositionStart);

	//test mouvement OK
	BOOST_ASSERT_MSG(aCavalier.canAccessCase(aPositionEnd), "TestCavalier canAccess - test position 1");
	BOOST_ASSERT_MSG(aCavalier.isValideMove(aMove), "TestCavalier MovePiece - test position 1");

	//test mouvement OK
	aPositionEnd.setPosition(0, 6);
	aMove.setPositionEnd(aPositionEnd);
	BOOST_ASSERT_MSG(aCavalier.canAccessCase(aPositionEnd), "TestCavalier canAccess - test position 2");
	BOOST_ASSERT_MSG(aCavalier.isValideMove(aMove), "TestCavalier MovePiece - test position 2");

	//test mouvement not OK
	aPositionEnd.setPosition(7, 3);
	aMove.setPositionEnd(aPositionEnd);
	BOOST_ASSERT_MSG(!aCavalier.canAccessCase(aPositionEnd), "TestCavalier canAccess - cannot access");
	BOOST_ASSERT_MSG(!aCavalier.isValideMove(aMove), "TestCavalier MovePiece - not valide move");
}

void TestCavalier::testIsValideMove(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Position aPositionStart(2, 5);
	Position aPositionEnd(4, 4);
	//Move aMove(Position(aPositionStart.getX()+1, aPositionStart.getY()), aPositionEnd);
	Move aMove(aPositionStart, aPositionEnd);

	Cavalier* aCavalier = new Cavalier(WHITE, aPositionStart);
	Cavalier* aCavalier2 = new Cavalier(WHITE, aPositionEnd);

	aEchiquier.addPiece(aCavalier);
	aEchiquier.addPiece(aCavalier2);

	//test avec position de depart du mouvement differente de la position de la piece ==> rejet
	BOOST_ASSERT_MSG(!aCavalier->isValideMove(aMove), "TestCavalier MovePiece - not valide move/incorrect start position");

	aMove.setPositionStart(aPositionStart);

	//test avec piece de meme couleur deja dans la case d'arrive ==> move non valide
	BOOST_ASSERT_MSG(aCavalier->canAccessCase(aMove.getEndPosition()), "TestCavalier MovePiece - canAccesCase/case already occupied by another piece same color ");
	BOOST_ASSERT_MSG(!aCavalier->isValideMove(aMove), "TestCavalier MovePiece - not valide move/case already occupied by another piece same color ");

	//test avec piece de couleur differente deja dans la case d'arrive ==> move valide
	PiecePtr aCavalier3(new Cavalier(BLACK, aPositionEnd));
	aEchiquier.addPiece(aCavalier3);
	BOOST_ASSERT_MSG(aCavalier->isValideMove(aMove), "TestCavalier MovePiece - valide move");
}
