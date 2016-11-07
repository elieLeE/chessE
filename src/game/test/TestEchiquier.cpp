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
	//game::TestEchiquier (*visuElement)(void) = &(game::TestEchiquier::test2);
}

TestEchiquier::~TestEchiquier()
{}

void TestEchiquier::startTest(){
	/*TEST_SET_CLASS(TestEchiquier);
	TEST_LAUNCH(testAddPiece);
	TEST_LAUNCH(testRemovePiece);
	TEST_LAUNCH(testRemovePiece);
	TEST_LAUNCH(testMovePiece);*/

	//pair<int, void (*)(void) > x(1, &(TestEchiquier::testAddPiece));

	//pair<int, void (*)(void) > x(1, testAddPiece);

	//(void (*)(void)) p = (void(*)(void))testAddPiece;

	TestEchiquier aTestEchiquier;

	/*aTestEchiquier.testAddPiece();
	aTestEchiquier.testRemovePiece();
	aTestEchiquier.testMovePiece();*/

	std::pair< int, void (*)(void) > c;

	//void (*)(void) f;

	//void (*visuElement)(void) = (void(*)(void))test2;

	cout << endl;
}

void TestEchiquier::testAddPiece(void){
	cout << "TestEchiquier - testAddPiece";

	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	aEchiquier.reset();

	Position aPosition(2, 5);
	Tour *aTour = new Tour(WHITE, aPosition);
	aEchiquier.addPiece(aTour);

	BOOST_ASSERT_MSG(aEchiquier.getCase(aPosition).hasPiece(), "TestEchiquier addPiece - hasPiece");
	BOOST_ASSERT_MSG(!aEchiquier.getCase(Position(aPosition).getX()+1, aPosition.getY()).hasPiece(), "TestEchiquier addPiece - hasNotPiece");

	cout << "	OK" << endl;
}

void TestEchiquier::testRemovePiece(void){
	cout << "TestEchiquier - testRemovePiece";

	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	Position aPosition(2, 5);
	Tour *aTour = new Tour(WHITE, aPosition);

	aEchiquier.addPiece(aTour);
	BOOST_ASSERT_MSG(aEchiquier.getCase(aPosition).hasPiece(), "TestEchiquier addPiece - hasPiece");

	aEchiquier.removePiece(aTour->getPosition());
	BOOST_ASSERT_MSG(!aEchiquier.getCase(aPosition).hasPiece(), "TestEchiquier addPiece - hasPiece");

	cout << "	OK" << endl;
}

void TestEchiquier::testMovePiece(void) const{
	cout << "TestEchiquier - testMovePiece";
	cout << endl;

	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	aEchiquier.reset();

	Position aPositionStart(2, 5);
	Position aPositionEnd(2, 7);
	Tour *aTour = new Tour(WHITE, aPositionStart);

	aEchiquier.addPiece(aTour);
	BOOST_ASSERT_MSG(aEchiquier.getCase(aPositionStart).hasPiece(), "TestEchiquier addPiece - hasPiece");

	/*aEchiquier->movePiece(aPositionStart, aPositionEnd);
	cout << "piece : " << aTour << endl;
	cout << "piece - start :" <<  aEchiquier->getCase(aPositionStart).getPiece().get() << endl;
	cout << "piece - end   :" <<  aEchiquier->getCase(aPositionEnd).getPiece().get() << endl;
	BOOST_ASSERT_MSG(aEchiquier->getCase(aPositionEnd).hasPiece(), "TestEchiquier movePiece - hasPiece");
	BOOST_ASSERT_MSG(!aEchiquier->getCase(aPositionStart).hasPiece(), "TestEchiquier movePiece - hasNotPiece");*/

	cout << "	OK" << endl;
}
