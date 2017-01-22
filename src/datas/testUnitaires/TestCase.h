/*
 * TestCase.h
 *
 *  Created on: 13 nov. 2016
 *      Author: le_e
 */

#ifndef TESTCASE_H_
#define TESTCASE_H_

namespace datas {

class TestCase {
public:
	TestCase();
	virtual ~TestCase();

	static void startTest();

	void testSimple(void) const;
};

} /* namespace datas */
#endif /* TESTCASE_H_ */
