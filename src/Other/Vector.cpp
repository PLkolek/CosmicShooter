/*
 * Vector.cpp
 *
 *  Created on: 25 paź 2013
 *      Author: kolzi
 */

#include "Other/Vector.h"

#include <cmath>


Vector::Vector()
:sf::Vector2f(0,0)
{
}

Vector::Vector(float x, float y)
:sf::Vector2f(x,y)
{
}

Vector::Vector(const Vector& v)
:sf::Vector2f(v)
{
}

Vector::Vector(const sf::Vector2f& v)
:sf::Vector2f(v)
{
}

Vector::~Vector()
{
}

Vector& Vector::scaleToLength(float targetLength)
{
	Vector v=direction()*targetLength;
	x=v.x;
	y=v.y;
	return *this;
}

float Vector::length() const
{
	return sqrt(x*x+y*y);
}

Vector Vector::direction() const
{
	return *this/length();
}
