/*
 * TestPiece.cpp
 *
 *  Created on: 6 nov. 2016
 *      Author: le_e
 *
 * Test unitaire de la classe Piece => classe abstraite => on passe par la sous classe Tour
 */
#include <iostream>

#include "../../../common/src/UnitTest.h"
#include "../../../game/src/Echiquier.h"
#include "../../src/piece/Tour.h"
#include "TestPiece.h"

using namespace std;
using namespace datas;
using namespace common;

TestPiece::TestPiece()
{}

TestPiece::~TestPiece()
{}

void TestPiece::startTests(void){
	UnitTest<TestPiece> unitT("TestPiece");

	unitT.addMethod("testSimple", &datas::TestPiece::testSimple);
	unitT.addMethod("testMovePiece", &datas::TestPiece::testMovePiece);
	unitT.addMethod("testAliveDead", &datas::TestPiece::testAliveDead);
	unitT.addMethod("testIsValideMove", &datas::TestPiece::testIsValideMove);
	unitT.addMethod("testCanTakeCase", &datas::TestPiece::testCanTakeCase);

	unitT.launchMethods();

}

void TestPiece::testSimple(void) const{
	Position aPosition(2, 2);
	Tour aTour(WHITE, aPosition);

	BOOST_ASSERT_MSG(aTour.getColor() == WHITE, "TestPiece simple - color");
	BOOST_ASSERT_MSG(aTour.getTypePiece() == TOUR_TYPE, "TestPiece simple - typePiece");
	BOOST_ASSERT_MSG(aTour.getNumJoueur() == JOUEUR_1, "TestPiece simple - numJoueur");
	BOOST_ASSERT_MSG(aTour.getPosition() == aPosition, "TestPiece simple - position");
}

void TestPiece::testMovePiece(void) const{
	Position aPositionStart(2, 2);
	Position aPositionEnd(6, 2);
	Tour* aTour(new Tour(WHITE, aPositionStart));

	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	aEchiquier.addPiece(aTour);

	BOOST_ASSERT_MSG(aTour->getPosition() == aPositionStart, "TestPiece move - before Move");
	BOOST_ASSERT_MSG(aEchiquier.getCase(aPositionStart).hasPiece(), "TestPiece move - before move/verif case pos initiale");
	BOOST_ASSERT_MSG(!aEchiquier.getCase(aPositionEnd).hasPiece(), "TestPiece move - before move/verif case pas finale");

	aTour->movePiece(aPositionEnd);
	BOOST_ASSERT_MSG(aTour->getPosition() == aPositionEnd, "TestPiece simple - after Move");
	BOOST_ASSERT_MSG(!aEchiquier.getCase(aPositionStart).hasPiece(), "TestPiece move - after move/verif case pos initiale");
	BOOST_ASSERT_MSG(aEchiquier.getCase(aPositionEnd).hasPiece(), "TestPiece move - after move/verif case pas finale");
}

void TestPiece::testAliveDead(void) const {
	Position aPosition(2, 2);
	Tour aTour(WHITE, aPosition);

	BOOST_ASSERT_MSG(aTour.isAlive(), "TestPiece simple - alive");

	aTour.setDead();
	BOOST_ASSERT_MSG(!aTour.isAlive(), "TestPiece simple - dead");

	aTour.setAlive();
	BOOST_ASSERT_MSG(aTour.isAlive(), "TestPiece simple - alive/revive");
}

void TestPiece::testIsValideMove(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Position aPositionStart(2, 2);
	Position aPositionEnd(4, 2);
	Piece* aTour(new Tour(WHITE, aPositionStart));
	Move aMove(aPositionStart, aPositionEnd);

	aEchiquier.addPiece(aTour);

	BOOST_ASSERT_MSG(aTour->isValideMove(aMove), "TestPiece isValideMove - valid");

	aMove.setPositionStart(aPositionEnd);
	BOOST_ASSERT_MSG(!aTour->isValideMove(aMove), "TestPiece isValideMove - valid");

	aMove.setPositionStart(aPositionStart);
	BOOST_ASSERT_MSG(aTour->isValideMove(aMove), "TestPiece isValideMove - valid/no piece");

	Tour *aTour2(new Tour(BLACK, aPositionEnd));
	aEchiquier.addPiece(aTour2);
	BOOST_ASSERT_MSG(aTour->isValideMove(aMove), "TestPiece isValideMove - valid/piece different color");

	aTour2->setDead();
	BOOST_ASSERT_MSG(aTour->isValideMove(aMove), "TestPiece isValideMove - valid/piece dead");

	Tour *aTour3(new Tour(WHITE, aPositionEnd));
	aEchiquier.addPiece(aTour3);
	BOOST_ASSERT_MSG(!aTour->isValideMove(aMove), "TestPiece isValideMove - not valid/piece same color");

	aTour3->setDead();
	BOOST_ASSERT_MSG(aTour->isValideMove(aMove), "TestPiece isValideMove - valid/piece same color but dead");
}

void TestPiece::testCanTakeCase() const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Position aPositionStart(2, 2);
	Position aPositionEnd(4, 2);
	Piece* aTour(new Tour(WHITE, aPositionStart));
	Move aMove(aPositionStart, aPositionEnd);

	aEchiquier.addPiece(aTour);

	BOOST_ASSERT_MSG(aTour->canTakeCase(aMove.getEndPosition()), "TestPiece canTakeCase - valid/no piece");

	Tour *aTour2(new Tour(BLACK, aPositionEnd));
	aEchiquier.addPiece(aTour2);
	BOOST_ASSERT_MSG(aTour->canTakeCase(aMove.getEndPosition()), "TestPiece canTakeCase - valid/piece different color");

	aTour2->setDead();
	BOOST_ASSERT_MSG(aTour->canTakeCase(aMove.getEndPosition()), "TestPiece canTakeCase - valid/piece dead");

	Tour *aTour3(new Tour(WHITE, aPositionEnd));
	aEchiquier.addPiece(aTour3);
	BOOST_ASSERT_MSG(!aTour->canTakeCase(aMove.getEndPosition()), "TestPiece canTakeCase - not valid/piece same color");

	aTour3->setDead();
	BOOST_ASSERT_MSG(aTour->canTakeCase(aMove.getEndPosition()), "TestPiece canTakeCase - valid/piece same color but dead");
}
