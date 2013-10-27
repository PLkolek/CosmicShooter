/* 
 * File:   HasScoreComponent.cpp
 * Author: kolzi
 * 
 * Created on 31 maj 2013, 13:45
 */

#include "HasScoreComponent.hpp"
#include "Exceptions/RequiredAttributeNotFound.hpp"

#include <boost/lexical_cast.hpp>

HasScoreComponent::HasScoreComponent(int EID) :
		Component(EID), scoreEID(-1)
{
}

HasScoreComponent::HasScoreComponent(int EID, int scoreEID) :
		Component(EID), scoreEID(scoreEID)
{
}

HasScoreComponent::HasScoreComponent(rapidxml::xml_node<>* componentNode) :
		HasScoreComponent(-1)
{
	read(componentNode);
}

void HasScoreComponent::read(rapidxml::xml_node<>* componentNode)
{
	if (componentNode->first_attribute("scoreEID") != 0)
		scoreEID = boost::lexical_cast<int>(
				componentNode->first_attribute("scoreEID")->value());
	else
		throw RequiredAttributeNotFound("scoreEID", "HasScore");
}

Component* HasScoreComponent::clone(int newEID)
{
	Component* comp = new HasScoreComponent(*this);
	comp->EID = newEID;
	return comp;
}
