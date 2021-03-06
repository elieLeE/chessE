/*
 * maic.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include <iostream>
#include <boost/assert.hpp>

#include "testJoueur/testJoueurIA.h"
#include "testJoueur/TestJoueur.h"
#include "testJoueur/TestJoueurHumain.h"
#include "testPiece/TestCavalier.h"
#include "testPiece/TestDame.h"
#include "testPiece/TestFou.h"
#include "testPiece/TestPiece.h"
#include "testPiece/TestPion.h"
#include "testPiece/TestRoi.h"
#include "testPiece/TestTour.h"

#include "TestCase.h"
#include "TestFile.h"
#include "TestMove.h"
#include "TestOptionsGame.h"
#include "TestPartie.h"
#include "TestPosition.h"

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

	TestPartie::startTests();

	TestOptionsGame::startTests();

	TestFile::startTests();

	cout << "all OK" << endl << endl;

	return 0;
}

