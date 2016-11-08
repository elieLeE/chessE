/*
 * TestRoi.cpp
 *
 *  Created on: 23 oct. 2016
 *      Author: le_e
 */

#include <iostream>
#include <boost/assert.hpp>

#include "../../../common/src/UnitTest.h"
#include "TestRoi.h"
#include "../../src/piece/Roi.h"
#include "../../src/piece/Pion.h"
#include "../../src/typeDefine/Color.h"
#include "../../../game/src/Echiquier.h"
#include "../../../gui/src/DisplayTerminal.h"

using namespace std;
using namespace datas;
using namespace common;

TestRoi::TestRoi()
{}

TestRoi::~TestRoi()
{}

void TestRoi::startTests(void){
	UnitTest<TestRoi> unitT("TestRoi");

	unitT.addMethod("testEstMoveOKTheorique", &datas::TestRoi::testEstMoveOKTheorique);
	unitT.addMethod("testIsValidaMove", &datas::TestRoi::testIsValidaMove, false);
	unitT.addMethod("testPionPeuxTuerLeRoi", &datas::TestRoi::testPionPeuxTuerLeRoi);
	unitT.addMethod("testEstPetitRock", &datas::TestRoi::testEstPetitRock);
	unitT.addMethod("testEstGrandRock", &datas::TestRoi::testEstGrandRock);

	unitT.luanchMethods();
}

void TestRoi::testIsValidaMove(void) const{
}

void TestRoi::testEstMoveOKTheorique(void) const{
	Position aPositionStart(2, 5);
	Position aPositionEnd(3, 5);
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Roi* aRoi(new Roi(WHITE, aPositionStart));

	aEchiquier.addPiece(aRoi);
	Move aMove(aPositionStart, aPositionEnd);
	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove)==NORMAL_MOVE, "test move theorique - normal move");
}

void TestRoi::testEstPetitRock(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Position aPositionStart(0, 4);
	Position aPositionTour(0, 7);
	Position aPositionEnd(0, 6);

	Roi* aRoi(new Roi(WHITE, aPositionStart));
	Tour* aTour1(new Tour(WHITE, aPositionTour));
	Move aMove(aPositionStart, aPositionEnd);

	aEchiquier.addPiece(aRoi);
	aEchiquier.addPiece(aTour1);

	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove)==PETIT_ROCK, "test petit rock");
}

void TestRoi::testEstGrandRock(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Position aPositionStart(0, 4);
	Position aPositionEnd(0, 1);
	Position aPositionTour(0, 0);

	Roi* aRoi(new Roi(WHITE, aPositionStart));
	Tour* aTour1(new Tour(WHITE, aPositionTour));
	Move aMove(aPositionStart, aPositionEnd);

	aEchiquier.addPiece(aRoi);
	aEchiquier.addPiece(aTour1);

	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove)==GRAND_ROCK, "test move theorique - grand rock");
}

void TestRoi::testPionPeuxTuerLeRoi(void) const{
	Position aPositionRoi(2, 5);
	Position aPositionPion(3, 4);
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	aEchiquier.reset();

	Roi* aRoi(new Roi(WHITE, aPositionRoi));
	aEchiquier.addPiece(aRoi);

	Pion* aPion(new Pion(BLACK, aPositionPion, false));
	aEchiquier.addPiece(aPion);

	BOOST_ASSERT_MSG(aRoi->pionPeuxTuerLeRoi(aPositionRoi, aPositionPion), "test grand rock");
}
