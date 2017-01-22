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

	void testVerifSensMove(void) const;
	void testMovePiece(void) const;
	void testCanKillCasePiece(void) const;
	void testCanAccessCase(void) const;
	void testIsSimpleMove(void) const;
	void testIsSimpleCapture(void) const;
	void testIsPassantCapture(void) const;
	void testToStream(void) const;
};

} /* namespace datas */
#endif /* TESTPION_H_ */
