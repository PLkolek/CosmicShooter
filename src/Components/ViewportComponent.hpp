/* 
 * File:   ViewportComponent.hpp
 * Author: marzena
 *
 * Created on 18 luty 2013, 22:28
 */

#ifndef VIEWPORTCOMPONENT_HPP
#define	VIEWPORTCOMPONENT_HPP

#include "Components/Component.hpp"
#include <SFML/Graphics/Rect.hpp>
#include "rapidxml/rapidxml.hpp"

struct ViewportComponent: public Component
{
	ViewportComponent(int x1, int y1, int w, int h, int EID);
	ViewportComponent(const sf::Rect<int>& rectangle, int EID);
	ViewportComponent(rapidxml::xml_node<>* componentNode);

	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);

	sf::Rect<int> destination;
};

#endif	/* VIEWPORTCOMPONENT_HPP */

