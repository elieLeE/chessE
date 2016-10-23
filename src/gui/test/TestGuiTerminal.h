/*
 * TestGuiTerminal.h
 *
 *  Created on: 16 oct. 2016
 *      Author: le_e
 */

#ifndef TESTGUITERMINAL_H_
#define TESTGUITERMINAL_H_

namespace gui {

class TestGuiTerminal {
public:
	TestGuiTerminal();
	virtual ~TestGuiTerminal();

	void startTests() const;

	void testDisplay() const;
};

} /* namespace gui */
#endif /* TESTGUITERMINAL_H_ */
