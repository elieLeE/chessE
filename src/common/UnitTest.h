/*
 * UnitTest.h
 *
 *  Created on: 30 oct. 2016
 *      Author: le_e
 */

#ifndef UNITTEST_H_
#define UNITTEST_H_

#include <list>
#include <string>

#include "../game/src/Echiquier.h"

namespace common{

class UnitTest {
public:
	UnitTest();
	virtual ~UnitTest();

	void resetEchiquier(void);

	game::Echiquier* aEchiquier;

private:

};

} /* namespace common */
#endif /* UNITTEST_H_ */
