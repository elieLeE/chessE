/*
 * TestPosition.h
 *
 *  Created on: 25 sept. 2016
 *      Author: le_e
 */

#ifndef TESTPOSITION_H_
#define TESTPOSITION_H_

namespace datas {

class TestPosition {
public:
	TestPosition();
	virtual ~TestPosition();

	static void startTests();

	void testDefaultConstructor(void) const;
	void testOperatorEgale(void) const;
	void testOperatorDifference(void) const;
	void testOperatorAffectation(void) const;
	void testSame(void) const;
	void testEvaluateDistance(void) const;
	void testDiffs(void) const;
	void testToStream(void) const;


};

} /* namespace datas */
#endif /* TESTPOSITION_H_ */
