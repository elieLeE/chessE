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
	cout << "test unitaire gui" << endl;

	TestGuiTerminal aTestGuiTerminal;

	aTestGuiTerminal.startTests();

	cout <<endl << "all OK" << endl;

	return 0;
}




