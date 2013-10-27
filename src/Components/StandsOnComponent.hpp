/* 
 * File:   StandsOnComponent.hpp
 * Author: kolzi
 *
 * Created on 15 maj 2013, 18:16
 */

#ifndef STANDSONCOMPONENT_HPP
#define	STANDSONCOMPONENT_HPP

#include "Component.hpp"

struct StandsOnComponent: public Component
{
	StandsOnComponent(int EID);
	StandsOnComponent(rapidxml::xml_node<>* componentNode);

	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);

	bool standing;
	int standsOn;
	double baseJumpingPower;
	double baseJumpingTime;
	double jumpingTimeLeft;

	static const double defaultBaseJumpingTime;
	static const double defaultBaseJumpingPower;
};

#endif	/* STANDSONCOMPONENT_HPP */

