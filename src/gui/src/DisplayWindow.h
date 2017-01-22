/*
 * DisplayWindow.h
 *
 *  Created on: 16 oct. 2016
 *      Author: le_e
 */

#ifndef DISPLAYWINDOW_H_
#define DISPLAYWINDOW_H_

namespace datas{
	class Move;
	class Position;
}

namespace gui{

class DisplayWindow{
public:
	DisplayWindow();
	virtual ~DisplayWindow();

	//void updateDisplay(const game::Echiquier& iEchiquier, const Move& iMove);

	void displayUpdated(const game::Echiquier& iEchiquier);

	const boost::shared_ptr<datas::Move> nextMove() const;
	//static boost::shared_ptr<datas::Move> nextMove();

};

} /* namespace gui*/

#endif /* DISPLAYWINDOW_H_ */
