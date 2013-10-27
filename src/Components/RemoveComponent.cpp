/* 
 * File:   RemoveComponent.cpp
 * Author: kolzi
 * 
 * Created on 8 czerwiec 2013, 18:54
 */

#include <boost/lexical_cast.hpp>

#include "RemoveComponent.hpp"
#include "Exceptions/RequiredAttributeNotFound.hpp"

RemoveComponent::RemoveComponent(int EID) :
		Component(EID), removeGroup(-1), target(true)
{
}

RemoveComponent::RemoveComponent(int EID, int removeGroup) :
		Component(EID), removeGroup(removeGroup), target(true)
{
}

RemoveComponent::RemoveComponent(rapidxml::xml_node<>* componentNode) :
		RemoveComponent(-1)
{
	read(componentNode);
}

void RemoveComponent::read(rapidxml::xml_node<>* componentNode)
{
	if (componentNode->first_attribute("removeGroup") != 0)
		removeGroup = boost::lexical_cast<double>(
				componentNode->first_attribute("removeGroup")->value());
	else if (removeGroup == -1)
		throw RequiredAttributeNotFound("removeGroup", "Remove");

	if (componentNode->first_attribute("target") != 0)
		target = boost::lexical_cast<bool>(
				componentNode->first_attribute("target")->value());
}

Component* RemoveComponent::clone(int newEID)
{
	Component* comp = new RemoveComponent(*this);
	comp->EID = newEID;
	return comp;
}
