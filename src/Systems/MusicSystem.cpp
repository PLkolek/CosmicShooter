/* 
 * File:   MusicSystem.cpp
 * Author: mk
 * 
 * Created on 25 maj 2013, 11:01
 */

#include "MusicSystem.hpp"
#include <assert.h>
#include "General/Level.hpp"
#include "Components/MusicComponent.hpp"
#include <boost/cast.hpp>

MusicSystem::MusicSystem(Level::CompMap& components) :
		System(components)
{
}

MusicSystem::MusicSystem(const MusicSystem& orig) :
		System(orig)
{
}

MusicSystem::~MusicSystem()
{
}
void MusicSystem::addEntity(int EID)
{
	assert(components.find(Level::CompKey(EID, "Music")) != components.end());
	entities.insert(EID);
	MusicComponent& musC = *boost::polymorphic_downcast<MusicComponent*>(
			components.at(Level::CompKey(EID, "Music")));
	musC.music->play();
}

void MusicSystem::update(sf::Time deltaTime)
{

}
