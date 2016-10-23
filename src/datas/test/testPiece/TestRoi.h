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

	bool testPionPeuxTuerLeRoi(const Position& iPositionFinaleMove, const Position& iPositionPion) const;
	bool testCavalierPeuxTuerLeRoi(const Position& iPositionFinaleMove, const Position& iPositionCavalier) const;
	bool testFouPeuxTuerLeRoi(const Position& iPositionFinaleMove, const Position& iPositionFou) const;
	bool testTourPeuxTuerLeRoi(const Position& iPositionFinaleMove, const Position& iPositionTour) const;
	bool testDamePeuxTuerLeRoi(const Position& iPositionFinaleMove, const Position& iPositionDame) const;
	bool testSecondRoiColle(const Position& iPositionFinaleMove, const Position& iPositionRoi) const;

};

} /* namespace datas */
#endif /* TESTROI_H_ */
