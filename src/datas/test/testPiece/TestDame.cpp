/*
 * TestDame.cpp
 *
 *  Created on: 29 oct. 2016
 *      Author: le_e
 */
#include <iostream>

#include "../../../common/src/UnitTest.h"
#include "TestDame.h"
#include "../../src/piece/Dame.h"

using namespace std;
using namespace datas;
using namespace common;

TestDame::TestDame()
{}

TestDame::~TestDame()
{}

void TestDame::startTests(void){
	UnitTest<TestDame> unitT("TestDame\n");

	unitT.addMethod("testCanAccessCaseMoveTypeFou/valideMove", &datas::TestDame::testCanAccessCaseMoveTypeFou);
	unitT.addMethod("testCanAccessCaseMoveTypeTour/valideMove", &datas::TestDame::testCanAccessCaseMoveTypeTour);

	unitT.launchMethods();
}

void TestDame::testCanAccessCaseMoveTypeTour(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Position aPositionStart(2, 5);
	Position aPositionEnd(2, 7);
	Move aMove(aPositionStart, aPositionEnd);
	Dame *aDame(new Dame(WHITE, aPositionStart));
	aEchiquier.addPiece(aDame);

	//test canAccessCase ok => suivant la ligne
	BOOST_ASSERT_MSG(aDame->canAccessCase(aPositionEnd), "TestDame/TypeTour canAccess - test sameLigne");

	//test canAccessCase ok => suivant la colonne
	aPositionEnd.setPosition(7, 5);
	BOOST_ASSERT_MSG(aDame->canAccessCase(aPositionEnd), "TestDame/TypeTour canAccess - test sameCol");

	//test canAccessCase not ok => ligne et colonne differents
	aPositionEnd.setPosition(6, 4);
	BOOST_ASSERT_MSG(!aDame->canAccessCase(aPositionEnd), "TestDame/TypeTour canAccess - different line and col");

	//test canAccessCase not ok => piece sur le chemin (noire ou blanche)
	aPositionEnd.setPosition(7, 5);
	Dame* aDame2(new Dame(WHITE, Position(5, 5)));
	aEchiquier.addPiece(aDame2);
	BOOST_ASSERT_MSG(!aDame->canAccessCase(aPositionEnd), "TestDame/TypeTour canAccess - piece sur le chemin, ligne");

	aPositionEnd.setPosition(2, 1);
	aDame2->movePiece(aPositionEnd);
	BOOST_ASSERT_MSG(!aDame->canAccessCase(aPositionEnd), "TestDame/TypeTour canAccess - piece sur le chemin, col");

	aPositionStart.setPosition(6, 0);
	aPositionEnd.setPosition(0, 0);
	aMove.setPositionStart(aPositionStart);
	aMove.setPositionEnd(aPositionEnd);
	aDame->movePiece(aPositionStart);

	aDame2->movePiece(aPositionEnd);
	BOOST_ASSERT_MSG(!aDame->isValideMove(aMove), "TestDame/TypeTour - same color");

	//test avec tour de couleur differente deja sur la case de depart => move OK
	Dame *aDame3(new Dame(BLACK, aPositionEnd));
	aEchiquier.addPiece(aDame3);
	BOOST_ASSERT_MSG(aDame->isValideMove(aMove), "TestDame/TypeTour - different color");
}

void TestDame::testCanAccessCaseMoveTypeFou(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Position aPositionStart(2, 5);
	Position aPositionEnd(7, 0);
	Move aMove(aPositionStart, aPositionEnd);
	Dame aDame(WHITE, aPositionStart);

	//test mouvement OK
	BOOST_ASSERT_MSG(aDame.canAccessCase(aPositionEnd), "TestDame/TypeFou canAccess - test position 1");

	//test mouvement not OK
	aPositionEnd.setPosition(7, 3);
	aMove.setPositionEnd(aPositionEnd);
	BOOST_ASSERT_MSG(!aDame.canAccessCase(aPositionEnd), "TestDame/TypeFou  canAccess - not same color case");

	aPositionEnd.setPosition(7, 2);
	aMove.setPositionEnd(aPositionEnd);
	BOOST_ASSERT_MSG(!aDame.canAccessCase(aPositionEnd), "TestDame/TypeFou  canAccess - not same diag");

	aPositionEnd.setPosition(7, 0);
	aMove.setPositionEnd(aPositionEnd);
	Position aPositionFou2(4, 3);
	Dame* aDame2(new Dame(WHITE, aPositionFou2));
	//to verify aDame2 ont the corrcet path
	BOOST_ASSERT_MSG(aDame.canAccessCase(aPositionFou2), "TestDame/TypeFou  canAccess - test position 2");
	aEchiquier.addPiece(aDame2);
	BOOST_ASSERT_MSG(!aDame.canAccessCase(aPositionEnd), "TestDame/TypeFou  canAccess - piece present on the path");

	aEchiquier.movePiece(aPositionFou2, aPositionEnd);
	//incorrecte move with isValideMove but not with canAccessCase (test are done on all case till before last case)
	BOOST_ASSERT_MSG(!aDame.canAccessCase(aPositionEnd), "TestDame/TypeFou  canAccess - piece already present in the end case and same color");
	BOOST_ASSERT_MSG(!aDame.isValideMove(aMove), "TestDame/TypeFou  isValideMove - piece already present in the end case and same color");

	Position aPositionFou3(7, 0);
	Dame* aDame3(new Dame(BLACK, aPositionFou3));
	aEchiquier.addPiece(aDame3);
	BOOST_ASSERT_MSG(aDame.canAccessCase(aPositionEnd), "TestDame/TypeFou  canAccess - piece already present in the end case but different color");
	BOOST_ASSERT_MSG(aDame.isValideMove(aMove), "TestDame/TypeFou  canAccess - piece already present in the end case but different color");
}
