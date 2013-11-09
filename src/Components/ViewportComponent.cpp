/* 
 * File:   ViewportComponent.cpp
 * Author: marzena
 * 
 * Created on 18 luty 2013, 22:28
 */

#include "ViewportComponent.hpp"

#include <boost/lexical_cast.hpp>

ViewportComponent::ViewportComponent(int x1, int y1, int w, int h, int EID) :
		Component(EID), destination(x1, y1, w, h)
{
}

ViewportComponent::ViewportComponent(const sf::Rect<int>& rectangle, int EID) :
		Component(EID), destination(rectangle)
{
}

ViewportComponent::ViewportComponent(rapidxml::xml_node<>* componentNode) :
		Component(-1)
{
	read(componentNode);
}

void ViewportComponent::read(rapidxml::xml_node<>* componentNode)
{
	destination.left = 0;
	destination.top = 0;
	if (componentNode->first_attribute("x") != 0)
		destination.left = boost::lexical_cast<double>(
				componentNode->first_attribute("x")->value());
	if (componentNode->first_attribute("y") != 0)
		destination.top = boost::lexical_cast<double>(
				componentNode->first_attribute("y")->value());
	if (componentNode->first_attribute("w") == 0
			|| std::string(componentNode->first_attribute("w")->value())
					== "max")
	{
		//FIXME: Window size=max!!!
		destination.width = 800;
	}
	else
		destination.width = destination.left = boost::lexical_cast<int>(
				componentNode->first_attribute("w")->value());
	if (componentNode->first_attribute("h") == 0
			|| std::string(componentNode->first_attribute("h")->value())
					== "max")
	{
		//FIXME: Window size=max!!!
		destination.height = 600;
	}
	else
		destination.height = destination.left = boost::lexical_cast<int>(
				componentNode->first_attribute("h")->value());
}

Component* ViewportComponent::clone(int newEID)
{
	Component* comp = new ViewportComponent(*this);
	comp->EID = newEID;
	return comp;
}
