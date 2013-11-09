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
	float deltaT = time.asSeconds();
	for (auto it = entities.begin(); it != entities.end(); it++)
	{
		PositionComponent& posC = *boost::polymorphic_downcast<PositionComponent*>(components.at(Level::CompKey(*it, "Position")));
		PhysicsComponent& physC = *boost::polymorphic_downcast<PhysicsComponent*>(components.at(Level::CompKey(*it, "Physics")));

		physC.a += physC.f/physC.m;

		Vector oldV = physC.v;
		physC.v += physC.a * deltaT;

		if (oldV.direction() == physC.v.direction()*-1.f)
		{
			physC.v = Vector();
		}

		/*if (physC.v.x > physC.maxSpeed * groundC.maxSpeedMultiplier)
		{
			physC.v.x = physC.maxSpeed * groundC.maxSpeedMultiplier;
		}
		if (physC.v.x < -physC.maxSpeed * groundC.maxSpeedMultiplier)
		{
			physC.v.x = -physC.maxSpeed * groundC.maxSpeedMultiplier;
		}*/

		posC.pos += deltaT * physC.v;

		posC.angle += deltaT * physC.angularV;
		posC.angle -= (360.0 * int(posC.angle / 360.0));
		if(posC.pos.x+posC.dim.x>800)
		{
			posC.pos.x=800-posC.dim.x-(posC.pos.x+posC.dim.x-800);
			physC.v.x*=-1.f;
		}
		else if(posC.pos.x<0)
		{
			posC.pos.x=-posC.pos.x;
			physC.v.x*=-1.f;
		}

		if(posC.pos.y+posC.dim.y>600)
		{
			posC.pos.y=600-posC.dim.y-(posC.pos.y+posC.dim.y-600);
			physC.v.y*=-1.f;
		}
		else if(posC.pos.y<0)
		{
			posC.pos.y=-posC.pos.y;
			physC.v.y*=-1.f;
		}


		physC.prevA=physC.a;
		physC.prevF=physC.f;
		physC.prevM=physC.m;
		physC.prevV=physC.v;
		physC.prevAngularV=physC.angularV;

		physC.a=Vector();
		physC.f=Vector();
	}
	std::cerr << "Movement system: " << timer.getElapsedTime().asMilliseconds() << "\n";
}
