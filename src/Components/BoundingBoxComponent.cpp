/* 
 * File:   BoundingBoxComponent.cpp
 * Author: marzena
 * 
 * Created on 18 luty 2013, 22:20
 */

#include "BoundingBoxComponent.hpp"
#include "Exceptions/RequiredAttributeNotFound.hpp"

#include <boost/lexical_cast.hpp>
#include <set>

BoundingBoxComponent::BoundingBoxComponent(int EID) :
		Component(EID), boundingBox(), topSolid(false), rightSolid(false), bottomSolid(false), leftSolid(false)
{
}
BoundingBoxComponent::BoundingBoxComponent(sf::Rect<double> boundingBox, int EID) :
		BoundingBoxComponent(EID)
{
	this->boundingBox = boundingBox;
}
BoundingBoxComponent::BoundingBoxComponent(rapidxml::xml_node<>* componentNode) :
		Component(-1), topSolid(false), rightSolid(false), bottomSolid(false), leftSolid(false)
{
	read(componentNode);
}

void BoundingBoxComponent::read(rapidxml::xml_node<>* componentNode)
{
	boundingBox.left = 0;
	boundingBox.top = 0;
	if (componentNode->first_attribute("x") != 0)
		boundingBox.left = boost::lexical_cast<double>(componentNode->first_attribute("x")->value());
	if (componentNode->first_attribute("y") != 0)
		boundingBox.top = boost::lexical_cast<double>(componentNode->first_attribute("y")->value());
	if (componentNode->first_attribute("w") != 0)
		boundingBox.width = boost::lexical_cast<double>(componentNode->first_attribute("w")->value());
	else
		throw RequiredAttributeNotFound("w", "BoundingBox");
	if (componentNode->first_attribute("h") != 0)
		boundingBox.height = boost::lexical_cast<double>(componentNode->first_attribute("h")->value());
	else
		throw RequiredAttributeNotFound("h", "BoundingBox");

	if (componentNode->first_attribute("topSolid") != 0)
		topSolid = boost::lexical_cast<bool>(componentNode->first_attribute("topSolid")->value());
	if (componentNode->first_attribute("rightSolid") != 0)
		rightSolid = boost::lexical_cast<bool>(componentNode->first_attribute("rightSolid")->value());
	if (componentNode->first_attribute("bottomSolid") != 0)
		bottomSolid = boost::lexical_cast<bool>(componentNode->first_attribute("bottomSolid")->value());
	if (componentNode->first_attribute("leftSolid") != 0)
		leftSolid = boost::lexical_cast<bool>(componentNode->first_attribute("leftSolid")->value());

	for (rapidxml::xml_attribute<> *att = componentNode->first_attribute("collisionGroup"); att;
			att = att->next_attribute("collisionGroup"))
	{
		collisionGroups.insert(boost::lexical_cast<int>(att->value()));
	}
}

Component* BoundingBoxComponent::clone(int newEID)
{
	Component* comp = new BoundingBoxComponent(*this);
	comp->EID = newEID;
	return comp;
}
