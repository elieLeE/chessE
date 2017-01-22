/*
 * TestFou.cpp
 *
 *  Created on: 29 oct. 2016
 *      Author: le_e
 */
#include "../testPiece/TestFou.h"

#include <iostream>

#include "../../../common/src/UnitTest.h"
#include "../../src/piece/Dame.h"
#include "../../src/piece/Fou.h"

using namespace std;
using namespace datas;
using namespace common;

TestFou::TestFou()
{}

TestFou::~TestFou()
{}

void TestFou::startTests(void){
	UnitTest<TestFou> unitT("TestFou");

	unitT.addMethod("testCanAccess/valideMove", &datas::TestFou::testCanAccessCase);

	unitT.launchMethods();
}

/*
 * on teste tous les cas dans testCanAccess et isValideMove de testPiece
 */
void TestFou::testCanAccessCase(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Position aPositionStart(6, 3);
	Position aPositionEnd(1, 8);
	Move aMove(aPositionStart, aPositionEnd);
	Fou* aFou(new Fou(WHITE, aPositionStart));

	aEchiquier.addPiece(aFou);

	//test mouvement OK
	BOOST_ASSERT_MSG(aFou->canAccessCase(aPositionEnd), "TestFou canAccess - test position 1");

	//test mouvement not OK
	aPositionEnd.setPosition(4, 8);
	aMove.setPositionEnd(aPositionEnd);
	BOOST_ASSERT_MSG(!aFou->canAccessCase(aPositionEnd), "TestFou canAccess - not same color case");

	aPositionEnd.setPosition(3, 8);
	aMove.setPositionEnd(aPositionEnd);
	BOOST_ASSERT_MSG(!aFou->canAccessCase(aPositionEnd), "TestFou canAccess - not same diag");

	aPositionEnd.setPosition(1, 8);
	aMove.setPositionEnd(aPositionEnd);
	Position aPositionDame(4, 5);
	Dame* aDame(new Dame(WHITE, aPositionDame));
	BOOST_ASSERT_MSG(aFou->canAccessCase(aPositionEnd), "TestFou canAccess - test position 2");

	aEchiquier.addPiece(aDame);
	BOOST_ASSERT_MSG(!aFou->canAccessCase(aPositionEnd), "TestFou canAccess - piece present on the path");

	aEchiquier.movePiece(aPositionDame, aPositionEnd);
	BOOST_ASSERT_MSG(aFou->canAccessCase(aPositionEnd), "TestFou canAccess - piece already present in the end case and same color");
	BOOST_ASSERT_MSG(!aFou->isValideMove(aMove), "TestFou isValideMove - piece already present in the end case and same color");

	Position aPositionDame2(1, 8);
	Dame* aDame2(new Dame(BLACK, aPositionDame2));
	aEchiquier.addPiece(aDame2);
	BOOST_ASSERT_MSG(aFou->canAccessCase(aPositionEnd), "TestFou canAccess - piece already present in the end case but different color");
}
