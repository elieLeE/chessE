/*
 * TestPion.cpp
 *
 *  Created on: 29 oct. 2016
 *      Author: le_e
 */
#include <iostream>
#include <sstream>

#include "../../../common/src/UnitTest.h"
#include "TestPion.h"
#include "../../src/piece/Pion.h"
#include "../../src/piece/Tour.h"
#include "../../src/piece/Dame.h"

#include "../../../common/src/DisplayType.h"

using namespace std;
using namespace datas;
using namespace common;

TestPion::TestPion()
{}

TestPion::~TestPion()
{}

void TestPion::startTests(void){
	UnitTest<TestPion> unitT("TestPion");

	unitT.addMethod("testMovePiece", &datas::TestPion::testMovePiece);
	unitT.addMethod("testVerifSensMove", &datas::TestPion::testVerifSensMove);
	unitT.addMethod("testCanAccessCase", &datas::TestPion::testCanAccessCase);
	unitT.addMethod("testIsSimpleMove", &datas::TestPion::testIsSimpleMove);
	unitT.addMethod("testIsSimpleCapture", &datas::TestPion::testIsSimpleCapture);
	unitT.addMethod("testIsPassantCapture", &datas::TestPion::testIsPassantCapture);
	unitT.addMethod("testCanKillCasePiece", &datas::TestPion::testCanKillCasePiece);
	unitT.addMethod("testToStream", &datas::TestPion::testToStream);

	unitT.launchMethods();
}

void TestPion::testMovePiece(void) const{
	Position aPositionStart(7, 2);
	Position aPositionEnd(7, 3);
	Pion aPion(WHITE, aPositionStart, true);

	BOOST_ASSERT_MSG(!aPion.hasAlreadyMoved(), "TestPion movePiece - hasAlreadyMoved false");
	BOOST_ASSERT_MSG(aPion.getPosition() == aPositionStart, "TestPion movePiece - position before move");

	aPion.movePiece(aPositionEnd);
	BOOST_ASSERT_MSG(aPion.hasAlreadyMoved(), "TestPion movePiece - hasAlreadyMoved true");
	BOOST_ASSERT_MSG(aPion.getPosition() == aPositionEnd, "TestPion movePiece - position after move");
}

void TestPion::testVerifSensMove(void) const{
	Position aPositionStart(7, 2);
	Position aPositionEnd(7, 3);
	Pion aPion(WHITE, aPositionStart, true);

	BOOST_ASSERT_MSG(aPion.verifSensMove(aPositionEnd), "TestPion verifSensMove - sens croissant / move OK");

	aPositionEnd.setPosition(7, 1);
	BOOST_ASSERT_MSG(!aPion.verifSensMove(aPositionEnd), "TestPion verifSensMove - sens croissant / move not OK");

	aPositionEnd.setPosition(7, 3);
	Pion aPion2(BLACK, aPositionStart, false);
	BOOST_ASSERT_MSG(!aPion2.verifSensMove(aPositionEnd), "TestPion verifSensMove - sens decroissant / move not OK");

	aPositionEnd.setPosition(7, 1);
	BOOST_ASSERT_MSG(aPion2.verifSensMove(aPositionEnd), "TestPion verifSensMove - sens decroissant / move OK");
}

void TestPion::testIsSimpleMove(void) const{
	game::Echiquier & aEchiquier = game::Echiquier::accessInstance();
	Position aPositionStart(4, 2);
	Position aPositionEnd(4, 3);

	Move aMove;

	Pion *aPion(new Pion(WHITE, aPositionStart, true));
	aEchiquier.addPiece(aPion);

	//=> Pion move one case forward
	aPositionEnd.setPosition(4, 3);
	aMove = Move(aPositionStart, aPositionEnd);
	BOOST_ASSERT_MSG(aPion->isSimpleMove(aMove.getEndPosition(), aEchiquier), "testPion canAccessCase - valid move one case never moved");

	//=> Pion move two cases forward, correct
	aPositionEnd.setPosition(4, 4);
	aMove = Move(aPositionStart, aPositionEnd);
	BOOST_ASSERT_MSG(aPion->isSimpleMove(aMove.getEndPosition(), aEchiquier), "testPion isSimpleMove - valid move two cases never move");

	//=> Pion move two cases forward but incorrect
	aPion->movePiece(aPositionEnd);
	aPositionStart = aPositionEnd;
	aPositionEnd.setPosition(4, 6);
	aMove = Move(aPositionStart, aPositionEnd);
	BOOST_ASSERT_MSG(!aPion->isSimpleMove(aMove.getEndPosition(), aEchiquier), "testPion isSimpleMove - valid move two cases already move/not valid");

	//=> Pion move one case forward after already moved
	aPositionEnd.setPosition(4, 5);
	aMove = Move(aPositionStart, aPositionEnd);
	BOOST_ASSERT_MSG(aPion->isSimpleMove(aMove.getEndPosition(), aEchiquier), "testPion isSimpleMove - valid move one case already move");
}

