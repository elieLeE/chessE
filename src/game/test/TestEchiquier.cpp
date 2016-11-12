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
	unitT.addMethod("testSetChangeMove", &game::TestEchiquier::testSetChangeMove);

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

	for(int i=0; i<NBRE_LIGNE; ++i){
		for(int j=0; j<NBRE_COLONNE; ++j){
			Position aPos(i, j);
			string aStr("TestEchiquier reset - hasNotPiece (" + std::to_string(i) + ", " + std::to_string(j) +")");
			BOOST_ASSERT_MSG(!aEchiquier.getCase(aPos).hasPiece(), aStr.c_str());
		}
	}
}

void TestEchiquier::testSetChangeMove(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Position aPositionStart(1, 5);
	Position aPositionEnd(2, 5);
	Move aMove(aPositionStart, aPositionEnd);
	datas::Pion* aPion(new datas::Pion(datas::WHITE, aPositionStart, true));

	aEchiquier.addPiece(aPion);

	aEchiquier.setChangeMove(aMove);
	BOOST_ASSERT_MSG(!aEchiquier.getPossiblePriseEnPassant(), "TestEchiquier setChangeMove - priseEnPassantNotPossible");

	aPositionEnd.setX(aPositionEnd.getX()+1);
	aMove.setPositionEnd(aPositionEnd);
	aEchiquier.setChangeMove(aMove);
	BOOST_ASSERT_MSG(aEchiquier.getPossiblePriseEnPassant(), "TestEchiquier setChangeMove - priseEnPassantPossible");

	BOOST_ASSERT_MSG(aEchiquier.getLastMove().getStartPosition() == aMove.getStartPosition(), "TestEchiquier setChangeMove - startPosition");
	BOOST_ASSERT_MSG(aEchiquier.getLastMove().getEndPosition() == aMove.getEndPosition(), "TestEchiquier setChangeMove - endPosition");
	BOOST_ASSERT_MSG(aEchiquier.getLastMove().getTypeMove() == aMove.getTypeMove(), "TestEchiquier setChangeMove - typeMove");
	BOOST_ASSERT_MSG(aEchiquier.getLastMove().getHasCapturedPiece() == aMove.getHasCapturedPiece(), "TestEchiquier setChangeMove - hasCapturedPiece");
}
