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

	void testComparePosition(void) const;
	void testSame(void) const;
	void testEvaluatePosition(void) const;
	void testToStream(void) const;

};

} /* namespace datas */
#endif /* TESTPOSITION_H_ */
