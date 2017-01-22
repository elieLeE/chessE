/*
 * TestMove.h
 *
 *  Created on: 12 nov. 2016
 *      Author: le_e
 */

#ifndef TESTMOVE_H_
#define TESTMOVE_H_

namespace datas {

class TestMove {
public:
	TestMove();
	virtual ~TestMove();

	static void startTests();

	void testSimple(void) const;
	void testEvaluateDistance(void) const;
	void testDefaultConstructor(void) const;
	void testOperatorAffectation(void) const;
	void testIsValideMove(void) const;
	void testSetMoveProperties(void) const;
	void testToStream(void) const;
};

} /* namespace datas */
#endif /* TESTMOVE_H_ */
