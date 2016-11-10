/*
 * TestFou.cpp
 *
 *  Created on: 29 oct. 2016
 *      Author: le_e
 */
#include <iostream>

#include "../../../common/src/UnitTest.h"
#include "TestFou.h"
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

	Position aPositionStart(2, 5);
	Position aPositionEnd(7, 0);
	Move aMove(aPositionStart, aPositionEnd);
	Fou aFou(WHITE, aPositionStart);

	//test mouvement OK
	BOOST_ASSERT_MSG(aFou.canAccessCase(aPositionEnd), "TestFou canAccess - test position 1");

	//test mouvement not OK
	aPositionEnd.setPosition(7, 3);
	aMove.setPositionEnd(aPositionEnd);
	BOOST_ASSERT_MSG(!aFou.canAccessCase(aPositionEnd), "TestFou canAccess - not same color case");

	aPositionEnd.setPosition(7, 2);
	aMove.setPositionEnd(aPositionEnd);
	BOOST_ASSERT_MSG(!aFou.canAccessCase(aPositionEnd), "TestFou canAccess - not same diag");

	aPositionEnd.setPosition(7, 0);
	aMove.setPositionEnd(aPositionEnd);
	Position aPositionFou2(4, 3);
	Fou* aFou2(new Fou(WHITE, aPositionFou2));
	//to verify aFou2 ont the corrcet path
	BOOST_ASSERT_MSG(aFou.canAccessCase(aPositionFou2), "TestFou canAccess - test position 2");
	aEchiquier.addPiece(aFou2);
	BOOST_ASSERT_MSG(!aFou.canAccessCase(aPositionEnd), "TestFou canAccess - piece present on the path");

	aEchiquier.movePiece(aPositionFou2, aPositionEnd);
	//incorrecte move with isValideMove but not with canAccessCase (test are done on all case till before last case)
	BOOST_ASSERT_MSG(aFou.canAccessCase(aPositionEnd), "TestFou canAccess - piece already present in the end case and same color");
	BOOST_ASSERT_MSG(!aFou.isValideMove(aMove), "TestFou isValideMove - piece already present in the end case and same color");

	Position aPositionFou3(7, 0);
	Fou* aFou3(new Fou(BLACK, aPositionFou3));
	aEchiquier.addPiece(aFou3);
	BOOST_ASSERT_MSG(aFou.canAccessCase(aPositionEnd), "TestFou canAccess - piece already present in the end case but different color");
}
