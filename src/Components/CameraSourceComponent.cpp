/* 
 * File:   CameraSourceComponent.cpp
 * Author: marzena
 * 
 * Created on 18 luty 2013, 22:38
 */

#include "CameraSourceComponent.hpp"
#include <boost/lexical_cast.hpp>

CameraSourceComponent::CameraSourceComponent(float offsetX, float offsetY,
		float offsetZ, float sourceWidth, float sourceHeight, int EID) :
		Component(EID), offsetX(offsetX), offsetY(offsetY), offsetZ(offsetZ), sourceHeight(
				sourceHeight), sourceWidth(sourceWidth)
{
}

CameraSourceComponent::CameraSourceComponent(
		rapidxml::xml_node<>* componentNode) :
		Component(-1)
{
	read(componentNode);
}

void CameraSourceComponent::read(rapidxml::xml_node<>* componentNode)
{
	offsetX = boost::lexical_cast<float>(
			componentNode->first_attribute("offsetX")->value());
	offsetY = boost::lexical_cast<float>(
			componentNode->first_attribute("offsetY")->value());
	offsetZ = boost::lexical_cast<float>(
			componentNode->first_attribute("offsetZ")->value());
	if (componentNode->first_attribute("w") == 0
			|| std::string(componentNode->first_attribute("w")->value())
					== "max")
	{
		//FIXME: Window size=max!!!
		sourceWidth = 800;
	}
	else
		sourceWidth = boost::lexical_cast<float>(
				componentNode->first_attribute("w")->value());
	if (componentNode->first_attribute("h") == 0
			|| std::string(componentNode->first_attribute("h")->value())
					== "max")
	{
		//FIXME: Window size=max!!!
		sourceHeight = 600;
	}
	else
		sourceHeight = boost::lexical_cast<float>(
				componentNode->first_attribute("h")->value());
}

Component* CameraSourceComponent::clone(int newEID)
{
	Component* comp = new CameraSourceComponent(*this);
	comp->EID = newEID;
	return comp;
}
