/*
 * testUnitTest.h
 *
 *  Created on: 6 nov. 2016
 *      Author: le_e
 */

#ifndef TESTUNITTEST_H_
#define TESTUNITTEST_H_

namespace common {

class TestUnitTest {
public:
	TestUnitTest();
	virtual ~TestUnitTest();

	static void startTests();

	void testA(void) const;
	void testB(void) const;
	void testC(void) const;
};

} /* namespace datas */
#endif /* TESTUNITTEST_H_ */
