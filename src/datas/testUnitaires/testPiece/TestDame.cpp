/*
 * TestDame.cpp
 *
 *  Created on: 29 oct. 2016
 *      Author: le_e
 */
#include "../../testUnitaires/testPiece/TestDame.h"

#include <iostream>

#include "../../../common/src/UnitTest.h"
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

	Position aPositionStart(6, 3);
	Position aPositionEnd(8, 3);
	Move aMove(aPositionStart, aPositionEnd);
	Dame *aDame(new Dame(WHITE, aPositionStart));
	aEchiquier.addPiece(aDame);

	//test canAccessCase ok => suivant la ligne
	BOOST_ASSERT_MSG(aDame->canAccessCase(aPositionEnd), "TestDame/TypeTour canAccess - test sameLigne");

	//test canAccessCase ok => suivant la colonne
	aPositionEnd.setPosition(6, 8);
	BOOST_ASSERT_MSG(aDame->canAccessCase(aPositionEnd), "TestDame/TypeTour canAccess - test sameCol");

	//test canAccessCase not ok => ligne et colonne differents
	aPositionEnd.setPosition(5, 7);
	BOOST_ASSERT_MSG(!aDame->canAccessCase(aPositionEnd), "TestDame/TypeTour canAccess - different line and col");

	//test canAccessCase not ok => piece sur le chemin (noire ou blanche)
	aPositionEnd.setPosition(6, 8);
	Dame* aDame2(new Dame(WHITE, Position(6, 6)));
	aEchiquier.addPiece(aDame2);
	BOOST_ASSERT_MSG(!aDame->canAccessCase(aPositionEnd), "TestDame/TypeTour canAccess - piece sur le chemin, ligne");

	aPositionEnd.setPosition(2, 3);
	aDame2->movePiece(aPositionEnd);
	BOOST_ASSERT_MSG(!aDame->canAccessCase(aPositionEnd), "TestDame/TypeTour canAccess - piece sur le chemin, col");

	aPositionStart.setPosition(1, 7);
	aPositionEnd.setPosition(1, 1);
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

	Position aPositionStart(6, 3);
	Position aPositionEnd(1, 8);
	Move aMove(aPositionStart, aPositionEnd);
	Dame aDame(WHITE, aPositionStart);

	//test mouvement OK
	BOOST_ASSERT_MSG(aDame.canAccessCase(aPositionEnd), "TestDame/TypeFou canAccess - test position 1");

	//test mouvement not OK
	aPositionEnd.setPosition(4, 8);
	aMove.setPositionEnd(aPositionEnd);
	BOOST_ASSERT_MSG(!aDame.canAccessCase(aPositionEnd), "TestDame/TypeFou  canAccess - not same color case");

	aPositionEnd.setPosition(3, 8);
	aMove.setPositionEnd(aPositionEnd);
	BOOST_ASSERT_MSG(!aDame.canAccessCase(aPositionEnd), "TestDame/TypeFou  canAccess - not same diag");

	aPositionEnd.setPosition(1, 8);
	aMove.setPositionEnd(aPositionEnd);
	Position aPositionFou2(4, 5);
	Dame* aDame2(new Dame(WHITE, aPositionFou2));
	//to verify aDame2 ont the corrcet path
	BOOST_ASSERT_MSG(aDame.canAccessCase(aPositionFou2), "TestDame/TypeFou  canAccess - test position 2");
	aEchiquier.addPiece(aDame2);
	BOOST_ASSERT_MSG(!aDame.canAccessCase(aPositionEnd), "TestDame/TypeFou  canAccess - piece present on the path");

	aEchiquier.movePiece(aPositionFou2, aPositionEnd);
	//incorrecte move with isValideMove but not with canAccessCase (test are done on all case till before last case)
	BOOST_ASSERT_MSG(!aDame.canAccessCase(aPositionEnd), "TestDame/TypeFou  canAccess - piece already present in the end case and same color");
	BOOST_ASSERT_MSG(!aDame.isValideMove(aMove), "TestDame/TypeFou  isValideMove - piece already present in the end case and same color");

	Position aPositionFou3(1, 8);
	Dame* aDame3(new Dame(BLACK, aPositionFou3));
	aEchiquier.addPiece(aDame3);
	BOOST_ASSERT_MSG(aDame.canAccessCase(aPositionEnd), "TestDame/TypeFou  canAccess - piece already present in the end case but different color");
	BOOST_ASSERT_MSG(aDame.isValideMove(aMove), "TestDame/TypeFou  canAccess - piece already present in the end case but different color");
}