void TestPion::testIsSimpleCapture(void) const{
	game::Echiquier & aEchiquier = game::Echiquier::accessInstance();
	Position aPositionStart(1, 4);
	Position aPositionEnd(3, 4);

	Move aMove;

	Pion *aPionCible1(new Pion(WHITE, Position(2, 3), false));
	Pion *aPionCible2(new Pion(WHITE, Position(3, 4), false));
	Pion *aPion(new Pion(WHITE, aPositionStart, true));

	aEchiquier.addPiece(aPionCible1);
	aEchiquier.addPiece(aPionCible2);
	aEchiquier.addPiece(aPion);

	//right taken / correct
	aPositionEnd.setPosition(2, 3);
	aMove = Move(aPositionStart, aPositionEnd);
	BOOST_ASSERT_MSG(aPion->isSimpleCapture(aMove.getEndPosition(), aEchiquier), "testPion isSimpleCapture - valid move take pion left");
	/*BOOST_ASSERT_MSG(aPion->verifSensMove(aMove.getEndPosition()), "testPion isPassantCapture - verifSensMove");
	BOOST_ASSERT_MSG(aPion->canAccessCase(aMove.getEndPosition()), "testPion isPassantCapture - canAccessCase - valid move take pion left");*/

	//left taken / correct
	aPion->movePiece(aPositionEnd);
	aPositionStart = aPositionEnd;
	aPositionEnd.setPosition(3, 4);
	aMove = Move(aPositionStart, aPositionEnd);
	BOOST_ASSERT_MSG(aPion->isSimpleCapture(aMove.getEndPosition(), aEchiquier), "testPion isSimpleCapture - valid move take pion right");
	//BOOST_ASSERT_MSG(aPion->canAccessCase(aMove.getEndPosition()), "testPion isPassantCapture - canAccessCase - valid move take pion right");

	//right taken / incorrect
	aPion->movePiece(aPositionEnd);
	aPositionStart = aPositionEnd;
	aPositionEnd.setPosition(4, 3);
	aMove = Move(aPositionStart, aPositionEnd);
	BOOST_ASSERT_MSG(!aPion->isSimpleCapture(aMove.getEndPosition(), aEchiquier), "testPion isSimpleCapture - valid move take pion right/not valid");
	//BOOST_ASSERT_MSG(aPion->canAccessCase(aMove.getEndPosition()), "testPion isPassantCapture - canAccessCase - valid move take pion right/not valid");

	//left taken / incorrect
	aPositionEnd.setPosition(4, 5);
	aMove = Move(aPositionStart, aPositionEnd);
	BOOST_ASSERT_MSG(!aPion->isSimpleCapture(aMove.getEndPosition(), aEchiquier), "testPion isSimpleCapture - valid move take pion left/not valid");
	//BOOST_ASSERT_MSG(!aPion->isSimpleCapture(aMove.getEndPosition(), aEchiquier), "testPion isSimpleCapture - valid move take pion left/not valid");
}

