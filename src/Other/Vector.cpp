/*
 * Vector.cpp
 *
 *  Created on: 25 paź 2013
 *      Author: kolzi
 */

#include "Other/Vector.h"


Vector::Vector()
:x(0), y(0)
{
}

Vector::Vector(double x, double y)
:x(x), y(y)
{
}

Vector::Vector(const Vector& v)
:x(v.x), y(v.y)
{
}

Vector::~Vector()
{
}

Vector Vector::operator+(const Vector& v) const
{
	return Vector(this->x+v.y, this->y+v.y);
}

Vector Vector::operator*(const double& v) const
{
	return Vector(this->x*v, this->y*v);
}

Vector& Vector::operator+=(const Vector& v)
{
	this->x+=v.x;
	this->y+=v.y;
	return *this;
}
