/* 
 * File:   PhysicsSystem.cpp
 * Author: marzena
 * 
 * Created on 19 luty 2013, 22:44
 */

#include "MovementSystem.hpp"
#include "Components/StandsOnComponent.hpp"
#include "Components/StandableComponent.hpp"
#include <iostream>
#include <unordered_map>
#include <assert.h>
#include <SFML/System/Time.hpp>
#include <boost/cast.hpp>

MovementSystem::MovementSystem(Level::CompMap& components) :
		System(components)
{
}

MovementSystem::MovementSystem(const MovementSystem& orig) :
		System(orig)
{
}

MovementSystem::~MovementSystem()
{
}

void MovementSystem::addEntity(int EID)
{
	assert(
			components.find(Level::CompKey(EID, "Position")) != components.end()
					&& components.find(Level::CompKey(EID, "Physics")) != components.end());
	//	components.find(Level::CompKey(EID, "StandsOn")) != components.end() );
	entities.insert(EID);
}

void MovementSystem::update(sf::Time time)
{
	sf::Clock timer;
	double deltaT = time.asSeconds();
	for (auto it = entities.begin(); it != entities.end(); it++)
	{
		PositionComponent& posC = *boost::polymorphic_downcast<PositionComponent*>(components.at(Level::CompKey(*it, "Position")));
		PhysicsComponent& physC = *boost::polymorphic_downcast<PhysicsComponent*>(components.at(Level::CompKey(*it, "Physics")));

		StandsOnComponent empty(*it);
		StandsOnComponent& standsOnC = (
				components.find(Level::CompKey(*it, "StandsOn")) != components.end() ?
						*boost::polymorphic_downcast<StandsOnComponent*>(components.at(Level::CompKey(*it, "StandsOn"))) : empty);

		//StandsOnComponent& standsOnC = *boost::polymorphic_downcast<StandsOnComponent*>(components.at(Level::CompKey(*it, "StandsOn")));

		StandableComponent groundC(-1, 0, 1000, 0, 0, 0);
		if (standsOnC.standing)
		{
			StandableComponent empty(-1);
			groundC = (
					components.find(Level::CompKey(standsOnC.standsOn, "Standable")) != components.end() ?
							*boost::polymorphic_downcast<StandableComponent*>(
									components.at(Level::CompKey(standsOnC.standsOn, "Standable"))) :
							empty);
		}
		else
			groundC = StandableComponent(-1);

		double oldVx = physC.v.x;
		physC.v += physC.a * deltaT;

		if (oldVx * physC.v.x < 0)
		{
			physC.v.x = 0;
		}

		if (physC.v.x > physC.maxSpeed * groundC.maxSpeedMultiplier)
		{
			physC.v.x = physC.maxSpeed * groundC.maxSpeedMultiplier;
		}
		if (physC.v.x < -physC.maxSpeed * groundC.maxSpeedMultiplier)
		{
			physC.v.x = -physC.maxSpeed * groundC.maxSpeedMultiplier;
		}

		posC.x += deltaT * physC.v.x;
		posC.y += deltaT * physC.v.y;

		posC.angle += deltaT * physC.angularV;
		posC.angle -= (360.0 * int(posC.angle / 360.0));
	}
	std::cerr << "Movement system: " << timer.getElapsedTime().asMilliseconds() << "\n";
}
