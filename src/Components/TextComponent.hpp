/* 
 * File:   TextComponent.hpp
 * Author: kolzi
 *
 * Created on 31 maj 2013, 13:54
 */

#ifndef TEXTCOMPONENT_HPP
#define	TEXTCOMPONENT_HPP

#include "SFML/Graphics/Text.hpp"

#include "Component.hpp"

struct TextComponent: public Component
{
	TextComponent(int EID);
	TextComponent(std::string text, int EID);
	TextComponent(const TextComponent& orig);
	TextComponent(rapidxml::xml_node<>* componentNode);
	virtual ~TextComponent();

	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);
	sf::Text text;
};

#endif	/* TEXTCOMPONENT_HPP */

