/* 
 * File:   RemoveComponent.hpp
 * Author: kolzi
 *
 * Created on 8 czerwiec 2013, 18:54
 */

#ifndef REMOVECOMPONENT_HPP
#define	REMOVECOMPONENT_HPP

#include "Component.hpp"

struct RemoveComponent: public Component
{
public:
	RemoveComponent(int EID);
	RemoveComponent(int EID, int removeGroup);
	RemoveComponent(rapidxml::xml_node<>* componentNode);

	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);

	int removeGroup;
	bool target;
};

#endif	/* REMOVECOMPONENT_HPP */

