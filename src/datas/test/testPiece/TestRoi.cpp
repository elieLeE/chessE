/*
 * TestRoi.cpp
 *
 *  Created on: 23 oct. 2016
 *      Author: le_e
 */

#include <iostream>
#include <boost/assert.hpp>

#include "TestRoi.h"
#include "../../src/piece/Roi.h"
#include "../../src/piece/Pion.h"
#include "../../src/typeDefine/Color.h"
#include "../../../game/src/Echiquier.h"

#include "../../../gui/src/DisplayTerminal.h"

using namespace std;

namespace datas {

TestRoi::TestRoi()
{}

TestRoi::~TestRoi()
{}

void TestRoi::startTests(){
	TestRoi aTestRoi;

	aTestRoi.testEstMoveOKTheorique();
	aTestRoi.testIsValidaMove();
	aTestRoi.testPionPeuxTuerLeRoi();
}

void TestRoi::testIsValidaMove() const{
	cout << "TestRoi - testIsValidaMove";

	cout << "	TO IMPLEMENT" << endl;
}

void TestRoi::testEstMoveOKTheorique() const{
	cout << "TestRoi - testEstMoveOKTheorique";

	Position aPositionStart(2, 5);
	Position aPositionEnd(3, 5);
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	aEchiquier.reset();

	Roi *aRoi = new Roi(WHITE, aPositionStart);

	aEchiquier.setPieceCaseXY(aPositionStart, aRoi);
	Move aMove(aPositionStart, aPositionEnd);
	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove), "test move theorique - move normal");

	aPositionStart.setPosition(0, 4);
	aPositionEnd.setPosition(0, 6);
	aMove.setPositionStart(aPositionStart);
	aMove.setPositionEnd(aPositionEnd);
	aRoi->movePiece(aPositionStart);
	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove), "test move theorique - petit rock");

	aPositionEnd.setPosition(0, 1);
	aMove.setPositionEnd(aPositionEnd);
	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove), "test move theorique - grand rock");

	cout << "	OK" << endl;
}

void TestRoi::testPionPeuxTuerLeRoi() const{
	cout << "TestRoi - testPionPeuxTuerLeRoi";

	Position aPositionRoi(2, 5);
	Position aPositionPion(3, 4);
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	aEchiquier.reset();

	Roi *aRoi = new Roi(WHITE, aPositionRoi);
	aEchiquier.setPieceCaseXY(aPositionRoi, aRoi);

	Pion* aPion = new Pion(BLACK, aPositionPion, false);
	aEchiquier.setPieceCaseXY(aPositionPion, aPion);

	BOOST_ASSERT_MSG(aRoi->pionPeuxTuerLeRoi(aPositionRoi, aPositionPion), "test move theorique - grand rock");

	cout << "	OK" << endl;
}

} /* namespace datas */
