/* 
 * File:   PositionComponent.cpp
 * Author: marzena
 * 
 * Created on 17 luty 2013, 22:51
 */

#include "PositionComponent.hpp"

#include <boost/lexical_cast.hpp>

PositionComponent::PositionComponent(int EID) :
		Component(EID), pos(), angle(0)
{

}

PositionComponent::PositionComponent(Vector p, double angle, int EID) :
		Component(EID), pos(p), angle(angle)
{

}

PositionComponent::PositionComponent(const PositionComponent& orig) :
		Component(orig.EID), pos(orig.pos), angle(orig.angle)
{
}

PositionComponent::~PositionComponent()
{
}

PositionComponent::PositionComponent(rapidxml::xml_node<>* componentNode) :
		PositionComponent(-1)
{
	read(componentNode);
}

void PositionComponent::read(rapidxml::xml_node<>* componentNode)
{
	if (componentNode->first_attribute("x") != 0)
		pos.x = boost::lexical_cast<double>(componentNode->first_attribute("x")->value());
	if (componentNode->first_attribute("y") != 0)
		pos.y = boost::lexical_cast<double>(componentNode->first_attribute("y")->value());
	if (componentNode->first_attribute("angle") != 0)
		angle = boost::lexical_cast<double>(componentNode->first_attribute("angle")->value());
}

Component* PositionComponent::clone(int newEID)
{
	Component* comp = new PositionComponent(*this);
	comp->EID = newEID;
	return comp;
}
