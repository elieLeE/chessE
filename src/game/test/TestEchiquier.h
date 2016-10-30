/*
 * TestEchiquier.h
 *
 *  Created on: 30 oct. 2016
 *      Author: le_e
 */

#ifndef TESTECHIQUIER_H_
#define TESTECHIQUIER_H_

namespace game{

class TestEchiquier {
public:
	TestEchiquier();
	virtual ~TestEchiquier();

	static void startTest(void);

	void testMovePiece(void) const;
};

} /* namespace datas */
#endif /* TESTECHIQUIER_H_ */
