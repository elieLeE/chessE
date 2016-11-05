/*
 * TestEchiquier.cpp
 *
 *  Created on: 30 oct. 2016
 *      Author: le_e
 */
#include <iostream>

#include "TestEchiquier.h"
#include "../src/Echiquier.h"
#include "../../datas/src/Position.h"
#include "../../datas/src/piece/Tour.h"

using namespace std;
using namespace game;
using namespace datas;

TestEchiquier::TestEchiquier()
{
	//void (*f)();
	//f = &(test);
}

TestEchiquier::~TestEchiquier()
{}

void TestEchiquier::startTest(){
	TestEchiquier aTestEchiquier;

	aTestEchiquier.testAddPiece();
	aTestEchiquier.testRemovePiece();
	aTestEchiquier.testMovePiece();

	cout << endl;
}

void TestEchiquier::testAddPiece(void){
	cout << "TestEchiquier - testAddPiece";

	aEchiquier->reset();

	Position aPosition(2, 5);
	PiecePtr aTour(new Tour(WHITE, aPosition));
	aEchiquier->addPiece(aTour);

	BOOST_ASSERT_MSG(aEchiquier->getCase(aPosition).hasPiece(), "TestEchiquier addPiece - hasPiece");
	BOOST_ASSERT_MSG(!aEchiquier->getCase(Position(aPosition).getX()+1, aPosition.getY()).hasPiece(), "TestEchiquier addPiece - hasNotPiece");

	cout << "	OK" << endl;
}

void TestEchiquier::testRemovePiece(void){
	cout << "TestEchiquier - testRemovePiece";

	aEchiquier->reset();

	Position aPosition(2, 3);
	Tour* aTour(new Tour(WHITE, aPosition));

	aEchiquier->addPiece(aTour);
	BOOST_ASSERT_MSG(aEchiquier->getCase(aPosition).hasPiece(), "TestEchiquier addPiece - hasPiece");

	aEchiquier->killPiece(aTour->getPosition());
	BOOST_ASSERT_MSG(!aEchiquier->getCase(aPosition).hasPiece(), "TestEchiquier addPiece - hasPiece");

	cout << "	OK" << endl;
}

void TestEchiquier::testMovePiece(void) const{
	cout << "TestEchiquier - testMovePiece";

	aEchiquier->reset();

	Position aPositionStart(2, 2);
	Position aPositionEnd(2, 7);
	PiecePtr aTour(new Tour(WHITE, aPositionStart));

	aEchiquier->addPiece(aTour);
	BOOST_ASSERT_MSG(aEchiquier->getCase(aPositionStart).hasPiece(), "TestEchiquier addPiece - hasPiece");

	aEchiquier->movePiece(aPositionStart, aPositionEnd);
	BOOST_ASSERT_MSG(aEchiquier->getCase(aPositionEnd).hasPiece(), "TestEchiquier movePiece - hasPiece");
	BOOST_ASSERT_MSG(!aEchiquier->getCase(aPositionStart).hasPiece(), "TestEchiquier movePiece - hasNotPiece");

	cout << "	=> OK" << endl;
}
