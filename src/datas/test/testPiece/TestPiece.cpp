/*
 * TestPiece.cpp
 *
 *  Created on: 6 nov. 2016
 *      Author: le_e
 *
 * Test unitaire de la classe Piece => classe abstraite => on passe par la sous classe Tour
 */

#include "TestPiece.h"

using namespace std;
using namespace datas;

TestPiece::TestPiece()
{}

TestPiece::~TestPiece()
{}

void TestPiece::startTests(void){
	TestPiece aTestPiece;

	aTestPiece.testSimple();
	aTestPiece.testMovePiece();
	aTestPiece.testAliveDead();
	aTestPiece.testIsValideMove();
	aTestPiece.testCanTakeCase();

	std::cout << std::endl;
}

void TestPiece::testSimple(void){
	cout << "TestPiece - testSimple";

	Position aPosition(2, 2);
	Tour aTour(WHITE, aPosition);

	BOOST_ASSERT_MSG(aTour.getColor() == WHITE, "TestPiece simple - color");
	BOOST_ASSERT_MSG(aTour.getTypePiece() == TOUR_TYPE, "TestPiece simple - typePiece");
	BOOST_ASSERT_MSG(aTour.getNumJoueur() == JOUEUR_1, "TestPiece simple - numJoueur");
	BOOST_ASSERT_MSG(aTour.getPosition() == aPosition, "TestPiece simple - position");

	cout << "	Ok" << endl;
}

void TestPiece::testMovePiece(void) const{
	cout << "TestPiece - testMovePiece";

	Position aPositionStart(2, 2);
	Position aPositionEnd(6, 2);
	Tour aTour(WHITE, aPositionStart);

	BOOST_ASSERT_MSG(aTour.getPosition() == aPositionStart, "TestPiece simple - before Move");

	aTour.movePiece(aPositionEnd);
	BOOST_ASSERT_MSG(aTour.getPosition() == aPositionEnd, "TestPiece simple - after Move");

	cout << "	OK" << endl;
}

void TestPiece::testAliveDead(void) const {
	cout << "TestPiece - testAliveDead";

	Position aPosition(2, 2);
	Tour aTour(WHITE, aPosition);

	BOOST_ASSERT_MSG(aTour.isAlive(), "TestPiece simple - alive");

	aTour.setDead();
	BOOST_ASSERT_MSG(!aTour.isAlive(), "TestPiece simple - dead");

	aTour.setAlive();
	BOOST_ASSERT_MSG(aTour.isAlive(), "TestPiece simple - alive/revive");

	cout << "	OK" << endl;
}

void TestPiece::testIsValideMove(void) const{
	cout << "TestPiece - testIsValideMove";

	aEchiquier->reset();

	Position aPositionStart(2, 2);
	Position aPositionEnd(4, 2);
	Piece* aTour(new Tour(WHITE, aPositionStart));
	Move aMove(aPositionStart, aPositionEnd);

	aEchiquier->addPiece(aTour);

	BOOST_ASSERT_MSG(aTour->isValideMove(aMove), "TestPiece isValideMove - valid");

	aMove.setPositionStart(aPositionEnd);
	BOOST_ASSERT_MSG(!aTour->isValideMove(aMove), "TestPiece isValideMove - valid");

	aMove.setPositionStart(aPositionStart);
	BOOST_ASSERT_MSG(aTour->isValideMove(aMove), "TestPiece isValideMove - valid/no piece");

	Tour *aTour2(new Tour(BLACK, aPositionEnd));
	aEchiquier->addPiece(aTour2);
	BOOST_ASSERT_MSG(aTour->isValideMove(aMove), "TestPiece isValideMove - valid/piece different color");

	aTour2->setDead();
	BOOST_ASSERT_MSG(aTour->isValideMove(aMove), "TestPiece isValideMove - valid/piece dead");

	Tour *aTour3(new Tour(WHITE, aPositionEnd));
	aEchiquier->addPiece(aTour3);
	BOOST_ASSERT_MSG(!aTour->isValideMove(aMove), "TestPiece isValideMove - not valid/piece same color");

	aTour3->setDead();
	BOOST_ASSERT_MSG(aTour->isValideMove(aMove), "TestPiece isValideMove - valid/piece same color but dead");

	cout << "	OK" << endl;
}

void TestPiece::testCanTakeCase() const{
	cout << "TestPiece - testCanTakeCase";

	aEchiquier->reset();

	Position aPositionStart(2, 2);
	Position aPositionEnd(4, 2);
	Piece* aTour(new Tour(WHITE, aPositionStart));
	Move aMove(aPositionStart, aPositionEnd);

	aEchiquier->addPiece(aTour);

	BOOST_ASSERT_MSG(aTour->canTakeCase(aMove.getEndPosition()), "TestPiece canTakeCase - valid/no piece");

	Tour *aTour2(new Tour(BLACK, aPositionEnd));
	aEchiquier->addPiece(aTour2);
	BOOST_ASSERT_MSG(aTour->canTakeCase(aMove.getEndPosition()), "TestPiece canTakeCase - valid/piece different color");

	aTour2->setDead();
	BOOST_ASSERT_MSG(aTour->canTakeCase(aMove.getEndPosition()), "TestPiece canTakeCase - valid/piece dead");

	Tour *aTour3(new Tour(WHITE, aPositionEnd));
	aEchiquier->addPiece(aTour3);
	BOOST_ASSERT_MSG(!aTour->canTakeCase(aMove.getEndPosition()), "TestPiece canTakeCase - not valid/piece same color");

	aTour3->setDead();
	BOOST_ASSERT_MSG(aTour->canTakeCase(aMove.getEndPosition()), "TestPiece canTakeCase - valid/piece same color but dead");

	cout << "	OK" << endl;
}
