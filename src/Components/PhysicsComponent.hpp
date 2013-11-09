/* 
 * File:   PhysicsComponent.hpp
 * Author: marzena
 *
 * Created on 19 luty 2013, 22:38
 */

#ifndef PHYSICSCOMPONENT_HPP
#define	PHYSICSCOMPONENT_HPP

#include "Components/Component.hpp"
#include "Utility/Vector.h"
#include "rapidxml/rapidxml.hpp"

struct PhysicsComponent: public Component
{
	PhysicsComponent(int EID, float mass, double acceleration, double maxSpeed,
			double stoppingSpeed);
	PhysicsComponent(rapidxml::xml_node<>* componentNode);

	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);

	Vector v;
	Vector a;
	Vector f;
	float m;
	double angularV;

	Vector prevV;
	Vector prevA;
	Vector prevF;
	double prevM;
	double prevAngularV;

	double acceleration;
	double maxSpeed;
	double stoppingSpeed;
};

#endif	/* PHYSICSCOMPONENT_HPP */

