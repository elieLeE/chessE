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

	void testMovePiece(void) const;

	void testEstMoveOKTheorique(void) const;
	void testEstMoveOKPratique(void) const;

	void testNormalMove(void) const;
	void testNormalMoveTheorique(void) const;
	void testNormalMovePratique(void) const;

	void testEstPetitRockTheorique(void) const;
	void testEstGrandRockTheorique(void) const;
	void testEstRockTheorique(void) const;
	void testEstRockPratique(void) const;

	void testCanBeKilled(void) const;
	void testCanAcccessCase(void) const;

	void testToStream(void) const;

};

} /* namespace datas */
#endif /* TESTROI_H_ */
