/* 
 * File:   PlayerInputSystem.cpp
 * Author: marzena
 * 
 * Created on 18 luty 2013, 21:19
 */

#include <assert.h>
#include <SFML/Window.hpp>
#include <boost/cast.hpp>

#include "PlayerInputSystem.hpp"
#include "Components/StandsOnComponent.hpp"
#include "Components/StandableComponent.hpp"
#include "States/StateEngine.hpp"

PlayerInputSystem::PlayerInputSystem(Level::CompMap& components,
		sf::RenderWindow& app) :
		System(components), app(app)
{
}

PlayerInputSystem::PlayerInputSystem(const PlayerInputSystem& orig) :
		System(orig), app(orig.app)
{
}

PlayerInputSystem::~PlayerInputSystem()
{
}

void PlayerInputSystem::addEntity(int EID)
{
	assert(components.find(Level::CompKey(EID, "Physics")) != components.end());
	entities.insert(EID);
}

void PlayerInputSystem::update(sf::Time deltaTime)
{
	sf::Clock timer;

	sf::Event event;
	while (app.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			app.close();
	}
	for (auto eid : entities)
	{
		PhysicsComponent& pC = *boost::polymorphic_downcast<PhysicsComponent*>(
				components.at(Level::CompKey(eid, "Physics")));
		StandsOnComponent soEmpty(-1);
		StandsOnComponent& soC =
				components.find(Level::CompKey(eid, "StandsOn"))
						!= components.end() ?
						*boost::polymorphic_downcast<StandsOnComponent*>(
								components.at(
										Level::CompKey(eid, "StandsOn"))) :
						soEmpty;

		StandableComponent sEmpty(-1);
		StandableComponent sC =
				components.find(Level::CompKey(soC.standsOn, "Standable"))
						!= components.end() ?
						*boost::polymorphic_downcast<StandableComponent*>(
								components.at(
										Level::CompKey(soC.standsOn,
												"Standable"))) :
						sEmpty;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			pC.a.x = -pC.acceleration * sC.accelerationMultiplier;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			pC.a.x = pC.acceleration * sC.accelerationMultiplier;
		}
		else
		{
			if (soC.standing)
			{
				double sign;
				if (pC.v.x > 0)
					sign = -1;
				else if (pC.v.x < 0)
					sign = 1;
				else
					sign = 0; //direction of decceleration
				pC.a.x = sign * pC.stoppingSpeed * sC.stoppingMultiplier;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
				&& soC.jumpingTimeLeft > 0)
		{
			pC.a.x = 0;
			pC.v.y = -soC.baseJumpingPower * sC.jumpingAccelerationMultiplier;
			soC.jumpingTimeLeft -= deltaTime.asSeconds();
		}
		else
		{
			soC.jumpingTimeLeft = 0;
		}

	}
	std::cerr << "Player input system: "
			<< timer.getElapsedTime().asMilliseconds() << "\n";
}
