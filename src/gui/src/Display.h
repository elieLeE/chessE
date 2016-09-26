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

	//void updateDisplay(const game::EtatGame& iEtatGame, const Move& iMove);

	static datas::MoveCSPtr nextMove();
	//static boost::shared_ptr<datas::Move> nextMove();

private:
	Display();

	static Display* _display;
};

} /* namespace gui*/
#endif /* DISPLAY_H_ */
