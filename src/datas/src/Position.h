/*
 * Position.h
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#ifndef POSITION_H_
#define POSITION_H_

namespace datas {

class Position {
public:
	Position();
	Position(int iX, int iY);
	virtual ~Position();

	int getX() const;
	void setX(int iX);

	int getY() const;
	void setY(int iY);

	const bool isValid() const;

	const bool operator==(const Position& iPosition) const ;
	const bool operator!=(const Position& iPosition) const ;

private:
	//Position& operator=(const Position&);

	int _x;
	int _y;
};

}

#endif /* POSITION_H_ */