void TestPion::testIsPassantCapture(void) const{
	game::Echiquier & aEchiquier = game::Echiquier::accessInstance();

	Position aPositionStart(5, 4);
	Position aPositionEnd(4, 3);

	Move aMove;

	Pion *aPion1(new Pion(WHITE, Position(4, 2), true));
	Pion *aPion2(new Pion(BLACK, Position(5, 4), false));

	aEchiquier.addPiece(aPion1);
	aEchiquier.addPiece(aPion2);

	//prise en passant not valid => deux simples move d'une case consecutifs
	aMove.setPositions(Position(4, 2), Position(4, 3));
	aEchiquier.doChangeMove(aMove);
	aMove.setPositions(Position(4, 3), Position(4, 4));
	aEchiquier.doChangeMove(aMove);
	BOOST_ASSERT_MSG(!aPion2->isPassantCapture(aMove.getEndPosition(), aEchiquier), "testPion isPassantCapture - previous move not double");

	//prise en passant correct, sens croissant / left
	aPion1->movePiece(Position(4, 2));
	aMove.setPositions(Position(4, 2), Position(4, 4));
	aEchiquier.doChangeMove(aMove);
	aMove.setPositions(Position(5, 4), Position(4, 3));
	BOOST_ASSERT_MSG(aPion2->isPassantCapture(aMove.getEndPosition(), aEchiquier), "testPion isPassantCapture - sens croissant / left - OK");
	BOOST_ASSERT_MSG(aPion2->canAccessCase(aMove.getEndPosition()), "testPion isPassantCapture - canAccessCase - sens croissant / left - OK");

	//prise en passant correct, sens croissant / right
	aEchiquier.accessCase(Position(5, 4)).accessPiece()->movePiece(Position(3, 4));
	aPion1->movePiece(Position(4, 2));
	aMove.setPositions(Position(4, 2), Position(4, 4));
	aEchiquier.doChangeMove(aMove);
	aMove.setPositions(Position(3, 4), Position(4, 3));
	BOOST_ASSERT_MSG(aPion2->isPassantCapture(aMove.getEndPosition(), aEchiquier), "testPion isPassantCapture - sens croissant / right - OK");
	BOOST_ASSERT_MSG(aPion2->canAccessCase(aMove.getEndPosition()), "testPion isPassantCapture - canAccessCase - sens croissant / right - OK");

	Pion *aPion3(new Pion(WHITE, Position(7, 7), false));
	Pion *aPion4(new Pion(BLACK, Position(6, 5), true));
	aEchiquier.addPiece(aPion3);
	aEchiquier.addPiece(aPion4);

	//prise en passant correct, sens decroissant / left
	aMove.setPositions(Position(7, 7), Position(7, 5));
	aEchiquier.doChangeMove(aMove);
	aMove.setPositions(Position(6, 5), Position(7, 6));
	BOOST_ASSERT_MSG(aPion4->isPassantCapture(aMove.getEndPosition(), aEchiquier), "testPion isPassantCapture - sens decroissant / right - OK");
	BOOST_ASSERT_MSG(aPion4->canAccessCase(aMove.getEndPosition()), "testPion isPassantCapture - canAccessCase - sens decroissant / right - OK");

	//prise en passant correct, sens decroissant / right
	aEchiquier.accessCase(Position(7, 5)).accessPiece()->movePiece(Position(6, 7));
	aEchiquier.accessCase(Position(6, 5)).accessPiece()->movePiece(Position(7, 5));
	aMove.setPositions(Position(6, 7), Position(6, 5));
	aEchiquier.doChangeMove(aMove);
	aMove.setPositions(Position(7, 5), Position(6, 6));
	BOOST_ASSERT_MSG(aPion4->isPassantCapture(aMove.getEndPosition(), aEchiquier), "testPion isPassantCapture - sens decroissant / left - OK");
	BOOST_ASSERT_MSG(aPion4->canAccessCase(aMove.getEndPosition()), "testPion isPassantCapture - canAccessCase - sens decroissant / left - OK");
}

