/*
 * Position.h
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#ifndef POSITION_H_
#define POSITION_H_

#include "typeDefine/Color.h"
#include <iostream>

namespace datas {

class Position {
public:
	Position();
	Position(int iX, int iY);
	virtual ~Position();

	void setPosition(int x, int y);

	int getX() const;
	void setX(int iX);

	int getY() const;
	void setY(int iY);

	bool isValid() const;

	int evaluateDistance(const Position& iPosition) const;

	bool sameCol(const Position& iPosition) const;
	bool sameLigne(const Position& iPosition) const;

	EColor getColorCase() const;

	std::ostream& toStream(std::ostream& aStream) const;

	bool operator==(const Position& iPosition) const ;
	bool operator!=(const Position& iPosition) const ;

private:
	//Position& operator=(const Position&);

	int _x;
	int _y;
};

}

#endif /* POSITION_H_ */
