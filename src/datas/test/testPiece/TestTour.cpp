/*
 * TestTour.cpp
 *
 *  Created on: 28 oct. 2016
 *      Author: le_e
 */

#include "TestTour.h"
#include "../../src/piece/Tour.h"
#include "../../../game/src/Echiquier.h"

using namespace std;
using namespace datas;

TestTour::TestTour()
{}

TestTour::~TestTour()
{}

void TestTour::startTests(void){
	TestTour aTestTour;

	aTestTour.testCanAccess();
	aTestTour.testMovePiece();
	aTestTour.testIsValideMove();

	std::cout << std::endl;
}

void TestTour::testIsValideMove(void) const{
	cout << "TestTour - testIsValideMove";

	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	aEchiquier.reset();

	Position aPositionStart(2, 5);
	Position aPositionEnd(7, 5);
	Move aMove(aPositionStart, aPositionEnd);
	Tour *aTour = new Tour(WHITE, aPositionStart);

	//test move OK
	BOOST_ASSERT_MSG(aTour->isValideMove(aMove), "TestTour MovePiece - valide move");

	//test position de depart incorrecte (differente position de la piece) => not valide move
	aMove.setPositionStart(aPositionEnd);
	aMove.setPositionEnd(aPositionStart);
	BOOST_ASSERT_MSG(!aTour->isValideMove(aMove), "TestTour MovePiece - not valide move");

	//test avec tour de meme couleur deja sur la case de depart => move not OK
	Tour *aTour2 = new Tour(WHITE, aPositionEnd);
	aEchiquier.addPiece(aTour2);
	BOOST_ASSERT_MSG(!aTour->isValideMove(aMove), "TestTour MovePiece - not valide move");

	//test avec tour de couleur differente deja sur la case de depart => move OK
	Tour *aTour3 = new Tour(BLACK, aPositionEnd);
	aEchiquier.removePiece(aTour2->getPosition());
	aEchiquier.addPiece(aTour3);
	BOOST_ASSERT_MSG(!aTour->isValideMove(aMove), "TestTour MovePiece - not valide move");

	delete aTour;

	cout << "	OK" << std::endl;
}

void TestTour::testCanAccess(void)const{
	cout << "TestTour - testCanAccess";

	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	aEchiquier.reset();

	Position aPositionStart(2, 5);
	Position aPositionEnd(2, 7);
	Tour *aTour = new Tour(WHITE, aPositionStart);

	//test canAccessCase ok => suivant la ligne
	BOOST_ASSERT_MSG(aTour->canAccessCase(aPositionEnd), "TestTour canAccess - test sameLigne");

	//test canAccessCase ok => suivant la colonne
	aPositionEnd.setPosition(7, 5);
	BOOST_ASSERT_MSG(aTour->canAccessCase(aPositionEnd), "TestTour canAccess - test sameCol");

	//test canAccessCase not ok => ligne et colonne differents
	aPositionEnd.setPosition(6, 4);
	BOOST_ASSERT_MSG(!aTour->canAccessCase(aPositionEnd), "TestTour canAccess - cannot access, ligne");

	//test canAccessCase not ok => piece sur le chemin (noire ou blanche)
	aPositionEnd.setPosition(7, 5);
	Tour *aTour2 = new Tour(WHITE, Position(5, 5));
	aEchiquier.addPiece(aTour2);
	BOOST_ASSERT_MSG(!aTour->canAccessCase(aPositionEnd), "TestTour canAccess - cannot access, piece sur le chemin, ligne");


	/*aEchiquier.removePiece(aTour2->getPosition());
	aEchiquier.removePiece(aTour2->getPosition());
	Tour *aTour4 = new Tour(WHITE, aTour2->getPosition());
	aEchiquier.addPiece(aTour4);
	aEchiquier.removePiece(aTour2->getPosition());*/

	aPositionEnd.setPosition(2, 1);
	Tour *aTour3 = new Tour(WHITE, Position(2, 4));
	aEchiquier.addPiece(aTour3);
	//aEchiquier.movePiece(aTour2->getPosition(), Position(2, 4));
	if(aEchiquier.getCase(Position(2, 4)).hasPiece()){
		cout << endl << "hasPiece" << endl;
	}
	else{
		cout << endl << "hasNotPiece" << endl;
	}
	BOOST_ASSERT_MSG(!aTour->canAccessCase(aPositionEnd), "TestTour canAccess - cannot access, piece sur le chemin, ligne");

	delete aTour;

	cout << "	OK" << std::endl;
}

void TestTour::testMovePiece(void) const{
	cout << "TestTour - testMovePiece";

	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	aEchiquier.reset();

	Position aPositionStart(2, 5);
	Position aPositionEnd(7, 5);
	Tour *atour = new Tour(WHITE, aPositionStart);

	BOOST_ASSERT_MSG(!atour->getHasAlreadyMoved(), "TestTour MovePiece - hasNotMoved");

	atour->movePiece(aPositionEnd);
	BOOST_ASSERT_MSG(atour->getHasAlreadyMoved(), "TestTour MovePiece - hasMoved");

	delete atour;

	cout << "	OK" << std::endl;
}
