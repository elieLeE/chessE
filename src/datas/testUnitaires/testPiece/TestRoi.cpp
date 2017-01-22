/*
 * TestRoi.cpp
 *
 *  Created on: 23 oct. 2016
 *      Author: le_e
 */

#include "../../testUnitaires/testPiece/TestRoi.h"

#include <iostream>
#include <sstream>
#include <boost/assert.hpp>

#include "../../../common/src/DisplayType.h"
#include "../../../common/src/UnitTest.h"
#include "../../src/piece/Roi.h"
#include "../../src/piece/Pion.h"
#include "../../src/piece/Dame.h"
#include "../../src/piece/Cavalier.h"
#include "../../src/piece/Fou.h"
#include "../../src/piece/Tour.h"
#include "../../src/typeDefine/Color.h"
#include "../../../game/src/Echiquier.h"
#include "../../../gui/src/DisplayTerminal.h"

using namespace std;
using namespace datas;
using namespace common;

TestRoi::TestRoi()
{}

TestRoi::~TestRoi()
{}

void TestRoi::startTests(void){
	UnitTest<TestRoi> unitT("TestRoi");

	unitT.addMethod("testSimple", &datas::TestRoi::testSimple);
	unitT.addMethod("testMovePiece", &datas::TestRoi::testMovePiece);
	unitT.addMethod("testNormalMoveTheorique", &datas::TestRoi::testNormalMoveTheorique);
	unitT.addMethod("testNormalMovePratique", &datas::TestRoi::testNormalMovePratique);
	unitT.addMethod("testPetitRockTheorique", &datas::TestRoi::testEstPetitRockTheorique);
	unitT.addMethod("testGrandRockTheorique", &datas::TestRoi::testEstGrandRockTheorique);
	unitT.addMethod("testRockPratique", &datas::TestRoi::testEstRockPratique);
	unitT.addMethod("testEstMoveOKTheorique", &datas::TestRoi::testEstMoveOKTheorique);
	unitT.addMethod("testEstMoveOKPratique", &datas::TestRoi::testEstMoveOKPratique);
	unitT.addMethod("testIsValidaMove", &datas::TestRoi::testIsValidaMove);
	unitT.addMethod("testCanAccessCase", &datas::TestRoi::testCanAcccessCase);
	unitT.addMethod("testCanBeKilled", &datas::TestRoi::testCanBeKilled);
	unitT.addMethod("testToStream", &datas::TestRoi::testToStream);

	unitT.launchMethods();
}

void TestRoi::testSimple(void) const{
	Position aPosition(5, 5);
	Roi aRoi(WHITE, aPosition);

	BOOST_ASSERT_MSG(aRoi.getColor()==WHITE, "test simple - color");
	BOOST_ASSERT_MSG(aRoi.getPosition() == aPosition, "test simple - position");
	BOOST_ASSERT_MSG(!aRoi.hasAlreadyMoved(), "test simple - hasAlreadyMoved");
}

void TestRoi::testMovePiece(void) const{
	Roi aRoi(WHITE, Position(2, 2));

	BOOST_ASSERT_MSG(!aRoi.hasAlreadyMoved(), "test simple - hasAlreadyMoved KO");

	aRoi.movePiece(Position(3, 3));
	BOOST_ASSERT_MSG(aRoi.hasAlreadyMoved(), "test simple - hasAlreadyMoved OK");
}

//nombreux cas deja testes par les autres methodes ==> on teste 2 cas pour chaque type de movement (1 correct et 1 incorrect)
void TestRoi::testIsValidaMove(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Roi* aRoi(new Roi(WHITE, Position(5, 1)));

	aEchiquier.addPiece(aRoi);

	Move aMove;

	//normal move
	aMove.setPositions(aRoi->getPosition(), Position(5, 2));
	BOOST_ASSERT_MSG(aRoi->isValideMove(aMove), "test isValidaMove - normal move - OK");

	Tour *aTour(new Tour(BLACK, Position(2, 2)));
	aEchiquier.addPiece(aTour);
	BOOST_ASSERT_MSG(!aRoi->isValideMove(aMove), "test isValidaMove - normal move - KO");

	//small rock move
	Tour *aTour2(new Tour(WHITE, Position(8, 1)));
	aEchiquier.addPiece(aTour2);
	aMove.setPositionEnd(Position(7, 1));
	BOOST_ASSERT_MSG(aRoi->isValideMove(aMove), "test isValidaMove - small rock OK");

	Tour *aTour3(new Tour(BLACK, Position(6, 6)));
	aEchiquier.addPiece(aTour3);
	aMove.setPositionEnd(Position(7, 1));
	BOOST_ASSERT_MSG(!aRoi->isValideMove(aMove), "test isValidaMove - small rock KO");

	//big rock move
	Tour *aTour4(new Tour(WHITE, Position(1, 1)));
	aEchiquier.addPiece(aTour4);
	aMove.setPositionEnd(Position(3, 1));
	BOOST_ASSERT_MSG(aRoi->isValideMove(aMove), "test isValidaMove - big rock OK");

	Tour *aTour5(new Tour(BLACK, Position(4, 1)));
	aEchiquier.addPiece(aTour5);
	aMove.setPositionEnd(Position(3, 1));
	BOOST_ASSERT_MSG(!aRoi->isValideMove(aMove), "test isValidaMove - big rock KO");
}

