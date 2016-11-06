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

	cout << "	TO IMPLMENT" << endl;
}

void TestPiece::testCanTakeCase() const{
	cout << "TestPiece - testCanTakeCase";

	cout << "	TO IMPLMENT" << endl;
}
