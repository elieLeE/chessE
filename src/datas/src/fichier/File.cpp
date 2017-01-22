/*
 * Fichier.cpp
 *
 *  Created on: 15 oct. 2016
 *      Author: le_e
 */
#include "File.h"

namespace datas {

File::File(std::string& iPath, std::ios_base::openmode iMode):
		_path(iPath),
		_mode(iMode)
{
	//f = open(s.c_str(), "r");
}

File::~File()
{}

} /* namespace datas */
