/*
 * TestCavalier.cpp
 *
 *  Created on: 29 oct. 2016
 *      Author: le_e
 */
#include <boost/assert.hpp>

#include "TestCavalier.h"
#include "../../src/piece/Cavalier.h"
#include "../../../game/src/Echiquier.h"

using namespace std;
using namespace datas;

TestCavalier::TestCavalier()
{}

TestCavalier::~TestCavalier()
{}

void TestCavalier::startTests(void){
	TestCavalier aTourCavalier;

	//aTourCavalier.testIsValideMove();
	aTourCavalier.testCanAccess();

	std::cout << std::endl;
}

void TestCavalier::testCanAccess(void) const{
	cout << "TestCavalier - testCanAccess";

	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();
	aEchiquier.reset();

	Position aPositionStart(2, 5);
	Position aPositionEnd(4, 4);
	Move aMove(aPositionStart, aPositionEnd);
	Cavalier *aCavalier = new Cavalier(WHITE, aPositionStart);

	aEchiquier.setPieceCaseXY(aPositionStart, aCavalier);

	BOOST_ASSERT_MSG(aCavalier->canAccessCase(aPositionEnd), "TestCavalier canAccess - test sameLigne");
	BOOST_ASSERT_MSG(aCavalier->isValideMove(aMove), "TestCavalier MovePiece - valide move");

	aPositionEnd.setPosition(0, 6);
	aMove.setPositionEnd(aPositionEnd);
	BOOST_ASSERT_MSG(aCavalier->canAccessCase(aPositionEnd), "TestCavalier canAccess - test sameCol");
	BOOST_ASSERT_MSG(aCavalier->isValideMove(aMove), "TestCavalier MovePiece - valide move");

	aPositionEnd.setPosition(7, 3);
	aMove.setPositionEnd(aPositionEnd);
	BOOST_ASSERT_MSG(!aCavalier->canAccessCase(aPositionEnd), "TestCavalier canAccess - cannot access");
	BOOST_ASSERT_MSG(!aCavalier->isValideMove(aMove), "TestCavalier MovePiece - not valide move");

	cout << "	OK" << endl;
}
