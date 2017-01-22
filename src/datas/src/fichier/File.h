/*
 * Fichier.h
 *
 *  Created on: 15 oct. 2016
 *      Author: le_e
 */

#ifndef FILE_H_
#define FILE_H_

#include <string>
#include <iostream>
#include <fstream>

namespace datas {

class File {
public:
	File(std::string& iPath, std::ios_base::openmode iMode);
	virtual ~File();

	virtual bool open() = 0;

	/*bool lecturePosition(ENumPlayer *oNumPlayer, ETypePiece *oTypePiece, int *oPosX, int *oPosY);
	bool lectureMove(Move & oMove);*/

protected:
	//std::fstream FILE;
	std::string _path;

	std::ios_base::openmode _mode;
};

}
#endif
