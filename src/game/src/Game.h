/*
 * Game.h
 *
 *  Created on: 15 oct. 2016
 *      Author: le_e
 */

#ifndef GAME_H_
#define GAME_H_

#include "../../datas/src/joueur/Joueur.h"
//#include <array>

namespace game {

class Game {
public:
	Game();
	virtual ~Game();

	void newGame();

private:
	//std::vector<datas::Joueur> _joueurs;
};

} /* namespace game */
#endif /* GAME_H_ */
