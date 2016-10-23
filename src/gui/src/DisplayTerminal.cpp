/*
 * DisplayTerminal.cpp
 *
 *  Created on: 15 oct. 2016
 *      Author: le_e
 */

#include <iostream>

#include "../../game/src/EtatGame.h"
#include "DisplayTerminal.h"
#include "../../datas/src/typeDefine/Dimension.h"
#include "ColorDisplay.h"

namespace gui {

DisplayTerminal::DisplayTerminal()
{}

DisplayTerminal::~DisplayTerminal()
{}

void DisplayTerminal::displayPositionGameTerminal(const game::EtatGame& iEtatGame){
	datas::ETypePiece aTypePiece;
	datas::EColor aColor;

	for(int i=NBRE_LIGNE-1; i>=0; --i){
		std::cout << " " << i << "|";
		for(int j=0; j<NBRE_COLONNE; j++){
			std::cout << " ";
			if(iEtatGame.getCase(i, j).hasPiece()){
				const datas::Piece *aPiece = &(iEtatGame.getCase(i, j).getPiece());
				aTypePiece = aPiece->getTypePiece();
				aColor = aPiece->getColor();
			}
			else{
				aTypePiece = datas::NO_TYPE;
				aColor = datas::WHITE;
			}
			displayPiece(aTypePiece, aColor);
			std::cout << " ";
			std::cout << "|";

		}
		std::cout << std::endl;
	}
	std::cout << "  --------------------------------" << std::endl;
	std::cout << "    a   b   c   d   e   f   g   h" << std::endl;
}

void DisplayTerminal::displayPiece(const datas::ETypePiece iTypePiece, const datas::EColor iColor){
	 //std::cout << "\033[1;31mbold red text\033[0m\n";
	//std::cout << FG_RED << "red text" << std::endl;
	//std::cout << getColor(2) << "red text" << std::endl;
	//std::cout << "test" << std::endl;
	std::cout << getSymbol(iTypePiece);
}

std::string DisplayTerminal::getColor(int color){
	std::string aResult("\033[31");
	/*aResult.append(FG_RED);
	+COLOR_SUFFIX);*/
	return aResult;
}

std::string DisplayTerminal::getSymbol(const datas::ETypePiece iTypePiece){
	std::string aResult;

	switch(iTypePiece){
	case datas::ROI_TYPE:
		aResult.assign("R");
		break;
	case datas::DAME_TYPE:
		aResult.assign("D");
		break;

	case datas::TOUR_TYPE:
		aResult.assign("T");
		break;

	case datas::CAVALIER_TYPE:
		aResult.assign("C");
		break;

	case datas::FOU_TYPE:
		aResult.assign("F");
		break;

	case datas::PION_TYPE:
		aResult.assign("P");
		break;

	case datas::NO_TYPE:
		aResult.assign(" ");
		break;
	}

	return aResult;
}

} /* namespace gui */