void TestRoi::testEstMoveOKTheorique(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Roi* aRoi(new Roi(WHITE, Position(5, 1)));

	Move aMove;

	//NORMAL_MOVE
	aMove.setPositions(aRoi->getPosition(), Position(5, 2));
	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove)==NORMAL_MOVE, "test move theorique - normal move - OK");

	aMove.setPositionEnd(Position(5, 3));
	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove)==INCORRECT_MOVE, "test move theorique - normal move - KO - final position not accessible");


	//PETIT_ROCK
	aMove.setPositionEnd(Position(7, 1));
	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove)==INCORRECT_MOVE, "test move theorique - small rock move - KO - not tower at (1, 1)");

	Tour *aTour(new Tour(WHITE, Position(8, 1)));
	aEchiquier.addPiece(aTour);
	aMove.setPositionEnd(Position(7, 1));
	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove)==PETIT_ROCK, "test move theorique - small rock move - OK");

	Tour *aTour2(new Tour(WHITE, Position(1, 1)));
	aEchiquier.addPiece(aTour2);
	aMove.setPositionEnd(Position(7, 1));
	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove)==PETIT_ROCK, "test move theorique - small rock move - OK - two towers (at (1, 1) and (8, 1)");
	aEchiquier.reset();

	aTour = new Tour(WHITE, Position(1, 1));
	aEchiquier.addPiece(aTour);
	aMove.setPositionEnd(Position(7, 1));
	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove)==INCORRECT_MOVE, "test move theorique - small rock move - KO - tower at wrong position");
	aEchiquier.reset();


	//GRAND_ROCK
	aMove.setPositionEnd(Position(3, 1));
	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove)==INCORRECT_MOVE, "test move theorique - small rock move - KO - not tower at (1, 1)");

	aTour = new Tour(WHITE, Position(1, 1));
	aEchiquier.addPiece(aTour);
	aMove.setPositionEnd(Position(3, 1));
	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove)==GRAND_ROCK, "test move theorique - big rock move - OK");

	aTour2 = new Tour(WHITE, Position(8, 1));
	aEchiquier.addPiece(aTour2);
	aMove.setPositionEnd(Position(3, 1));
	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove)==GRAND_ROCK, "test move theorique - big rock move - OK - two towers (at (1, 1) and (8, 1)");
	aEchiquier.reset();

	aTour = new Tour(WHITE, Position(8, 1));
	aEchiquier.addPiece(aTour);
	aMove.setPositionEnd(Position(3, 1));
	BOOST_ASSERT_MSG(aRoi->estMoveOKTheorique(aMove)==INCORRECT_MOVE, "test move theorique - big rock move - KO - tower at wrong position");
}

