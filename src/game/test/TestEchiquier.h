/*
 * TestEchiquier.h
 *
 *  Created on: 30 oct. 2016
 *      Author: le_e
 */

#ifndef TESTECHIQUIER_H_
#define TESTECHIQUIER_H_

#include "../../common/src/UnitTest.h"

namespace game{

class TestEchiquier {
public:
	TestEchiquier();
	virtual ~TestEchiquier();

	static void startTest(void);

	void testMovePiece(void) const;
	void testAddPiece(void);
	void testRemovePiece(void);
};

void test();

} /* namespace datas */
#endif /* TESTECHIQUIER_H_ */
