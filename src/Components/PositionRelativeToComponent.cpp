/* 
 * File:   PositionRelativeToComponent.cpp
 * Author: kolzi
 * 
 * Created on 3 czerwiec 2013, 19:26
 */

#include "PositionRelativeToComponent.hpp"

#include <boost/lexical_cast.hpp>

PositionRelativeToComponent::PositionRelativeToComponent(int EID) :
		Component(EID), relativeTo(-1)
{
}

PositionRelativeToComponent::PositionRelativeToComponent(int EID,
		int relativeTo) :
		Component(EID), relativeTo(relativeTo)
{
}

PositionRelativeToComponent::PositionRelativeToComponent(
		rapidxml::xml_node<>* componentNode) :
		PositionRelativeToComponent(-1)
{
	read(componentNode);
}

void PositionRelativeToComponent::read(rapidxml::xml_node<>* componentNode)
{
	if (componentNode->first_attribute("relativeTo") != 0)
		relativeTo = boost::lexical_cast<int>(
				componentNode->first_attribute("relativeTo")->value());
}

Component* PositionRelativeToComponent::clone(int newEID)
{
	std::cerr << "Cloning position relative to\n";
	Component* comp = new PositionRelativeToComponent(*this);
	comp->EID = newEID;
	std::cerr << "Cloned!\n";
	return comp;
}
