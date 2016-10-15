/*
 * DisplayTerminal.h
 *
 *  Created on: 16 oct. 2016
 *      Author: le_e
 */

#ifndef DISPLAYTERMINAL_H_
#define DISPLAYTERMINAL_H_

namespace gui{

class DisplayTerminal {
public:
	DisplayTerminal();
	virtual ~DisplayTerminal();

	//void updateDisplay(const game::EtatGame& iEtatGame, const Move& iMove);

	void displayPositionGameTerminal(const game::EtatGame& iEtatGame);

	//static datas::MoveCSPtr nextMove();
	//static boost::shared_ptr<datas::Move> nextMove();

};

} /* namespace gui*/

#endif /* DISPLAYTERMINAL_H_ */
