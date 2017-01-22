/*
 * ReadingFile.cpp
 *
 *  Created on: 22 janv. 2017
 *      Author: le_e
 */

#include "ReadingFile.h"

namespace datas {

ReadingFile::ReadingFile(std::string& iPath, std::ios_base::openmode iMode):
		File(iPath, iMode)
{}

ReadingFile::~ReadingFile()
{}

bool ReadingFile::open(){
	_file.open(_path.c_str(), _mode);

	//return _file;
	return true;
}

std::string ReadingFile::readingLine() const{
	std::string aStr;

	//std::ifstream.getline(_file, aStr);

	//_file.getline(aStr);

	return aStr;
}

}
