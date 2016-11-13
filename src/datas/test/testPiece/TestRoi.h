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

	static void startTests(void);

	void testSimple(void) const;

	void testIsValidaMove(void) const;

	void testEstMoveOKTheorique(void) const;
	void testEstMoveOKPratique(void) const;

	void testNormal(void) const;
	void testEstPetitRock(void) const;
	void testEstGrandRock(void) const;

	void testPionPeuxTuerLeRoi(void) const;
	void testCavalierPeuxTuerLeRoi(void) const;
	void testFouPeuxTuerLeRoi(void) const;
	void testTourPeuxTuerLeRoi(void) const;
	void testDamePeuxTuerLeRoi(void) const;
	void testSecondRoiColle(void) const;

	void testToStream(void) const;

};

} /* namespace datas */
#endif /* TESTROI_H_ */
