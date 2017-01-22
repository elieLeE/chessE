/*
 * TestMove.cpp
 *
 *  Created on: 12 nov. 2016
 *      Author: le_e
 */

#include "TestMove.h"

#include "../src/Move.h"
#include "../../common/src/UnitTest.h"
#include "../src/piece/Tour.h"
#include "../src/piece/Roi.h"
#include "../src/piece/Pion.h"

#include <sstream>

using namespace datas;
using namespace std;
using namespace common;

TestMove::TestMove()
{}

TestMove::~TestMove()
{}

void TestMove::startTests(){
	UnitTest<TestMove> unitT("TestMove");

	unitT.addMethod("testSimple", &datas::TestMove::testSimple);
	unitT.addMethod("testEvaluateDistance", &datas::TestMove::testEvaluateDistance);
	unitT.addMethod("testDefaultConstructor", &datas::TestMove::testDefaultConstructor);
	unitT.addMethod("testOperator =", &datas::TestMove::testOperatorAffectation);
	unitT.addMethod("testIsValideMove", &datas::TestMove::testIsValideMove);
	unitT.addMethod("testSetMoveProperties", &datas::TestMove::testSetMoveProperties);
	unitT.addMethod("testToStream", &datas::TestMove::testToStream);

	unitT.launchMethods();

}

void TestMove::testSimple(void) const{
	Position aPositionStart(2, 2);
	Position aPositionEnd(5, 6);
	Move aMove(aPositionStart, aPositionEnd);

	BOOST_ASSERT_MSG(aMove.getStartPosition() == aPositionStart, "TestMove simple - start position");
	BOOST_ASSERT_MSG(aMove.getEndPosition() == aPositionEnd, "TestMove simple - end position");
	BOOST_ASSERT_MSG(aMove.getCapturedPiece() == NO_TYPE, "TestMove simple - capturedPiece/NO_TYPE");
	BOOST_ASSERT_MSG(!aMove.hasCapturePiece(), "TestMove simple - not hasCapturedPiece");
	BOOST_ASSERT_MSG(aMove.getTypeMove() == NORMAL_MOVE, "TestMove simple - typeMove/NORMAL_MOVE");

	aMove.setPositionStart(aPositionEnd);
	BOOST_ASSERT_MSG(aMove.getStartPosition() == aPositionEnd, "TestMove simple - setStartPosition");

	aMove.setPositionEnd(aPositionStart);
	BOOST_ASSERT_MSG(aMove.getEndPosition() == aPositionStart, "TestMove simple - setEndPosition");

	aMove.setTypeMove(PETIT_ROCK);
	BOOST_ASSERT_MSG(aMove.getTypeMove() == PETIT_ROCK, "TestMove simple - capturedPiece/PETIT_ROCK");

	aMove.setCapturedPiece(TOUR_TYPE);
	BOOST_ASSERT_MSG(aMove.getCapturedPiece() == TOUR_TYPE, "TestMove simple - typeMove/PETIT_ROCK");
}

void TestMove::testDefaultConstructor(void) const{
	Move aMove;

	BOOST_ASSERT_MSG(aMove.getStartPosition() == Position(), "TestMove defaultConstructor - startPosition");
	BOOST_ASSERT_MSG(aMove.getEndPosition() == Position(), "TestMove defaultConstructor - endPosition");
	BOOST_ASSERT_MSG(aMove.getCapturedPiece() == NO_TYPE, "TestMove defaultConstructor - capturedPiece");
	BOOST_ASSERT_MSG(aMove.getTypeMove() == NORMAL_MOVE, "TestMove defaultConstructor - typeMove");
}

void TestMove::testEvaluateDistance(void) const{
	Position aPositionStart(2, 2);
	Position aPositionEnd(5, 6);
	Move aMove(aPositionStart, aPositionEnd);

	BOOST_ASSERT_MSG(aMove.evaluateDistance() == 25, "TestMove evaluateDistance");
}

void TestMove::testOperatorAffectation(void) const{
	Position aPositionStart(2, 2);
	Position aPositionEnd(5, 6);
	ETypeMove aTypeMove = GRAND_ROCK;
	ETypePiece aCapturedPiece = FOU_TYPE;

	Move aMove(aPositionStart, aPositionEnd, aCapturedPiece, aTypeMove);
	Move aMove2 = aMove;

	BOOST_ASSERT_MSG(aMove2.getStartPosition() == aPositionStart, "TestMove operator = - startPosition");
	BOOST_ASSERT_MSG(aMove2.getEndPosition() == aPositionEnd, "TestMove operator = - endPosition");
	BOOST_ASSERT_MSG(aMove2.getCapturedPiece() == aCapturedPiece, "TestMove operator = - capturedPiece");
	BOOST_ASSERT_MSG(aMove2.getTypeMove() == aTypeMove, "TestMove operator = - typeMove");
}

