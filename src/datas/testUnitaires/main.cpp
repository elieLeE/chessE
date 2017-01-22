/*
 * maic.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include <iostream>
#include <boost/assert.hpp>

#include "../testUnitaires/testJoueur/testJoueurIA.h"
#include "../testUnitaires/testJoueur/TestJoueur.h"
#include "../testUnitaires/testJoueur/TestJoueurHumain.h"
#include "../testUnitaires/testPiece/TestCavalier.h"
#include "../testUnitaires/testPiece/TestDame.h"
#include "../testUnitaires/testPiece/TestFou.h"
#include "../testUnitaires/testPiece/TestPiece.h"
#include "../testUnitaires/testPiece/TestPion.h"
#include "../testUnitaires/testPiece/TestRoi.h"
#include "../testUnitaires/testPiece/TestTour.h"

#include "../testUnitaires/TestCase.h"
#include "../testUnitaires/TestMove.h"
#include "../testUnitaires/TestOptionsGame.h"
#include "../testUnitaires/TestPartie.h"
#include "../testUnitaires/TestPosition.h"

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

	cout << "all OK" << endl << endl;

	return 0;
}

