/*
 * testRoi.h
 *
 *  Created on: 23 oct. 2016
 *      Author: le_e
 */

#ifndef TESTROI_H_
#define TESTROI_H_

#include "../../src/Position.h"

namespace datas {

class TestRoi {
public:
	TestRoi();
	virtual ~TestRoi();

	static void startTests();

	void testIsValidaMove() const;

	void testEstMoveOKTheorique() const;
	void testEstMoveOKPratique() const;

	void testNormal(void) const;
	void testEstPetitRock(void) const;
	void testEstGrandRock(void) const;

	void testPionPeuxTuerLeRoi() const;
	void testCavalierPeuxTuerLeRoi() const;
	void testFouPeuxTuerLeRoi() const;
	void testTourPeuxTuerLeRoi() const;
	void testDamePeuxTuerLeRoi() const;
	void testSecondRoiColle() const;

};

} /* namespace datas */
#endif /* TESTROI_H_ */

/*cout << "TestRoi - testEstMoveOKTheorique";

	Position aPositionStart(2, 5);
	Position aPositionEnd(3, 5);
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	aEchiquier.reset();

	Roi *aRoi = new Roi(WHITE, aPositionStart);
	Tour *aTour1 = new Tour(WHITE, aPositionStart);
	Tour *aTour2 = new Tour(WHITE, aPositionStart);

	aEchiquier.setPieceCaseXY(0, 0, aTour1);
	aEchiquier.setPieceCaseXY(0, 7, aTour2);

	aEchiquier.setPieceCaseXY(aPositionStart, aRoi);
	Move aMove(aPositionStart, aPositionEnd);
	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove), "test move theorique - normal move");

	aPositionStart.setPosition(0, 4);
	aPositionEnd.setPosition(0, 7);
	aMove.setPositionStart(aPositionStart);
	aMove.setPositionEnd(aPositionEnd);
	aRoi->accessPosition() = aPositionStart;
	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove), "test move theorique - petit rock");

	aPositionEnd.setPosition(0, 0);
	aMove.setPositionEnd(aPositionEnd);
	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove), "test move theorique - grand rock");*/
