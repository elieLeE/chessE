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

	void startTests() const;

	void testComparePosition() const;
};

} /* namespace datas */
#endif /* TESTPOSITION_H_ */
