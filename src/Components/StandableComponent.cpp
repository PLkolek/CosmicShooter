/* 
 * File:   StandableComponent.cpp
 * Author: kolzi
 * 
 * Created on 15 maj 2013, 18:58
 */

#include <boost/lexical_cast.hpp>

#include "StandableComponent.hpp"
#include "Component.hpp"

const double StandableComponent::defaultAccelerationMultiplier = 1;
const double StandableComponent::defaultMaxSpeedMultiplier = 1;
const double StandableComponent::defaultStoppingMultiplier = 1;
const double StandableComponent::defaultJumpingAccelerationMultiplier = 1;
const double StandableComponent::defaultJumpingTimeMultiplier = 1; //time you can hold jump

StandableComponent::StandableComponent(int EID) :
		Component(EID), accelerationMultiplier(defaultAccelerationMultiplier), maxSpeedMultiplier(
				defaultMaxSpeedMultiplier), stoppingMultiplier(
				defaultStoppingMultiplier), jumpingAccelerationMultiplier(
				defaultJumpingAccelerationMultiplier), jumpingTimeMultiplier(
				defaultJumpingTimeMultiplier)
{

}

StandableComponent::StandableComponent(int EID, double accelerationMultiplier,
		double maxSpeedMultiplier, double stoppingMultiplier,
		double jumpingAccelerationMultiplier, double jumpingTimeMultiplier) :
		StandableComponent(-1)
{
}

StandableComponent::StandableComponent(rapidxml::xml_node<>* componentNode) :
		Component(-1), accelerationMultiplier(defaultAccelerationMultiplier), maxSpeedMultiplier(
				defaultMaxSpeedMultiplier), stoppingMultiplier(
				defaultStoppingMultiplier), jumpingAccelerationMultiplier(
				defaultJumpingAccelerationMultiplier), jumpingTimeMultiplier(
				defaultJumpingTimeMultiplier)
{
	read(componentNode);
}

void StandableComponent::read(rapidxml::xml_node<>* componentNode)
{
	if (componentNode->first_attribute("accelerationMultiplier") != 0)
		accelerationMultiplier =
				boost::lexical_cast<double>(
						componentNode->first_attribute("accelerationMultiplier")->value());
	if (componentNode->first_attribute("maxSpeedMultiplier") != 0)
		maxSpeedMultiplier = boost::lexical_cast<double>(
				componentNode->first_attribute("maxSpeedMultiplier")->value());
	if (componentNode->first_attribute("stoppingMultiplier") != 0)
		stoppingMultiplier = boost::lexical_cast<double>(
				componentNode->first_attribute("stoppingMultiplier")->value());
	if (componentNode->first_attribute("jumpingAccelerationMultiplier") != 0)
		stoppingMultiplier =
				boost::lexical_cast<double>(
						componentNode->first_attribute(
								"jumpingAccelerationMultiplier")->value());
	if (componentNode->first_attribute("jumpingTimeMultiplier") != 0)
		stoppingMultiplier =
				boost::lexical_cast<double>(
						componentNode->first_attribute("jumpingTimeMultiplier")->value());
}

Component* StandableComponent::clone(int newEID)
{
	Component* comp = new StandableComponent(*this);
	comp->EID = newEID;
	return comp;
}
