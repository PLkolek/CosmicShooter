/* 
 * File:   PositionComponent.cpp
 * Author: marzena
 * 
 * Created on 17 luty 2013, 22:51
 */

#include "PositionComponent.hpp"
#include "General/ComponentsEnum.hpp"
#include "Exceptions/RequiredAttributeNotFound.hpp"

#include <boost/lexical_cast.hpp>

PositionComponent::PositionComponent(int EID) :
		Component(EID), pos(),dim(), angle(0)
{

}

PositionComponent::PositionComponent(Vector p, Vector dim, double angle, int EID) :
		Component(EID), pos(p), dim(dim), angle(angle)
{

}

PositionComponent::PositionComponent(const PositionComponent& orig) :
		Component(orig.EID), pos(orig.pos), dim(orig.dim), angle(orig.angle)
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
		pos.x = boost::lexical_cast<float>(componentNode->first_attribute("x")->value());
	if (componentNode->first_attribute("y") != 0)
		pos.y = boost::lexical_cast<float>(componentNode->first_attribute("y")->value());
	if (componentNode->first_attribute("w") != 0)
		dim.x = boost::lexical_cast<float>(componentNode->first_attribute("w")->value());
	if (componentNode->first_attribute("h") != 0)
		dim.y = boost::lexical_cast<float>(componentNode->first_attribute("h")->value());

	if (componentNode->first_attribute("angle") != 0)
		angle = boost::lexical_cast<float>(componentNode->first_attribute("angle")->value());

}

Component* PositionComponent::clone(int newEID)
{
	Component* comp = new PositionComponent(*this);
	comp->EID = newEID;
	return comp;
}