void TestRoi::testEstMoveOKPratique(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Roi* aRoi(new Roi(WHITE, Position(5, 1)));

	aEchiquier.addPiece(aRoi);

	Move aMove;

	aMove.setPositions(aRoi->getPosition(), Position(5, 2));
	BOOST_ASSERT_MSG(aRoi->estMoveOKPratique(aMove, NORMAL_MOVE), "test move pratique - normal move - OK");

	aMove.setPositionEnd(Position(7, 1));
	BOOST_ASSERT_MSG(aRoi->estMoveOKPratique(aMove, PETIT_ROCK), "test move pratique - small rock move - OK");

	aMove.setPositionEnd(Position(3, 1));
	BOOST_ASSERT_MSG(aRoi->estMoveOKPratique(aMove, GRAND_ROCK), "test move pratique - big rock move - OK");

	Tour *aTour(new Tour(BLACK, Position(6, 6)));
	aEchiquier.addPiece(aTour);

	aMove.setPositions(aRoi->getPosition(), Position(6, 1));
	BOOST_ASSERT_MSG(!aRoi->estMoveOKPratique(aMove, NORMAL_MOVE), "test move pratique - normal move - KO");

	aMove.setPositionEnd(Position(7, 1));
	BOOST_ASSERT_MSG(!aRoi->estMoveOKPratique(aMove, PETIT_ROCK), "test move pratique - small rock move - KO");

	Tour *aTour2(new Tour(BLACK, Position(5, 6)));
	aEchiquier.addPiece(aTour2);

	aMove.setPositionEnd(Position(3, 1));
	BOOST_ASSERT_MSG(!aRoi->estMoveOKPratique(aMove, GRAND_ROCK), "test move pratique - big rock move - KO");
}

void TestRoi::testNormalMoveTheorique(void) const{
	Roi aRoi(WHITE, Position(5, 0));

	Move aMove(aRoi.getPosition(), Position(6, 1));

	BOOST_ASSERT_MSG(aRoi.estNormalMoveTheorique(aMove), "test normalMoveTheorique - normal move OK");

	aMove.setPositionEnd(Position(7, 7));
	BOOST_ASSERT_MSG(!aRoi.estNormalMoveTheorique(aMove), "test normalMoveTheorique - normal move KO");
}

void TestRoi::testNormalMovePratique(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Tour *aTour(new Tour(BLACK, Position(1, 4)));
	Tour *aTour2(new Tour(WHITE, Position(1, 6)));

	aEchiquier.addPiece(aTour);
	aEchiquier.addPiece(aTour2);

	Move aMove;

	Roi aRoi(WHITE, Position(5, 5));

	//attetion => move OK == can not be killed !!
	//can not be killed
	aMove.setPositions(aRoi.getPosition(), Position(6, 5));
	BOOST_ASSERT_MSG(aRoi.estNormalMovePratique(aMove), "test normalMovePratique - normal move OK - can not be killed");

	//can be killed
	aMove.setPositions(aRoi.getPosition(), Position(5, 4));
	BOOST_ASSERT_MSG(!aRoi.estNormalMovePratique(aMove), "test normalMovePratique - normal move KO - can be killed");

	//can not be killed because same color
	aMove.setPositions(aRoi.getPosition(), Position(5, 6));
	BOOST_ASSERT_MSG(aRoi.estNormalMovePratique(aMove), "test normalMovePratique - normal move OK - can not be killed - same color");
}

void TestRoi::testEstPetitRockTheorique(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	//en bas de l'echiquier
	Roi aRoi(WHITE, Position(5, 1));
	Tour *aTour(new Tour(WHITE, Position(8, 1)));

	aEchiquier.addPiece(aTour);

	Move aMove(aRoi.getPosition(), Position(7, 1));

	BOOST_ASSERT_MSG(aRoi.estPetitRockTheorique(aMove), "test petitRockTheorique - en bas - OK");

	aRoi.movePiece(Position(5, 1));
	BOOST_ASSERT_MSG(!aRoi.estPetitRockTheorique(aMove), "test petitRockTheorique - en bas - KO - king already moved");

	//en haut de l'echiquier
	Roi aRoi2(WHITE, Position(5, 8));
	Tour *aTour2(new Tour(WHITE, Position(8, 8)));

	aEchiquier.addPiece(aTour2);

	aMove.setPositions(aRoi2.getPosition(), Position(7, 8));

	BOOST_ASSERT_MSG(aRoi2.estPetitRockTheorique(aMove), "test petitRockTheorique - en haut - OK");

	aTour2->movePiece(Position(8, 8));
	BOOST_ASSERT_MSG(!aRoi2.estPetitRockTheorique(aMove), "test petitRockTheorique - en haut - KO - tower already moved");
}

