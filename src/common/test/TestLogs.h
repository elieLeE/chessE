/*
 * TestLogs.h
 *
 *  Created on: 17 janv. 2017
 *      Author: le_e
 */

#ifndef COMMON_TEST_TESTLOGS_H_
#define COMMON_TEST_TESTLOGS_H_

namespace common {

class TestLogs {
public:
	TestLogs();
	virtual ~TestLogs();

	static void startTests();

	void testA(void) const;
};

}

#endif /* COMMON_TEST_TESTLOGS_H_ */
