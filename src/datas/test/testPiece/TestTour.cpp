/*
 * TestTour.cpp
 *
 *  Created on: 28 oct. 2016
 *      Author: le_e
 */

#include "TestTour.h"
#include "../../src/piece/Tour.h"
#include "../../../game/src/Echiquier.h"
#include "../../../common/src/UnitTest.h"

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

	unitT.launchMethods();
}

void TestTour::testIsValideMove(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Position aPositionStart(2, 5);
	Position aPositionEnd(7, 5);
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

	Position aPositionStart(2, 5);
	Position aPositionEnd(2, 7);
	Tour* aTour(new Tour(WHITE, aPositionStart));
	aEchiquier.addPiece(aTour);

	//test canAccessCase ok => suivant la ligne
	BOOST_ASSERT_MSG(aTour->canAccessCase(aPositionEnd), "TestTour canAccess - test sameLigne");

	//test canAccessCase ok => suivant la colonne
	aPositionEnd.setPosition(7, 5);
	BOOST_ASSERT_MSG(aTour->canAccessCase(aPositionEnd), "TestTour canAccess - test sameCol");

	//test canAccessCase not ok => ligne et colonne differents
	aPositionEnd.setPosition(6, 4);
	BOOST_ASSERT_MSG(!aTour->canAccessCase(aPositionEnd), "TestTour canAccess - different line and col");

	//test canAccessCase not ok => piece sur le chemin (noire ou blanche)
	aPositionEnd.setPosition(7, 5);
	Tour* aTour2(new Tour(WHITE, Position(5, 5)));
	aEchiquier.addPiece(aTour2);
	BOOST_ASSERT_MSG(!aTour->canAccessCase(aPositionEnd), "TestTour canAccess - piece sur le chemin, ligne");

	aPositionEnd.setPosition(2, 1);
	Tour* aTour3(new Tour(WHITE, Position(2, 4)));
	aEchiquier.addPiece(aTour3);
	BOOST_ASSERT_MSG(!aTour->canAccessCase(aPositionEnd), "TestTour canAccess - piece sur le chemin, col");
}

void TestTour::testMovePiece(void) const{
	Position aPositionStart(2, 5);
	Position aPositionEnd(7, 5);
	Tour *atour = new Tour(WHITE, aPositionStart);

	BOOST_ASSERT_MSG(!atour->getHasAlreadyMoved(), "TestTour MovePiece - hasNotMoved");

	atour->movePiece(aPositionEnd);
	BOOST_ASSERT_MSG(atour->getHasAlreadyMoved(), "TestTour MovePiece - hasMoved");

	delete atour;
}
