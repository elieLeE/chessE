/*
 * maic.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include <iostream>
#include <boost/assert.hpp>

#include "TestPosition.h"
#include "TestCase.h"

#include "testPiece/TestPiece.h"
#include "testPiece/TestCavalier.h"
#include "testPiece/TestDame.h"
#include "testPiece/TestFou.h"
#include "testPiece/TestPion.h"
#include "testPiece/TestRoi.h"
#include "testPiece/TestTour.h"

#include "testJoueur/TestJoueur.h"
#include "testJoueur/testJoueurIA.h"
#include "testJoueur/TestJoueurHumain.h"

#include "TestMove.h"

using namespace std;
using namespace datas;

int main() {
	cout << "test unitaire datas" << endl << endl;

	TestPosition::startTests();
	TestCase::startTest();

	TestCavalier::startTests();
	TestDame::startTests();
	TestFou::startTests();
	TestPiece::startTests();
	TestPion::startTests();
	TestRoi::startTests();
	TestTour::startTests();

	TestMove::startTests();

	TestJoueur::startTests();
	TestJoueurHumain::startTests();
	testJoueurIA::startTests();

	cout << endl << "all OK" << endl;

	return 0;
}

