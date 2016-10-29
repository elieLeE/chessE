/*
 * TestCavalier.h
 *
 *  Created on: 29 oct. 2016
 *      Author: le_e
 */

#ifndef TESTCAVALIER_H_
#define TESTCAVALIER_H_

namespace datas {

class TestCavalier {
public:
	TestCavalier();
	virtual ~TestCavalier();

	static void startTests(void);

	void testCanAccess(void) const;
};

} /* namespace datas */
#endif /* TESTCAVALIER_H_ */