void TestRoi::testEstGrandRockTheorique(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	//en bas de l'echiquier
	Roi aRoi(WHITE, Position(5, 1));
	Tour *aTour(new Tour(WHITE, Position(1, 1)));

	aEchiquier.addPiece(aTour);

	Move aMove(aRoi.getPosition(), Position(3, 1));

	BOOST_ASSERT_MSG(aRoi.estGrandRockTheorique(aMove), "test grandRockTheorique - en bas - OK");

	aRoi.movePiece(Position(5, 1));
	BOOST_ASSERT_MSG(!aRoi.estGrandRockTheorique(aMove), "test grandRockTheorique - en bas - KO - king already moved");

	//en haut de l'echiquier
	Roi aRoi2(WHITE, Position(5, 8));
	Tour *aTour2(new Tour(WHITE, Position(1, 8)));

	aEchiquier.addPiece(aTour2);

	aMove.setPositions(aRoi2.getPosition(), Position(3, 8));

	BOOST_ASSERT_MSG(aRoi2.estGrandRockTheorique(aMove), "test grandRockTheorique - en haut - OK");

	aTour2->movePiece(Position(1, 8));
	BOOST_ASSERT_MSG(!aRoi2.estGrandRockTheorique(aMove), "test grandRockTheorique - en haut - KO - tower already moved");
}

void TestRoi::testEstRockPratique(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Tour *aTour(new Tour(BLACK, Position(6, 6)));
	aEchiquier.addPiece(aTour);

	Move aMove;

	Roi aRoi(WHITE, Position(5, 1));

	BOOST_ASSERT_MSG(!aRoi.estRockPratique(PETIT_ROCK), "test estRockPratique - rock move KO - can be killed while move");

	//canBeKilled
	Tour *aTour2(new Tour(WHITE, Position(4, 6)));
	aEchiquier.addPiece(aTour2);
	BOOST_ASSERT_MSG(aRoi.estRockPratique(GRAND_ROCK), "test estRockPratique - rock move OK - can not be killed by another piece of same color");

	//in chess at beginning
	//cache tour that can kill king while petit rock and verify cache is OK
	Tour *aTour3(new Tour(BLACK, Position(5, 6)));
	aEchiquier.addPiece(aTour3);
	BOOST_ASSERT_MSG(!aRoi.estRockPratique(PETIT_ROCK), "test estRockPratique - rock move KO - king already in check - PETIT_ROCK");
	BOOST_ASSERT_MSG(!aRoi.estRockPratique(GRAND_ROCK), "test estRockPratique - rock move KO - king already in check - GRAND_ROCK");

	Tour *aTour4(new Tour(WHITE, Position(5, 5)));
	aEchiquier.addPiece(aTour4);
	Tour *aTour5(new Tour(WHITE, Position(6, 5)));
	aEchiquier.addPiece(aTour5);
	BOOST_ASSERT_MSG(aRoi.estRockPratique(PETIT_ROCK), "test estRockPratique - rock move OK - king not in check by other piece same color - PETIT_ROCK");
	BOOST_ASSERT_MSG(aRoi.estRockPratique(GRAND_ROCK), "test estRockPratique - rock move OK - king not in check by other piece same color - GRAND_ROCK");

	Tour *aTour6(new Tour(WHITE, Position(6, 1)));
	aEchiquier.addPiece(aTour6);
	BOOST_ASSERT_MSG(!aRoi.estRockPratique(PETIT_ROCK), "test estRockPratique - rock move KO - piece on the path - PETIT_ROCK");

	Tour *aTour7(new Tour(WHITE, Position(4, 1)));
	aEchiquier.addPiece(aTour7);
	BOOST_ASSERT_MSG(!aRoi.estRockPratique(PETIT_ROCK), "test estRockPratique - rock move KO - piece on the path - GRAND_ROCK");
}

void TestRoi::testCanAcccessCase(void) const{
	Roi* aRoi(new Roi(WHITE, Position(2, 2)));

	BOOST_ASSERT_MSG(aRoi->canAccessCase(Position(3, 3)), "test canAcccessCase - OK");

	BOOST_ASSERT_MSG(!aRoi->canAccessCase(Position(5, 6)), "test canAcccessCase - OK");

	delete aRoi;
}

