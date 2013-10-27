/* 
 * File:   MusicComponent.hpp
 * Author: mk
 *
 * Created on 25 maj 2013, 12:02
 */

#ifndef MUSICCOMPONENT_HPP
#define	MUSICCOMPONENT_HPP
#include <SFML/Audio.hpp>
#include "rapidxml/rapidxml.hpp"
#include "Components/Component.hpp"

class MusicComponent: public Component
{
public:
	MusicComponent(sf::Music *music, int EID);
	MusicComponent(const MusicComponent& orig);
	MusicComponent(rapidxml::xml_node<>* componentNode);
	virtual ~MusicComponent();

	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);
	sf::Music *music;
};

#endif	/* MUSICCOMPONENT_HPP */

