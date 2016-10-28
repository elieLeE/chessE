/*
 * TestTour.h
 *
 *  Created on: 28 oct. 2016
 *      Author: le_e
 */

#ifndef TESTTOUR_H_
#define TESTTOUR_H_

namespace datas {

class TestTour {
public:
	TestTour();
	virtual ~TestTour();

	static void startTests(void);

	void testIsValideMove(void) const;
	void testCanAccess(void) const;
	void testMovePiece(void) const;
};

} /* namespace datas */
#endif /* TESTTOUR_H_ */