void TestRoi::testCanBeKilled(void) const{
	game::Echiquier& aEchiquier = game::Echiquier::accessInstance();

	Roi aRoi(WHITE, Position(4, 4));

	Roi* aRoi2(new Roi(BLACK, Position(3, 3)));
	Tour *aTour(new Tour(BLACK, Position(4, 1)));
	Cavalier *aCavalier(new Cavalier(BLACK, Position(3, 6)));
	Fou *aFou(new Fou(BLACK, Position(1, 1)));
	Dame *aDame(new Dame(BLACK, Position(1, 4)));
	Pion *aPion(new Pion(BLACK, Position(5, 5), false));

	Roi* aRoi2White(new Roi(WHITE, Position(3, 3)));
	Tour *aTourWhite(new Tour(WHITE, Position(4, 1)));
	Cavalier *aCavalierWhite(new Cavalier(WHITE, Position(3, 6)));
	Fou *aFouWhite(new Fou(WHITE, Position(1, 1)));
	Dame *aDameWhite(new Dame(WHITE, Position(1, 4)));
	Pion *aPionWhite(new Pion(WHITE, Position(5, 5), false));

	//Tour
	aEchiquier.addPiece(aTour);
	BOOST_ASSERT_MSG(aRoi.canBeKilled(), "test canBeKilled - Tour can kill King");

	aTour->setDead();
	BOOST_ASSERT_MSG(!aRoi.canBeKilled(), "test canBeKilled - Tour can not kill King / dead");

	aEchiquier.addPiece(aTourWhite);
	BOOST_ASSERT_MSG(!aRoi.canBeKilled(), "test canBeKilled - Tour can not kill King / same color");
	aTourWhite->setDead();

	//Cavalier
	aEchiquier.addPiece(aCavalier);
	BOOST_ASSERT_MSG(aRoi.canBeKilled(), "test canBeKilled - Cavalier can kill King");

	aCavalier->setDead();
	BOOST_ASSERT_MSG(!aRoi.canBeKilled(), "test canBeKilled - Cavalier can not kill King / dead");

	aEchiquier.addPiece(aCavalierWhite);
	BOOST_ASSERT_MSG(!aRoi.canBeKilled(), "test canBeKilled - Cavalier can not kill King / same color");
	aCavalierWhite->setDead();

	//Fou
	aEchiquier.addPiece(aFou);
	BOOST_ASSERT_MSG(aRoi.canBeKilled(), "test canBeKilled - Fou can kill King");

	aFou->setDead();
	BOOST_ASSERT_MSG(!aRoi.canBeKilled(), "test canBeKilled - Fou can not kill King / dead");

	aEchiquier.addPiece(aFouWhite);
	BOOST_ASSERT_MSG(!aRoi.canBeKilled(), "test canBeKilled - Fou can not kill King / same color");
	aFouWhite->setDead();

	//Dame
	aEchiquier.addPiece(aDame);
	BOOST_ASSERT_MSG(aRoi.canBeKilled(), "test canBeKilled - Dame can kill King");

	aDame->setDead();
	BOOST_ASSERT_MSG(!aRoi.canBeKilled(), "test canBeKilled - Dame can not kill King / dead");

	aEchiquier.addPiece(aDameWhite);
	BOOST_ASSERT_MSG(!aRoi.canBeKilled(), "test canBeKilled - Dame can not kill King / same color");
	aDameWhite->setDead();
	//Roi
	aEchiquier.addPiece(aRoi2);
	BOOST_ASSERT_MSG(aRoi.canBeKilled(), "test canBeKilled - Roi can kill King");

	aRoi2->setDead();
	BOOST_ASSERT_MSG(!aRoi.canBeKilled(), "test canBeKilled - Roi can not kill King / dead");

	aEchiquier.addPiece(aRoi2White);
	BOOST_ASSERT_MSG(!aRoi.canBeKilled(), "test canBeKilled - Roi can not kill King / same color");
	aRoi2White->setDead();
	//Pion
	aEchiquier.addPiece(aPion);
	BOOST_ASSERT_MSG(aRoi.canBeKilled(), "test canBeKilled - Pion can kill King");

	aPion->setDead();
	BOOST_ASSERT_MSG(!aRoi.canBeKilled(), "test canBeKilled - Pion can not kill King / dead");

	aEchiquier.addPiece(aPionWhite);
	BOOST_ASSERT_MSG(!aRoi.canBeKilled(), "test canBeKilled - Pion can not kill King / same color");
	aPionWhite->setDead();
}

void TestRoi::testToStream(void) const{
	ostream aStream(0);
	stringbuf aStr;
	aStream.rdbuf(&aStr);

	Position aPosition(5, 5);
	Roi aRoi(WHITE, aPosition);

	aStream << aRoi;

	string aExpected("type : Roi\n"
			"pos : (5, 5)\n"
			"color : WHITE\n"
			"numJ : JOUEUR_1\n"
			"alive ? true\n"
			"value : 100\n"
			"already moved ? false\n");

	BOOST_ASSERT_MSG(aStr.str().compare(aExpected) == 0, "testRoi toStream");
}
