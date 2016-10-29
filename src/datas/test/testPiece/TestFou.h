/*
 * TestFou.h
 *
 *  Created on: 29 oct. 2016
 *      Author: le_e
 */

#ifndef TESTFOU_H_
#define TESTFOU_H_

namespace datas {

class TestFou {
public:
	TestFou();
	virtual ~TestFou();

	static void startTests(void);

	void testIsValideMove(void) const;
};

} /* namespace datas */
#endif /* TESTFOU_H_ */
