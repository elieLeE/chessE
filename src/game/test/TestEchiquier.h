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
	void testAddPiece(void) const;
	void testKillAndRevivePiece(void) const;
	void testReset(void) const;
	void testDoChangeMove(void) const;
	void testToStream(void) const;
};

} /* namespace datas */
#endif /* TESTECHIQUIER_H_ */
