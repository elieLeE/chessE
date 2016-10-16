/*
 * Position.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Position.h"
#include "../src/Dimension.h"

namespace datas{

Position::Position()
{}

Position::Position(int iX, int iY){
	_x = iX;
	_y = iY;
}

Position::~Position()
{}

void Position::setPosition(int x, int y){
	setX(x);
	setY(y);
}

bool Position::operator==(const Position& iPosition) const {
	return ((iPosition._x == _x) && (iPosition._y) == _y);
}

bool Position::operator!=(const Position& iPosition) const {
	return !(*this == iPosition);
}

bool Position::isValid() const{
	return ((_x >=0) && (_x<NBRE_LIGNE) && (_y>=0) && (_y < NBRE_COLONNE));
}

int Position::getX() const{
	return _x;
}

void Position::setX(int iX){
	_x = iX;
}

int Position::getY() const{
	return _y;
}

void Position::setY(int iY){
	_y = iY;
}

}
