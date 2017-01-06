/*
 * TestTour.cpp
 *
 *  Created on: 28 oct. 2016
 *      Author: le_e
 */

#include "TestTour.h"
#include "../../src/piece/Tour.h"
#include "../../src/piece/Dame.h"
#include "../../../game/src/Echiquier.h"
#include "../../../common/src/UnitTest.h"

#include <ostream>
#include <sstream>

using namespace std;
using namespace datas;
using namespace common;

TestTour::TestTour()
{}

TestTour::~TestTour()
{}

void TestTour::startTests(void){
	UnitTest<TestTour> unitT("TestTour");

	unitT.addMethod("testCanAccess", &datas::TestTour::testCanAccess);
	unitT.addMethod("testMovePiece", &datas::TestTour::testMovePiece);
	unitT.addMethod("testIsValideMove", &datas::TestTour::testIsValideMove);
	unitT.addMethod("testToStream", &datas::TestTour::testToStream);

	unitT.launchMethods();
}

void TestTour::testIsValideMove(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Position aPositionStart(5, 2);
	Position aPositionEnd(5, 7);
	Move aMove(aPositionStart, aPositionEnd);
	Tour *aTour(new Tour(WHITE, aPositionStart));

	//test move OK
	BOOST_ASSERT_MSG(aTour->isValideMove(aMove), "TestTour isValideMove - valid move");

	//test position de depart incorrecte (differente position de la piece) => not valide move
	aMove.setPositionStart(aPositionEnd);
	BOOST_ASSERT_MSG(!aTour->isValideMove(aMove), "TestTour isValideMove - positionStart != positionEnd");

	aMove.setPositionStart(aPositionStart);
	//test avec tour de meme couleur deja sur la case de depart => move not OK
	PiecePtr aTour2(new Tour(WHITE, aPositionEnd));
	aEchiquier.addPiece(aTour2);
	BOOST_ASSERT_MSG(!aTour->isValideMove(aMove), "TestTour isValideMove - same color");

	//test avec tour de couleur differente deja sur la case de depart => move OK
	PiecePtr aTour3(new Tour(BLACK, aPositionEnd));
	aEchiquier.addPiece(aTour3);
	BOOST_ASSERT_MSG(aTour->isValideMove(aMove), "TestTour isValideMove - different color");

	delete aTour;
}

void TestTour::testCanAccess(void)const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	cout << endl;

	Position aPositionStart(5, 2);
	Position aPositionEnd(7, 2);
	Tour* aTour(new Tour(WHITE, aPositionStart));
	aEchiquier.addPiece(aTour);

	//test canAccessCase ok => suivant la ligne
	BOOST_ASSERT_MSG(aTour->canAccessCase(aPositionEnd), "TestTour canAccess - test sameLigne");

	//test canAccessCase ok => suivant la colonne
	aPositionEnd.setPosition(5, 7);
	BOOST_ASSERT_MSG(aTour->canAccessCase(aPositionEnd), "TestTour canAccess - test sameCol");

	//test canAccessCase not ok => ligne et colonne differents
	aPositionEnd.setPosition(4, 6);
	BOOST_ASSERT_MSG(!aTour->canAccessCase(aPositionEnd), "TestTour canAccess - different line and col");

	//test canAccessCase not ok => piece sur le chemin (noire ou blanche)
	aPositionEnd.setPosition(5, 7);
	Dame* aDame(new Dame(WHITE, Position(5, 5)));
	aEchiquier.addPiece(aDame);
	BOOST_ASSERT_MSG(!aTour->canAccessCase(aPositionEnd), "TestTour canAccess - piece sur le chemin, ligne");

	aPositionEnd.setPosition(1, 2);
	Dame* aDame2(new Dame(WHITE, Position(4, 2)));
	aEchiquier.addPiece(aDame2);
	//cout << "echiquier : " << aEchiquier << endl;
	BOOST_ASSERT_MSG(!aTour->canAccessCase(aPositionEnd), "TestTour canAccess - piece sur le chemin, col");
}

void TestTour::testMovePiece(void) const{
	Position aPositionStart(5, 2);
	Position aPositionEnd(5, 7);
	Tour *aTour = new Tour(WHITE, aPositionStart);

	BOOST_ASSERT_MSG(!aTour->hasAlreadyMoved(), "TestTour MovePiece - hasNotMoved");

	aTour->movePiece(aPositionEnd);
	BOOST_ASSERT_MSG(aTour->hasAlreadyMoved(), "TestTour MovePiece - hasMoved");

	delete aTour;
}

void TestTour::testToStream(void) const{
	ostream aStream(0);
	stringbuf aStr;
	aStream.rdbuf(&aStr);

	Position aPosition(5, 5);
	Tour aTour(WHITE, aPosition);

	aStream << aTour;

	string aExpected("type : Tour\n"
			"pos : (5, 5)\n"
			"color : WHITE\n"
			"numJ : JOUEUR_1\n"
			"alive ? true\n"
			"value : 5\n"
			"already moved ? false\n");

	BOOST_ASSERT_MSG(aStr.str().compare(aExpected) == 0, "testTour toStream");
}
