/*
 * TestCase.cpp
 *
 *  Created on: 13 nov. 2016
 *      Author: le_e
 */

#include "TestCase.h"
#include "../../common/src/UnitTest.h"
#include "../src/Case.h"

using namespace std;
using namespace game;
using namespace datas;
using namespace common;

TestCase::TestCase()
{}

TestCase::~TestCase()
{}

void TestCase::startTest(){
	UnitTest<TestCase> unitT("TestCase");

	unitT.addMethod("TestCase", &datas::TestCase::testSimple);

	unitT.launchMethods();
}

void TestCase::testSimple(void) const{
	Case aCase;

	BOOST_ASSERT_MSG(!aCase.hasPiece(), "TestCase simple - no piece");

	Tour* aTour(new Tour(WHITE, Position()));
	PiecePtr aPiece(aTour);
	aCase.setPiece(aPiece);

	BOOST_ASSERT_MSG(aCase.hasPiece(), "TestCase simple - hasPiece");
	BOOST_ASSERT_MSG(aCase.getPiece().get() == aTour, "TestCase simple - getPiece");
	BOOST_ASSERT_MSG(aCase.accessPiece().get() == aTour, "TestCase simple - accessPiece");

	aCase.resetPiece();
	BOOST_ASSERT_MSG(!aCase.hasPiece(), "TestCase simple - reset, no piece anymore");
}


