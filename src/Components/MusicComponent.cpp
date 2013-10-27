/* 
 * File:   MusicComponent.cpp
 * Author: mk
 * 
 * Created on 25 maj 2013, 12:02
 */

#include "MusicComponent.hpp"
#include "General/MusicManager.h"
#include "Exceptions/RequiredAttributeNotFound.hpp"

MusicComponent::MusicComponent(sf::Music *music, int EID) :
		Component(EID), music(music)
{
}

MusicComponent::MusicComponent(const MusicComponent& orig) :
		Component(orig.EID), music(orig.music)
{
}

MusicComponent::MusicComponent(rapidxml::xml_node<>* componentNode) :
		Component(-1)
{
	read(componentNode);
}

MusicComponent::~MusicComponent()
{
}

void MusicComponent::read(rapidxml::xml_node<>* componentNode)
{
	if (componentNode->first_attribute("file") == 0)
		throw RequiredAttributeNotFound("file", "MusicComponent");
	music = MusicManager::getMusic(
			componentNode->first_attribute("file")->value());
}

Component* MusicComponent::clone(int newEID)
{
	Component* comp = new MusicComponent(*this);
	comp->EID = newEID;
	return comp;
}

