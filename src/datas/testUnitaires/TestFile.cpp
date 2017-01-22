/*
 * TestFichier.cpp
 *
 *  Created on: 22 janv. 2017
 *      Author: le_e
 */

#include "TestFile.h"

#include "../../common/src/UnitTest.h"

using namespace datas;
using namespace common;

TestFile::TestFile()
{}

TestFile::~TestFile()
{}

void TestFile::startTests(){
	UnitTest<TestFile> unitT("TestFichier");

	unitT.launchMethods();
}

void TestFile::testWriteRead(void){

}
