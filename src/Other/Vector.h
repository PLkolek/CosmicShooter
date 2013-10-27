/*
 * Vector.h
 *
 *  Created on: 25 paź 2013
 *      Author: kolzi
 */

#ifndef VECTOR_H_
#define VECTOR_H_

struct Vector
{
	Vector();
	Vector(double x, double y);
	Vector(const Vector& vector);
	virtual ~Vector();

	double x, y;
	Vector operator+(const Vector& right) const;
	Vector operator*(const double& a) const;
	Vector& operator+=(const Vector& right);

};

#endif /* VECTOR_H_ */
