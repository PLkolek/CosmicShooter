/*
 * Vector.h
 *
 *  Created on: 25 paź 2013
 *      Author: kolzi
 */

#ifndef VECTOR_H_
#define VECTOR_H_
#include <SFML/System/Vector2.hpp>

struct Vector : sf::Vector2f
{
	Vector();
	Vector(const sf::Vector2f& vector);
	Vector(float x, float y);
	Vector(const Vector& vector);
	virtual ~Vector();

	Vector& scaleToLength(float targetLength);
	float length() const;
	Vector direction() const;

};

#endif /* VECTOR_H_ */
