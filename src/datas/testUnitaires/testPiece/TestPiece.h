/*
 * TestPiece.h
 *
 *  Created on: 6 nov. 2016
 *      Author: le_e
 */

#ifndef TESTPIECE_H_
#define TESTPIECE_H_

namespace datas {

class TestPiece {
public:
	TestPiece();
	virtual ~TestPiece();

	static void startTests(void);

	void testSimple(void) const;
	void testMovePiece(void) const;
	void testAliveDead(void) const ;
	void testIsValideMove(void) const;
	void testCanTakeCase() const;
	void testToStream(void) const;
};

} /* namespace datas */
#endif /* TESTPIECE_H_ */
