/* 
 * File:   StandsOnComponent.cpp
 * Author: kolzi
 * 
 * Created on 15 maj 2013, 18:16
 */

#include "StandsOnComponent.hpp"

#include <boost/lexical_cast.hpp>

const double StandsOnComponent::defaultBaseJumpingPower = 0;
const double StandsOnComponent::defaultBaseJumpingTime = 0;

StandsOnComponent::StandsOnComponent(int EID) :
		Component(EID), standing(false), standsOn(-1), baseJumpingPower(
				defaultBaseJumpingPower), baseJumpingTime(
				defaultBaseJumpingTime), jumpingTimeLeft(0)
{
}

StandsOnComponent::StandsOnComponent(rapidxml::xml_node<>* componentNode) :
		StandsOnComponent(-1)
{
	read(componentNode);
}

void StandsOnComponent::read(rapidxml::xml_node<>* componentNode)
{
	if (componentNode->first_attribute("jumpingPower") != 0)
		baseJumpingPower = boost::lexical_cast<double>(
				componentNode->first_attribute("jumpingPower")->value());
	if (componentNode->first_attribute("jumpingTime") != 0)
		baseJumpingTime = boost::lexical_cast<double>(
				componentNode->first_attribute("jumpingTime")->value());
	if (componentNode->first_attribute("standsOn") != 0)
		standsOn = boost::lexical_cast<int>(
				componentNode->first_attribute("standsOn")->value());
	if (componentNode->first_attribute("standing") != 0)
		standing = boost::lexical_cast<bool>(
				componentNode->first_attribute("standing")->value());
}

Component* StandsOnComponent::clone(int newEID)
{
	Component* comp = new StandsOnComponent(*this);
	comp->EID = newEID;
	return comp;
}

