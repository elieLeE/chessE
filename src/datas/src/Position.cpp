/*
 * Position.cpp
 *
 *  Created on: 17 sept. 2016
 *      Author: le_e
 */

#include "Position.h"
#include "typeDefine/Dimension.h"
#include <cmath>
#include <fstream>

namespace datas{

Position::Position():
		_x(1),
		_y(1)
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

bool Position::sameLigne(const Position& iPosition) const{
	return (_y == iPosition.getY());
}

bool Position::sameCol(const Position& iPosition) const{
	return (_x == iPosition.getX());
}

int Position::diffLigne(const Position& iPosition) const{
	return std::abs(getY() - iPosition.getY());
}

int Position::diffCol(const Position& iPosition) const{
	return std::abs(getX() - iPosition.getX());
}

bool Position::isValid() const{
	return ((_x >=1) && (_x<=NBRE_COLONNE) && (_y>=1) && (_y <= NBRE_LIGNE));
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
	int sum = _x + _y;

	return (sum%2==0?WHITE:BLACK);
}

bool Position::operator==(const Position& iPosition) const {
	return ((iPosition._x == _x) && (iPosition._y == _y));
}

bool Position::operator!=(const Position& iPosition) const {
	return !(*this == iPosition);
}

void Position::operator=(const Position& iPosition){
	setX(iPosition.getX());
	setY(iPosition.getY());
}

void Position::toStream(std::ostream& os) const{
	os << "(" << _x << ", " << _y << ")";
}

std::ostream& operator<<(std::ostream& os, const Position& iPosition) {
	iPosition.toStream(os);

	return os;
}

}
