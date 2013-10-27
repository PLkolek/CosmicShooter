/* 
 * File:   PositionComponent.hpp
 * Author: marzena
 *
 * Created on 17 luty 2013, 22:51
 */

#ifndef POSITIONCOMPONENT_HPP
#define	POSITIONCOMPONENT_HPP

#include "Components/Component.hpp"
#include "rapidxml/rapidxml.hpp"

class PositionComponent: public Component
{
public:
	PositionComponent(int EID);
	PositionComponent(double x, double y, double z, double angle, int EID);
	PositionComponent(const PositionComponent& orig);
	PositionComponent(rapidxml::xml_node<>* componentNode);
	virtual ~PositionComponent();

	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);

	double x, y, z;
	double angle; //orientation
	int EID;
};

#endif	/* POSITIONCOMPONENT_HPP */

