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

void TestRoi::startTests(void){
	TestRoi aTestRoi;

	aTestRoi.testEstMoveOKTheorique();
	aTestRoi.testIsValidaMove();
	aTestRoi.testPionPeuxTuerLeRoi();
	aTestRoi.testEstPetitRock();
	aTestRoi.testEstGrandRock();
	std::cout << std::endl;
}

void TestRoi::testIsValidaMove(void) const{
	cout << "TestRoi - testIsValidaMove";

	cout << "	TO IMPLEMENT" << endl;
}

void TestRoi::testEstMoveOKTheorique(void) const{
	cout << "TestRoi - testEstMoveOKTheorique";

	Position aPositionStart(2, 5);
	Position aPositionEnd(3, 5);
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	aEchiquier.reset();

	Roi *aRoi = new Roi(WHITE, aPositionStart);

	aEchiquier.setPieceCaseXY(aPositionStart, aRoi);
	Move aMove(aPositionStart, aPositionEnd);
	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove)==NORMAL_MOVE, "test move theorique - normal move");

	cout << "	OK" << endl;
}

void TestRoi::testEstPetitRock(void) const{
	cout << "TestRoi - testEstPetitRock";

	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	aEchiquier.reset();

	Position aPositionStart(0, 4);
	Position aPositionTour(0, 7);
	Position aPositionEnd(0, 6);

	Roi *aRoi = new Roi(WHITE, aPositionStart);
	Tour *aTour1 = new Tour(WHITE, aPositionTour);
	Move aMove(aPositionStart, aPositionEnd);

	aEchiquier.setPieceCaseXY(aPositionStart, aRoi);
	aEchiquier.setPieceCaseXY(aPositionTour, aTour1);

	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove)==PETIT_ROCK, "test petit rock");

	cout << "	OK" << std::endl;
}

void TestRoi::testEstGrandRock(void) const{
	cout << "TestRoi - testEstGrandRock";

	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	aEchiquier.reset();

	Position aPositionStart(0, 4);
	Position aPositionEnd(0, 1);
	Position aPositionTour(0, 0);

	Roi *aRoi = new Roi(WHITE, aPositionStart);
	Tour *aTour1 = new Tour(WHITE, aPositionTour);
	Move aMove(aPositionStart, aPositionEnd);

	aEchiquier.setPieceCaseXY(aPositionStart, aRoi);
	aEchiquier.setPieceCaseXY(aPositionTour, aTour1);

	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove)==GRAND_ROCK, "test move theorique - grand rock");

	cout << "	OK" << std::endl;
}

void TestRoi::testPionPeuxTuerLeRoi(void) const{
	cout << "TestRoi - testPionPeuxTuerLeRoi";

	Position aPositionRoi(2, 5);
	Position aPositionPion(3, 4);
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	aEchiquier.reset();

	Roi *aRoi = new Roi(WHITE, aPositionRoi);
	aEchiquier.setPieceCaseXY(aPositionRoi, aRoi);

	Pion* aPion = new Pion(BLACK, aPositionPion, false);
	aEchiquier.setPieceCaseXY(aPositionPion, aPion);

	BOOST_ASSERT_MSG(aRoi->pionPeuxTuerLeRoi(aPositionRoi, aPositionPion), "test grand rock");

	cout << "	OK" << endl;
}

} /* namespace datas */
