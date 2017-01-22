/*
 * WritingFile.cpp
 *
 *  Created on: 22 janv. 2017
 *      Author: le_e
 */

#include "WritingFile.h"

namespace datas {

WritingFile::WritingFile(std::string& iPath, std::ios_base::openmode iMode):
		File(iPath, iMode)

{}

WritingFile::~WritingFile()
{}

bool ReadingFile::open(){
	_file.open(_path.c_str(), _mode);

	return _file;
}

}
