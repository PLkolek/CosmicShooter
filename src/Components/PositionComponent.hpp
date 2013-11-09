/* 
 * File:   PositionComponent.hpp
 * Author: marzena
 *
 * Created on 17 luty 2013, 22:51
 */

#ifndef POSITIONCOMPONENT_HPP
#define	POSITIONCOMPONENT_HPP

#include "Components/Component.hpp"
#include "Utility/Vector.h"
#include "rapidxml/rapidxml.hpp"

class PositionComponent: public Component
{
public:
	PositionComponent(int EID);
	PositionComponent(Vector p, Vector dim, double angle, int EID);
	PositionComponent(const PositionComponent& orig);
	PositionComponent(rapidxml::xml_node<>* componentNode);
	virtual ~PositionComponent();

	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);

	Vector pos;
	Vector dim;
	double angle; //orientation
};

#endif	/* POSITIONCOMPONENT_HPP */

