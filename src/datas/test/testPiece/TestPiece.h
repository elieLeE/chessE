/*
 * TestPiece.h
 *
 *  Created on: 6 nov. 2016
 *      Author: le_e
 */

#ifndef TESTPIECE_H_
#define TESTPIECE_H_

#include "../../../common/UnitTest.h"

namespace datas {

class TestPiece : common::UnitTest{
public:
	TestPiece();
	virtual ~TestPiece();

	static void startTests(void);

	void testSimple(void);
	void testMovePiece(void) const;
	void testAliveDead(void) const ;
	void testIsValideMove(void) const;
	void testCanTakeCase() const;
};

} /* namespace datas */
#endif /* TESTPIECE_H_ */