void TestMove::testIsValideMove(void) const{
	Position aPositionStart(-1, 6);
	Position aPositionEnd(4, -1);
	Move aMove(aPositionStart, aPositionEnd);

	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	BOOST_ASSERT_MSG(!aMove.isValid(aEchiquier), "TestMove isValideMove - startPosition not valid");

	aPositionStart.setPosition(2, 6);
	aMove.setPositionStart(aPositionStart);
	BOOST_ASSERT_MSG(!aMove.isValid(aEchiquier), "TestMove isValideMove - endPosition not valid");

	aMove.setPositionEnd(aPositionStart);
	BOOST_ASSERT_MSG(!aMove.isValid(aEchiquier), "TestMove isValideMove - startPosition = endPosition");

	aPositionEnd.setPosition(4, 6);
	aMove.setPositionEnd(aPositionEnd);
	BOOST_ASSERT_MSG(!aMove.isValid(aEchiquier), "TestMove isValideMove - case at endPosition has not piece");

	Tour *aTourBlack(new Tour(BLACK, Position(6, 6)));
	Tour *aTourWhite(new Tour(WHITE, Position(8, 1)));
	Roi *aRoi(new Roi(WHITE, Position(5, 1)));
	aEchiquier.addPiece(aTourBlack);
	aEchiquier.addPiece(aTourWhite);
	aEchiquier.addPiece(aRoi);
	aMove.setPositions(Position(5, 1), Position(7, 1));
	BOOST_ASSERT_MSG(!aMove.isValid(aEchiquier), "test isValideMove - rock move - king can be killed while move");

	aTourBlack->movePiece(Position(5, 6));
	aMove.setPositions(Position(8, 1), Position(7, 1));
	BOOST_ASSERT_MSG(!aMove.isValid(aEchiquier), "test isValideMove - king can be killed after move - already chess before");

	aTourBlack->setDead();
	BOOST_ASSERT_MSG(aMove.isValid(aEchiquier), "TestMove isValideMove - valid");

}

void TestMove::testSetMoveProperties(void) const{
	Position aPositionStart(3, 3);
	Position aPositionEnd(4, 3);
	Move aMove(aPositionStart, aPositionEnd);
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	//before setMoveProperties
	BOOST_ASSERT_MSG(!aMove.hasCapturePiece(), "TestMove capturedPiece - before setMoveProperties");
	BOOST_ASSERT_MSG(aMove.getTypeMove() == NORMAL_MOVE, "TestMove typeMove - before setMoveProperties");

	Tour *aTour(new Tour(WHITE, aPositionStart));
	Tour *aTour2(new Tour(WHITE, aPositionEnd));
	aEchiquier.addPiece(aTour);
	aEchiquier.addPiece(aTour2);
	aMove.setMoveProperties();

	//Normal move, with captured piece
	BOOST_ASSERT_MSG(aMove.hasCapturePiece(), "TestMove capturedPiece - hasCapturedPiece");
	BOOST_ASSERT_MSG(aMove.getTypeMove() == NORMAL_MOVE, "TestMove typeMove - NORMAL_MOVE");

	aMove.setCapturedPiece(NO_TYPE);
	aPositionStart.setPosition(5, 1);
	aPositionEnd.setPosition(7, 1);
	aMove.setPositions(aPositionStart, aPositionEnd);

	//petit rock move
	Roi *aRoi(new Roi(WHITE, aPositionStart));
	aEchiquier.addPiece(aRoi);
	aMove.setMoveProperties();
	BOOST_ASSERT_MSG(!aMove.hasCapturePiece(), "TestMove capturedPiece - PETIT_ROCK");
	BOOST_ASSERT_MSG(aMove.getTypeMove() == PETIT_ROCK, "TestMove typeMove - PETIT_ROCK");

	//grand rock move
	aMove.setPositionEnd(Position(3, 1));
	aMove.setMoveProperties();
	BOOST_ASSERT_MSG(!aMove.hasCapturePiece(), "TestMove capturedPiece - GRAND_ROCK");
	BOOST_ASSERT_MSG(aMove.getTypeMove() == GRAND_ROCK, "TestMove typeMove - GRAND_ROCK");

	// ??
	/*aPositionStart.setPosition(7, 7);
	aPositionEnd.setPosition(6, 5);
	aMove.setPositionStart(aPositionStart);
	aMove.setPositionEnd(aPositionEnd);
	Pion *aPion(new Pion(WHITE, aPositionStart, true));
	Pion *aPion2(new Pion(WHITE, aPositionEnd, true));
	aEchiquier.addPiece(aPion);
	aEchiquier.addPiece(aPion2);
	std::cout << aEchiquier;
	aMove.setMoveProperties();
	BOOST_ASSERT_MSG(aMove.hasCapturePiece(), "TestMove capturedPiece - NORMAL_MOVE/prise en passant");
	BOOST_ASSERT_MSG(aMove.getTypeMove() == NORMAL_MOVE, "TestMove typeMove - NORMAL_MOVE/prise en passant");*/

	//PRISE EN PASSANT
	aMove.setCapturedPiece(NO_TYPE);
	Pion *aPion(new Pion(WHITE, Position(7, 2), true));
	Pion *aPion2(new Pion(WHITE, Position(6, 4), true));
	aEchiquier.addPiece(aPion);
	aEchiquier.addPiece(aPion2);
	aPion->movePiece(Position(7, 4));
	aMove.setPositionStart(Position(6, 4));
	aMove.setPositionEnd(Position(7, 5));
	aMove.setMoveProperties();
	BOOST_ASSERT_MSG(aMove.hasCapturePiece(), "TestMove capturedPiece - PRISE_EN_PASSANT");
	BOOST_ASSERT_MSG(aMove.getTypeMove() == PRISE_EN_PASSANT, "TestMove typeMove - PRISE_EN_PASSANT");
}

void TestMove::testToStream(void) const{
	Position aPositionStart(2, 2);
	Position aPositionEnd(5, 6);
	Move aMove(aPositionStart, aPositionEnd);

	ostream aStream(0);
	stringbuf aStr;
	aStream.rdbuf(&aStr);

	aStream << aMove;

	string aExpected("start : (2, 2) / end : (5, 6)\n"
			"type : NORMAL_MOVE / capturedPiece : No Type\n");

	BOOST_ASSERT_MSG(aStr.str().compare(aExpected) == 0, "testMove toStream");
}


