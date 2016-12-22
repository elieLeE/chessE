/*
 * TestFou.cpp
 *
 *  Created on: 29 oct. 2016
 *      Author: le_e
 */
#include <iostream>

#include "../../../common/src/UnitTest.h"
#include "TestFou.h"
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
	//to verify aFou2 ont the corrcet path
	//cout << endl << "echiquier 1 : " << endl << aEchiquier << endl;
	BOOST_ASSERT_MSG(aFou->canAccessCase(aPositionEnd), "TestFou canAccess - test position 2");
	aEchiquier.addPiece(aDame);
	/*cout << "dame added at position " << aPositionDame << endl;
	cout << "piece : " << *aDame << endl;
	cout << endl << "echiquier 2 : " << endl << aEchiquier << endl;
	if(aEchiquier.getCase(5, 4).hasPiece()){
		cout << "aPositionDame has piece" << endl;
	}
	else{
		cout << "aPositionDame has not piece" << endl;
	}*/
	BOOST_ASSERT_MSG(!aFou->canAccessCase(aPositionEnd), "TestFou canAccess - piece present on the path");

	aEchiquier.movePiece(aPositionDame, aPositionEnd);
	//incorrecte move with isValideMove but not with canAccessCase (test are done on all case till before last case)
	//cout << endl << "echiquier : " << endl << aEchiquier << endl;
	BOOST_ASSERT_MSG(aFou->canAccessCase(aPositionEnd), "TestFou canAccess - piece already present in the end case and same color");
	BOOST_ASSERT_MSG(!aFou->isValideMove(aMove), "TestFou isValideMove - piece already present in the end case and same color");

	Position aPositionDame2(1, 8);
	Dame* aDame2(new Dame(BLACK, aPositionDame2));
	aEchiquier.addPiece(aDame2);
	BOOST_ASSERT_MSG(aFou->canAccessCase(aPositionEnd), "TestFou canAccess - piece already present in the end case but different color");
}
