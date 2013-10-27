/* 
 * File:   PositionRelativeToComponent.hpp
 * Author: kolzi
 *
 * Created on 3 czerwiec 2013, 19:25
 */

#ifndef POSITIONRELATIVETOCOMPONENT_HPP
#define	POSITIONRELATIVETOCOMPONENT_HPP

#include "Component.hpp"

struct PositionRelativeToComponent: public Component
{
	PositionRelativeToComponent(int EID);
	PositionRelativeToComponent(int EID, int relativeTo);
	PositionRelativeToComponent(rapidxml::xml_node<>* componentNode);

	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);

	int relativeTo;
};

#endif	/* POSITIONRELATIVETOCOMPONENT_HPP */

