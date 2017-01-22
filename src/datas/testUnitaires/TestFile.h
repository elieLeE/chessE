/*
 * TestFichier.h
 *
 *  Created on: 22 janv. 2017
 *      Author: le_e
 */

#ifndef DATAS_TESTUNITAIRES_TESTFILE_H_
#define DATAS_TESTUNITAIRES_TESTFILE_H_

namespace datas {

class TestFile {
public:
	TestFile();
	virtual ~TestFile();

	static void startTests();

	void testWriteRead(void);
};

}

#endif
