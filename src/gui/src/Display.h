/*
 * Display.h
 *
 *  Created on: 25 sept. 2016
 *      Author: le_e
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

//#include "../../datas/src/Types.h"
#include <boost/shared_ptr.hpp>

#include "../../game/src/EtatGame.h"
#include "DisplayTerminal.h"
#include "DisplayWindow.h"
#include "DefienGui.h"

namespace datas{
	class Move;
	typedef boost::shared_ptr<Move> MoveCSPtr;
}

namespace gui{

class Display {
public:
	virtual ~Display();

	static const Display* getInstance();
	static Display* accessInstance();

	/*
	 * en argument => etatGame ou lastMove
	 * pour terminal => etatGame ==> masi peut-être recupere directement + necessaire que pour les tests a terme
	 * pour window => lastMove ==> mais peut-être recupere via EtatGame
	 */
	//void updateDisplay(const game::EtatGame& iEtatGame);

	void displayPositionGame(const game::EtatGame& iEtatGame);

	static datas::MoveCSPtr nextMove();
	//static boost::shared_ptr<datas::Move> nextMove();

protected:
	Display();

	static Display* _display;

#if DISPLAY_WINDOW
	boost::shared_ptr<DisplayWindow> _pDisplayWindow;
#else
	boost::shared_ptr<DisplayTerminal> _pDisplayTerminal;
#endif

};

} /* namespace gui*/
#endif /* DISPLAY_H_ */
