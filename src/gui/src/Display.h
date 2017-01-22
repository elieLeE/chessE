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

#include "../../game/src/Echiquier.h"
#include "DisplayTerminal.h"
#include "DisplayWindow.h"
#include "DefienGui.h"
#include "TypeGui.h"

namespace datas{
	class Move;
}

namespace gui{

class Display {
public:
	virtual ~Display();

	static const Display& getInstance();
	static Display& accessInstance();

	/*
	 * en argument => Echiquier ou lastMove
	 * pour terminal => Echiquier ==> masi peut-être recupere directement + necessaire que pour les tests a terme
	 * pour window => lastMove ==> mais peut-être recupere via Echiquier
	 */
	//void updateDisplay(const game::Echiquier& iEchiquier);

	void displayUpdated(const game::Echiquier& iEchiquier);

	boost::shared_ptr<datas::Move> nextMove() const;
	//static boost::shared_ptr<datas::Move> nextMove();

	void setTypeGui(const ETypeGui iTypeGui);

protected:
	Display();

	static Display _display;

	boost::shared_ptr<DisplayWindow> _pDisplayWindow;
	boost::shared_ptr<DisplayTerminal> _pDisplayTerminal;

	static ETypeGui _typeGui;
};

} /* namespace gui*/
#endif /* DISPLAY_H_ */
