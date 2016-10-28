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
	Tour *atour = new Tour(WHITE, aPositionStart);

	BOOST_ASSERT_MSG(atour->isValideMove(aMove), "testTour MovePiece - hasNotMoved");

	aMove.setPositionStart(aPositionEnd);
	aMove.setPositionEnd(aPositionStart);
	BOOST_ASSERT_MSG(!atour->isValideMove(aMove), "testTour MovePiece - hasMoved");

	delete atour;

	cout << "	OK" << std::endl;
}

void TestTour::testCanAccess(void)const{
	cout << "TestTour - testCanAccess";

	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	aEchiquier.reset();

	Position aPositionStart(2, 5);
	Position aPositionEnd(7, 5);
	Tour *atour = new Tour(WHITE, aPositionStart);

	BOOST_ASSERT_MSG(atour->canAccessCase(aPositionEnd), "testTour canAccess - test sameLigne");

	aPositionEnd.setPosition(7, 5);
	BOOST_ASSERT_MSG(atour->canAccessCase(aPositionEnd), "testTour canAccess - test sameCol");

	aPositionEnd.setPosition(7, 3);
	BOOST_ASSERT_MSG(!atour->canAccessCase(aPositionEnd), "testTour canAccess - cannot access");

	delete atour;

	cout << "	OK" << std::endl;;
}

void TestTour::testMovePiece(void) const{
	cout << "TestTour - testMovePiece";

	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	aEchiquier.reset();

	Position aPositionStart(2, 5);
	Position aPositionEnd(7, 5);
	Tour *atour = new Tour(WHITE, aPositionStart);

	BOOST_ASSERT_MSG(!atour->getHasAlreadyMoved(), "testTour MovePiece - hasNotMoved");

	atour->movePiece(aPositionEnd);
	BOOST_ASSERT_MSG(atour->getHasAlreadyMoved(), "testTour MovePiece - hasMoved");

	delete atour;

	cout << "	OK" << std::endl;
}
