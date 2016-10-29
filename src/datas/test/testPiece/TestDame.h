/*
 * TestDame.h
 *
 *  Created on: 29 oct. 2016
 *      Author: le_e
 */

#ifndef TESTDAME_H_
#define TESTDAME_H_

namespace datas {

class TestDame {
public:
	TestDame();
	virtual ~TestDame();

	static void startTests(void);

	void testIsValideMove(void) const;
};

} /* namespace datas */
#endif /* TESTDAME_H_ */
