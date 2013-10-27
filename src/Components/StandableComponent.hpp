/* 
 * File:   StandableComponent.hpp
 * Author: kolzi
 *
 * Created on 15 maj 2013, 18:58
 */

#ifndef STANDABLECOMPONENT_HPP
#define	STANDABLECOMPONENT_HPP

#include "rapidxml/rapidxml.hpp"

#include "Component.hpp"

struct StandableComponent: public Component
{
	StandableComponent(int EID);
	StandableComponent(int EID, double accelerationMultiplier,
			double maxSpeedMultiplier, double stoppingMultiplier,
			double jumpingAccelerationMultiplier, double jumpingTimeMultiplier);
	StandableComponent(rapidxml::xml_node<>* componentNode);

	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);

	double accelerationMultiplier;
	double maxSpeedMultiplier;
	double stoppingMultiplier;
	double jumpingAccelerationMultiplier;
	double jumpingTimeMultiplier; //time you can hold jump

	static const double defaultAccelerationMultiplier;
	static const double defaultMaxSpeedMultiplier;
	static const double defaultStoppingMultiplier;
	static const double defaultJumpingAccelerationMultiplier;
	static const double defaultJumpingTimeMultiplier; //time you can hold jump

};

#endif	/* STANDABLECOMPONENT_HPP */

