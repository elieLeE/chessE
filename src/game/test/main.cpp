/*
 * main.cpp
 *
 *  Created on: 28 sept. 2016
 *      Author: le_e
 */

#include <iostream>
#include <boost/shared_ptr.hpp>
#include <memory>

#include "TestEchiquier.h"

using namespace std;
using namespace game;

int main() {
	cout << "test unitaire game" << endl;

	TestEchiquier::startTest();

	/*boost::shared_ptr<int> x (new int(5));
	boost::shared_ptr<int> y;

	if(x){
		y = x;
		x.reset();
	}
	if(!x.get()){
	    cout << "ok" << endl;
	}
	if(y.get()){
	    cout << "ok" << endl;
	}*/

	cout << endl << "all OK" << endl;

	return 0;
}