void TestPion::testCanAccessCase(void) const{
	game::Echiquier & aEchiquier = game::Echiquier::accessInstance();

	Position aPositionStart(4, 2);
	Position aPositionEnd(4, 3);

	Move aMove;

	Pion *aPionSensCroissant(new Pion(WHITE, aPositionStart, true));
	Pion *aPionSensDecroissant(new Pion(WHITE, aPositionStart, false));

	//simpleMove
	aMove.setPositions(aPositionStart, aPositionEnd);
	BOOST_ASSERT_MSG(aPionSensCroissant->isSimpleMove(aMove.getEndPosition(), aEchiquier), "testPion canAccessCase - simpleMove - sens croissant");
	BOOST_ASSERT_MSG(aPionSensDecroissant->isSimpleMove(aMove.getEndPosition(), aEchiquier), "testPion canAccessCase - simpleMove - sens decroissant");
	BOOST_ASSERT_MSG(aPionSensCroissant->canAccessCase(aMove.getEndPosition()), "testPion canAccessCase - simpleMove/canAccessCase - sens croissant");
	BOOST_ASSERT_MSG(!aPionSensDecroissant->canAccessCase(aMove.getEndPosition()), "testPion canAccessCase - simpleMove/canAccessCase - sens decroissant");

	//SimpleCapture
	Tour *aTourCibleSensCroissant1(new Tour(WHITE, Position(2, 4)));
	Dame *aDameCibleSensDecroissant1(new Dame(WHITE, Position(2, 2)));
	Tour *aTourCibleSensCroissant2(new Tour(WHITE, Position(7, 5)));
	Dame *aDameCibleSensDecroissant2(new Dame(WHITE, Position(7, 7)));

	aPionSensCroissant->accessPosition().setPosition(3, 3);
	aPionSensDecroissant->accessPosition().setPosition(6, 6);

	aEchiquier.addPiece(aTourCibleSensCroissant1);
	aEchiquier.addPiece(aTourCibleSensCroissant2);
	aEchiquier.addPiece(aDameCibleSensDecroissant1);
	aEchiquier.addPiece(aDameCibleSensDecroissant2);
	aEchiquier.addPiece(aPionSensCroissant);
	aEchiquier.addPiece(aPionSensDecroissant);

	aMove.setPositions(aPionSensCroissant->getPosition(), aDameCibleSensDecroissant1->getPosition());
	BOOST_ASSERT_MSG(aPionSensCroissant->isSimpleCapture(aMove.getEndPosition(), aEchiquier), "testPion canAccessCase - simpleCapture - sens croissant OK 1");
	BOOST_ASSERT_MSG(!aPionSensCroissant->canAccessCase(aMove.getEndPosition()), "testPion canAccessCase - simpleMove/canAccessCase - sens croissant OK");

	aMove.setPositions(aPionSensCroissant->getPosition(), aTourCibleSensCroissant1->getPosition());
	BOOST_ASSERT_MSG(aPionSensCroissant->isSimpleCapture(aMove.getEndPosition(), aEchiquier), "testPion canAccessCase - simpleCapture - sens croissant OK 2");
	BOOST_ASSERT_MSG(aPionSensCroissant->canAccessCase(aMove.getEndPosition()), "testPion canAccessCase - simpleMove/canAccessCase - sens croissant KO");

	aMove.setPositions(aPionSensDecroissant->getPosition(), aDameCibleSensDecroissant2->getPosition());
	BOOST_ASSERT_MSG(aPionSensDecroissant->isSimpleCapture(aMove.getEndPosition(), aEchiquier), "testPion canAccessCase - simpleCapture - sens decroissant OK 1");
	BOOST_ASSERT_MSG(!aPionSensDecroissant->canAccessCase(aMove.getEndPosition()), "testPion canAccessCase - simpleMove/canAccessCase - sens decroissant OK");

	aMove.setPositions(aPionSensDecroissant->getPosition(), aTourCibleSensCroissant2->getPosition());
	BOOST_ASSERT_MSG(aPionSensDecroissant->isSimpleCapture(aMove.getEndPosition(), aEchiquier), "testPion canAccessCase - simpleCapture - sens decroissant OK 2");
	BOOST_ASSERT_MSG(aPionSensDecroissant->canAccessCase(aMove.getEndPosition()), "testPion canAccessCase - simpleMove/canAccessCase - sens decroissant KO");
}

void TestPion::testCanKillCasePiece(void) const{
	Pion aPion(WHITE, Position(2, 2), true);

	BOOST_ASSERT_MSG(!aPion.canKillCasePiece(Position(5, 5)), "testPion CanKillCasePiece - wrong position - not accessible");
	BOOST_ASSERT_MSG(!aPion.canKillCasePiece(Position(3, 2)), "testPion CanKillCasePiece - wrong position - not diagonal");
	BOOST_ASSERT_MSG(!aPion.canKillCasePiece(Position(1, 1)), "testPion CanKillCasePiece - wrong position - wrong way");
	BOOST_ASSERT_MSG(aPion.canKillCasePiece(Position(3, 3)), "testPion CanKillCasePiece - OK");
}

void TestPion::testToStream(void) const{
	ostream aStream(0);
	stringbuf aStr;
	aStream.rdbuf(&aStr);

	Position aPosition(5, 5);
	Pion aPion(WHITE, aPosition, true);

	aStream << aPion;

	string aExpected("type : Pion\n"
			"pos : (5, 5)\n"
			"color : WHITE\n"
			"numJ : JOUEUR_1\n"
			"alive ? true\n"
			"value : 1\n"
			"sens croissant ? true\n"
			"already moved ? false\n");

	BOOST_ASSERT_MSG(aStr.str().compare(aExpected) == 0, "testPion toStream");
}
