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

PlayerInputSystem::PlayerInputSystem(Level::CompMap& components, sf::RenderWindow& app) :
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
		PhysicsComponent& pC = *boost::polymorphic_downcast<PhysicsComponent*>(components.at(Level::CompKey(eid, "Physics")));

		Vector thrust;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			thrust.x = -1;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			thrust.x = 1;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			thrust.y = -1;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			thrust.y = 1;

		if(thrust!=Vector())
			thrust.scaleToLength(50000);
		pC.f += thrust;
	}
	std::cerr << "Player input system: " << timer.getElapsedTime().asMilliseconds() << "\n";
}
