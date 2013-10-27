/* 
 * File:   PlayerInputSystem.hpp
 * Author: marzena
 *
 * Created on 18 luty 2013, 21:19
 */

#ifndef PLAYERINPUTSYSTEM_HPP
#define	PLAYERINPUTSYSTEM_HPP

#include "Systems/System.hpp"
#include "SFML/System.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/PhysicsComponent.hpp"

#include <unordered_map>

class PlayerInputSystem: public System
{
public:
	PlayerInputSystem(Level::CompMap& components, sf::RenderWindow& app);
	PlayerInputSystem(const PlayerInputSystem& orig);
	virtual ~PlayerInputSystem();
	void update(sf::Time deltaTime);
	void addEntity(int entity);
	sf::RenderWindow& app;
};

#endif	/* PLAYERINPUTSYSTEM_HPP */

