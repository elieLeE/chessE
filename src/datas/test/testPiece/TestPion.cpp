/*
 * TestPion.cpp
 *
 *  Created on: 29 oct. 2016
 *      Author: le_e
 */
#include <iostream>
#include <sstream>

#include "../../../common/src/UnitTest.h"
#include "TestPion.h"
#include "../../src/piece/Pion.h"

using namespace std;
using namespace datas;
using namespace common;

TestPion::TestPion()
{}

TestPion::~TestPion()
{}

void TestPion::startTests(void){
	UnitTest<TestPion> unitT("TestPion");

	unitT.addMethod("testSimple", &datas::TestPion::testSimple, NOT_YET_IMPLEMENTED);
	unitT.addMethod("testMovePiece", &datas::TestPion::testMovePiece, NOT_YET_IMPLEMENTED);
	unitT.addMethod("testCanAccessCase", &datas::TestPion::testCanAccessCase, NOT_YET_IMPLEMENTED);
	unitT.addMethod("testIsValideMove", &datas::TestPion::testIsValideMove, NOT_YET_IMPLEMENTED);
	unitT.addMethod("testToStream", &datas::TestPion::testToStream);

	unitT.launchMethods();
}

void TestPion::testSimple(void) const{

}

void TestPion::testMovePiece(void) const{

}

void TestPion::testCanAccessCase(void) const{

}

void TestPion::testIsValideMove(void) const{

}

void TestPion::testToStream(void) const{
	ostream aStream(0);
	stringbuf aStr;
	aStream.rdbuf(&aStr);

	Position aPosition(5, 5);
	Pion aPion(WHITE, aPosition, true);

	aStream << aPion;

	string aExpected("type : Pion\n"
			"pos : (5, 5)\n"
			"color : WHITE\n"
			"numJ : JOUEUR_1\n"
			"alive ? true\n"
			"value : 1\n"
			"sens croissant ? true\n"
			"already moved ? false\n");

	BOOST_ASSERT_MSG(aStr.str().compare(aExpected) == 0, "testPion toStream");
}
