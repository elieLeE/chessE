/*
 * DisplayWindow.h
 *
 *  Created on: 16 oct. 2016
 *      Author: le_e
 */

#ifndef DISPLAYWINDOW_H_
#define DISPLAYWINDOW_H_

namespace gui{

class DisplayWindow{
public:
	DisplayWindow();
	virtual ~DisplayWindow();

	//void updateDisplay(const game::Echiquier& iEchiquier, const Move& iMove);

	void displayPositionGameWindow(const game::Echiquier& iEchiquier);

	//static datas::MoveCSPtr nextMove();
	//static boost::shared_ptr<datas::Move> nextMove();

};

} /* namespace gui*/

#endif /* DISPLAYWINDOW_H_ */
