/*
 * WritingFile.h
 *
 *  Created on: 22 janv. 2017
 *      Author: le_e
 */

#ifndef DATAS_SRC_FICHIER_WRITINGFILE_H_
#define DATAS_SRC_FICHIER_WRITINGFILE_H_

#include "File.h"

namespace datas {

class WritingFile : public File {
public:
	WritingFile(std::string& iPath, std::ios_base::openmode mode);
	virtual ~WritingFile();

	void addLine(std::string& line);

	virtual bool open();

private:
	std::ofstream _file;
};

}

#endif
