/* 
 * File:   CameraSourceComponent.hpp
 * Author: marzena
 *
 * Created on 18 luty 2013, 22:38
 */

#ifndef CAMERASOURCECOMPONENT_HPP
#define	CAMERASOURCECOMPONENT_HPP

#include "Components/Component.hpp"
#include "rapidxml/rapidxml.hpp"

struct CameraSourceComponent: public Component
{
	CameraSourceComponent(float offsetX, float offsetY, float sourceWidth, float sourceHeight, int EID);
	CameraSourceComponent(rapidxml::xml_node<>* componentNode);

	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);

	float offsetX, offsetY;
	float sourceHeight, sourceWidth;
};

#endif	/* CAMERASOURCECOMPONENT_HPP */

