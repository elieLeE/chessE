/*
 * TestPion.h
 *
 *  Created on: 29 oct. 2016
 *      Author: le_e
 */

#ifndef TESTPION_H_
#define TESTPION_H_

namespace datas {

class TestPion {
public:
	TestPion();
	virtual ~TestPion();

	static void startTests(void);

	void testSimple(void) const;
	void testMovePiece(void) const;
	void testCanAccessCase(void) const;
	void testIsValideMove(void) const;
	void testToStream(void) const;
};

} /* namespace datas */
#endif /* TESTPION_H_ */
