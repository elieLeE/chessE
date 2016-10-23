/*
 * Position.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Position.h"
#include "typeDefine/Dimension.h"
#include <cmath>

namespace datas{

Position::Position()
{}

Position::Position(int iX, int iY):
		_x(iX),
		_y(iY)
{}

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

bool Position::sameLigne(const Position& iPosition) const{
	return (_x == iPosition.getX());
}

bool Position::sameCol(const Position& iPosition) const{
	return (this->_y == iPosition.getY());
}
bool Position::isValid() const{
	return ((_x >=0) && (_x<NBRE_LIGNE) && (_y>=0) && (_y < NBRE_COLONNE));
}

int Position::getX() const{
	return _x;
}

//add verification du parametre ??
void Position::setX(int iX){
	_x = iX;
}

int Position::getY() const{
	return _y;
}

void Position::setY(int iY){
	_y = iY;
}

int Position::evaluateDistance(const Position& iPosition) const{
	int x2 = std::abs(iPosition.getX() - this->getX());
	x2 = x2 * x2;

	int y2 = std::abs(iPosition.getY() - this->getY());
	y2 = y2 * y2;

	return (x2 + y2);
}

EColor Position::getColorCase() const{
	int sum = getX() + getY();

	return (sum%2==0?WHITE:BLACK);
}

}
