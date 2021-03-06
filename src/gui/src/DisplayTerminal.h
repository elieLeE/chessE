/*
 * DisplayTerminal.h
 *
 *  Created on: 16 oct. 2016
 *      Author: le_e
 */

#ifndef DISPLAYTERMINAL_H_
#define DISPLAYTERMINAL_H_

#include "../../game/src/Echiquier.h"
#include "../../datas/src/typeDefine/Types.h"
#include "../../datas/src/typeDefine/TypePiece.h"
#include "../../datas/src/typeDefine/Color.h"

namespace datas{
	class Position;
	class Move;
}

namespace gui{

class DisplayTerminal {
public:
	DisplayTerminal();
	virtual ~DisplayTerminal();

	//void updateDisplay(const game::Echiquier& iEchiquier, const Move& iMove);

	void displayPositionGameTerminal(const game::Echiquier& iEchiquier);
	std::string getColor(int color);

	boost::shared_ptr<datas::Move> nextMove() const;
	//static boost::shared_ptr<datas::Move> nextMove();

};

} /* namespace gui*/

#endif /* DISPLAYTERMINAL_H_ */
