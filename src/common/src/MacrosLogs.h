/*
 * MacrosLogs.h
 *
 *  Created on: 17 janv. 2017
 *      Author: le_e
 */

#ifndef COMMON_SRC_MACROSLOGS_H_
#define COMMON_SRC_MACROSLOGS_H_

#include <iostream>
#include <string>

#include "Logs.h"
#include "MacroCouleurs.h"

#define LOG_METHODNAME aMethodName

#define LOG_DEF_METHOD(n) const char* const aMethodName = #n;

#define LOG_FILE_LINE \
	filterFileName(__FILE__) << " (" << __LINE__ << ") : " \
	\

#define DISPLAY_INFO(message)\
		std::cout << retrieveDateTime() << " <==> " << LOG_FILE_LINE << LOG_METHODNAME << message << std::endl;\
		\

#define LOG_INFO(message)\
		CHANGE_COULEUR(BLANC)\
		DISPLAY_INFO(message)\
		RESET_COLOR\
		\

#define LOG_ERROR(message)\
		CHANGE_COULEUR(ROUGE)\
		DISPLAY_INFO(message)\
		RESET_COLOR\
		\

#define LOG_WARN(message)\
		CHANGE_COULEUR(JAUNE)\
		DISPLAY_INFO(message)\
		RESET_COLOR\
		\

#define LOG_DEBUG(message)\
		CHANGE_COULEUR(BLEU)\
		DISPLAY_INFO(message)\
		RESET_COLOR\
		\



#endif /* COMMON_SRC_MACROSLOGS_H_ */
