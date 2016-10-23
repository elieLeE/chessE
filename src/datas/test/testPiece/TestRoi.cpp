/*
 * TestRoi.cpp
 *
 *  Created on: 23 oct. 2016
 *      Author: le_e
 */

#include <iostream>

#include "TestRoi.h"
#include "../../src/piece/Roi.h"
#include "../../src/typeDefine/Color.h"
#include "../../../game/src/EtatGame.h"

using namespace std;

namespace datas {

TestRoi::TestRoi()
{}

TestRoi::~TestRoi()
{}

void TestRoi::startTests(){
	TestRoi aTestRoi;

	aTestRoi.testEstMoveOKTheorique();
	aTestRoi.testIsValidaMove();
}

void TestRoi::testIsValidaMove() const{
	cout << "TestRoi - testIsValidaMove";

	cout << "	TO IMPLEMENT" << endl;
}

void TestRoi::testEstMoveOKTheorique() const{
	cout << "TestRoi - testEstMoveOKTheorique";

	Position aPosition(2, 5);
	game::EtatGame* aEtatGame = game::EtatGame::accessInstance();

	game::EtatGame& aEtatGame2 = *(game::EtatGame::accessInstance());
	Roi *aRoi = new Roi(WHITE, aPosition);

	aEtatGame->setPieceCaseXY(aPosition, aRoi);
	//aEtatGame->reset();

	cout << "	OK" << endl;
}

} /* namespace datas */
