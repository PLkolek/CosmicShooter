/* 
 * File:   RemoveOnContactSystem.cpp
 * Author: kolzi
 * 
 * Created on 8 czerwiec 2013, 19:20
 */

#include <boost/cast.hpp>

#include "RemoveOnContactSystem.hpp"
#include "Components/RemoveComponent.hpp"
#include "Components/BoundingBoxComponent.hpp"

RemoveOnContactSystem::RemoveOnContactSystem(Level::CompMap& components,
		Level& level) :
		System(components), level(level)
{
}

RemoveOnContactSystem::RemoveOnContactSystem(const RemoveOnContactSystem& orig) :
		System(orig), level(orig.level)
{
}

RemoveOnContactSystem::~RemoveOnContactSystem()
{
}

void RemoveOnContactSystem::addEntity(int EID)
{
	assert(
			components.find(Level::CompKey(EID, "Remove")) != components.end()
					&& components.find(Level::CompKey(EID, "BoundingBox"))
							!= components.end());
	entities.insert(EID);
}

void RemoveOnContactSystem::update(sf::Time deltaTime)
{
	sf::Clock timer;
	for (auto it = entities.begin(); it != entities.end(); it++)
	{
		BoundingBoxComponent& bbi = *boost::polymorphic_downcast<
				BoundingBoxComponent*>(
				components.at(Level::CompKey(*it, "BoundingBox")));
		RemoveComponent& remCi = *boost::polymorphic_downcast<RemoveComponent*>(
				components.at(Level::CompKey(*it, "Remove")));
		for (BoundingBoxComponent::CollisionData collWith : bbi.collidedWith)
		{
			if (components.find(Level::CompKey(collWith.EID, "Remove"))
					!= components.end())
			{
				RemoveComponent& remCj = *boost::polymorphic_downcast<
						RemoveComponent*>(
						components.at(Level::CompKey(collWith.EID, "Remove")));
				if (remCj.target && remCi.removeGroup == remCj.removeGroup)
				{
					level.removeEntity(collWith.EID);
				}
			}
		}
	}
	std::cerr << "Remove on contact system: "
			<< timer.getElapsedTime().asMilliseconds() << "\n";
}
