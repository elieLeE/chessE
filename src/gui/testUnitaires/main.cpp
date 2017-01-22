/*
 * main.cpp
 *
 *  Created on: 28 sept. 2016
 *      Author: le_e
 */

#include <iostream>

#include "TestGuiTerminal.h"

using namespace std;
using namespace gui;

int main() {
	cout << "test unitaire gui" << endl << endl;

	TestGuiTerminal aTestGuiTerminal;

	aTestGuiTerminal.startTests();

	cout << "all OK" << endl << endl;

	return 0;
}




