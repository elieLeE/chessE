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

	void testPionPeuxTuerLeRoi() const;
	void testCavalierPeuxTuerLeRoi() const;
	void testFouPeuxTuerLeRoi() const;
	void testTourPeuxTuerLeRoi() const;
	void testDamePeuxTuerLeRoi() const;
	void testSecondRoiColle() const;

	void test();

};

} /* namespace datas */
#endif /* TESTROI_H_ */
