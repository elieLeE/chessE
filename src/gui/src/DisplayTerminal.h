/*
 * DisplayTerminal.h
 *
 *  Created on: 16 oct. 2016
 *      Author: le_e
 */

#ifndef DISPLAYTERMINAL_H_
#define DISPLAYTERMINAL_H_

#include "../../game/src/EtatGame.h"
#include "../../datas/src/Types.h"
#include "../../datas/src/TypePiece.h"
#include "../../datas/src/Color.h"

namespace gui{

class DisplayTerminal {
public:
	DisplayTerminal();
	virtual ~DisplayTerminal();

	//void updateDisplay(const game::EtatGame& iEtatGame, const Move& iMove);

	void displayPositionGameTerminal(const game::EtatGame& iEtatGame);
	void displayPiece(const datas::ETypePiece iTypePiece, const datas::EColor iColor);
	std::string getSymbol(const datas::ETypePiece iTypePiece);
	std::string getColor(int color);

	//static datas::MoveCSPtr nextMove();
	//static boost::shared_ptr<datas::Move> nextMove();

};

} /* namespace gui*/

#endif /* DISPLAYTERMINAL_H_ */