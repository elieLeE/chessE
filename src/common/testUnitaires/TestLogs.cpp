/*
 * TestLogs.cpp
 *
 *  Created on: 17 janv. 2017
 *      Author: le_e
 */

#include "TestLogs.h"

#include "../src/UnitTest.h"
#include "../src/MacrosLogs.h"

#include "../src/Logs.h"

using namespace common;
using namespace std;

TestLogs::TestLogs()
{}

TestLogs::~TestLogs()
{}

void TestLogs::startTests(){
	UnitTest<TestLogs> unitT("TestLogs");

	unitT.addMethod("testA", &common::TestLogs::testA);

	unitT.launchMethods();
}

void TestLogs::testA(void) const{
	LOG_DEF_METHOD(TestLogs::testA);

	LOG_INFO("test ecriture log INFO - BLANC");

	LOG_ERROR("test ecriture log ERROR - ROUGE");

	LOG_WARN("test ecriture log WARN - JAUNE");

	LOG_DEBUG("test ecriture log DEBUG - BLEU");
}
