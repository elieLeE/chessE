/*
 * TestEchiquier.cpp
 *
 *  Created on: 30 oct. 2016
 *      Author: le_e
 */
#include <iostream>

#include "TestEchiquier.h"
#include "../src/Echiquier.h"
#include "../../datas/src/Position.h"
#include "../../datas/src/piece/Tour.h"
#include "../../datas/src/piece/Pion.h"
#include "../../common/src/UnitTest.h"

using namespace std;
using namespace game;
using namespace datas;
using namespace common;

TestEchiquier::TestEchiquier()
{}

TestEchiquier::~TestEchiquier()
{}

void TestEchiquier::startTest(){
	UnitTest<TestEchiquier> unitT("TestEchiquier");

	unitT.addMethod("testAddPiece", &game::TestEchiquier::testAddPiece);
	unitT.addMethod("testKillAndRevivePiece", &game::TestEchiquier::testKillAndRevivePiece);
	unitT.addMethod("testMovePiece", &game::TestEchiquier::testMovePiece);
	unitT.addMethod("testReset", &game::TestEchiquier::testReset);
	unitT.addMethod("testDoChangeMove", &game::TestEchiquier::testDoChangeMove);
	unitT.addMethod("testToStream", &game::TestEchiquier::testToStream);

	unitT.launchMethods();
}

void TestEchiquier::testAddPiece(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Position aPosition(2, 5);
	Tour *aTour = new Tour(WHITE, aPosition);
	aEchiquier.addPiece(aTour);

	BOOST_ASSERT_MSG(aEchiquier.getCase(aPosition).hasPiece(), "TestEchiquier addPiece - hasPiece");
	BOOST_ASSERT_MSG(!aEchiquier.getCase(Position(aPosition).getX()+1, aPosition.getY()).hasPiece(), "TestEchiquier addPiece - hasNotPiece");
}

//egalement RevicePiece
void TestEchiquier::testKillAndRevivePiece(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Position aPosition(2, 3);
	Tour* aTour(new Tour(WHITE, aPosition));

	aEchiquier.addPiece(aTour);
	BOOST_ASSERT_MSG(aEchiquier.getCase(aPosition).hasPiece(), "TestEchiquier killAndRevivePiece - addPiece");

	aEchiquier.killPiece(aPosition);
	BOOST_ASSERT_MSG(!aEchiquier.getCase(aPosition).hasPiece(), "TestEchiquier killAndRevivePiece - killPiece");


	aEchiquier.revivePiece(aPosition);
	BOOST_ASSERT_MSG(aEchiquier.getCase(aPosition).hasPiece(), "TestEchiquier killAndRevivePiece - revivePiece");
}

void TestEchiquier::testMovePiece(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Position aPositionStart(2, 2);
	Position aPositionEnd(2, 7);
	PiecePtr aTour(new Tour(WHITE, aPositionStart));

	aEchiquier.addPiece(aTour);
	BOOST_ASSERT_MSG(aEchiquier.getCase(aPositionStart).hasPiece(), "TestEchiquier addPiece - hasPiece");

	aEchiquier.movePiece(aPositionStart, aPositionEnd);
	BOOST_ASSERT_MSG(aEchiquier.getCase(aPositionEnd).getPiece()->getPosition() == aPositionStart, "TestEchiquier movePiece - position == positionStart");
	BOOST_ASSERT_MSG(aEchiquier.getCase(aPositionEnd).hasPiece(), "TestEchiquier movePiece - hasPiece");
	BOOST_ASSERT_MSG(!aEchiquier.getCase(aPositionStart).hasPiece(), "TestEchiquier movePiece - hasNotPiece");
}

void TestEchiquier::testReset(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	aEchiquier.setBegginingGameWithoutHandicap();
	aEchiquier.reset();

	for(int i=1; i<=NBRE_LIGNE; ++i){
		for(int j=1; j<=NBRE_COLONNE; ++j){
			Position aPos(i, j);
			string aStr("TestEchiquier reset - hasNotPiece (" + std::to_string(i) + ", " + std::to_string(j) +")");
			BOOST_ASSERT_MSG(!aEchiquier.getCase(aPos).hasPiece(), aStr.c_str());
		}
	}
}

void TestEchiquier::testDoChangeMove(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Position aPositionStart(1, 1);
	Position aPositionEnd(1, 2);
	Move aMove(aPositionStart, aPositionEnd);
	datas::Pion* aPion(new datas::Pion(datas::WHITE, aPositionStart, true));

	aEchiquier.addPiece(aPion);

	aEchiquier.doChangeMove(aMove);
	BOOST_ASSERT_MSG(!aEchiquier.getPossiblePriseEnPassant(), "TestEchiquier doChangeMove - priseEnPassantNotPossible");

	aPositionEnd.setY(aPositionEnd.getY()+1);
	aMove.setPositionEnd(aPositionEnd);
	aPion->movePiece(aPositionStart);
	aEchiquier.doChangeMove(aMove);
	BOOST_ASSERT_MSG(aEchiquier.getPossiblePriseEnPassant(), "TestEchiquier doChangeMove - priseEnPassantPossible");

	BOOST_ASSERT_MSG(aEchiquier.getLastMove().getStartPosition() == aMove.getStartPosition(), "TestEchiquier doChangeMove - startPosition");
	BOOST_ASSERT_MSG(aEchiquier.getLastMove().getEndPosition() == aMove.getEndPosition(), "TestEchiquier doChangeMove - endPosition");
	BOOST_ASSERT_MSG(aEchiquier.getLastMove().getTypeMove() == aMove.getTypeMove(), "TestEchiquier doChangeMove - typeMove");
	BOOST_ASSERT_MSG(aEchiquier.getLastMove().getCapturedPiece() == aMove.getCapturedPiece(), "TestEchiquier doChangeMove - hasCapturedPiece");
}

void TestEchiquier::testToStream(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	std::stringstream aStr;

	aEchiquier.setBegginingGameWithoutHandicap();

	aStr << aEchiquier;
	string aExpected(""
			"\nechiquier : \n"
			" 8| T | C | F | R | D | F | C | T |\n"
			" 7| P | P | P | P | P | P | P | P |\n"
			" 6|   |   |   |   |   |   |   |   |\n"
			" 5|   |   |   |   |   |   |   |   |\n"
			" 4|   |   |   |   |   |   |   |   |\n"
			" 3|   |   |   |   |   |   |   |   |\n"
			" 2| P | P | P | P | P | P | P | P |\n"
			" 1| T | C | F | D | R | F | C | T |\n"
			"  --------------------------------\n"
			"    a   b   c   d   e   f   g   h\n"
			"    1   2   3   4   5   6   7   8\n"
			"\n");

	BOOST_ASSERT_MSG(aExpected.compare(aStr.str())==0, "testEchiquier ToStream");
}
