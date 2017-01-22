/*
 * ReadingFile.h
 *
 *  Created on: 22 janv. 2017
 *      Author: le_e
 */

#ifndef DATAS_SRC_FICHIER_READINGFILE_H_
#define DATAS_SRC_FICHIER_READINGFILE_H_

#include "File.h"

namespace datas {

class ReadingFile : public File {
public:
	ReadingFile(std::string& iPath, std::ios_base::openmode mode);
	virtual ~ReadingFile();

	std::string readingLine() const;

	virtual bool open();

private:
	std::ifstream _file;

	//std::ios_base::openmode _mode;
};

}

#endif
