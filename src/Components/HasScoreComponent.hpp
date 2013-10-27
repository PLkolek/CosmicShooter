/* 
 * File:   HasScoreComponent.hpp
 * Author: kolzi
 *
 * Created on 31 maj 2013, 13:45
 */

#ifndef HASSCORECOMPONENT_HPP
#define	HASSCORECOMPONENT_HPP

#include "Component.hpp"

struct HasScoreComponent: public Component
{
	HasScoreComponent(int EID);
	HasScoreComponent(int EID, int scoreEID);
	HasScoreComponent(rapidxml::xml_node<>* componentNode);

	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);

	int scoreEID;
};

#endif	/* HASSCORECOMPONENT_HPP */

