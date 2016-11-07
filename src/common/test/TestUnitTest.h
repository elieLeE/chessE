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

	void testA(void);
	void testB(void);
	void testC(void);
};

} /* namespace datas */
#endif /* TESTUNITTEST_H_ */
