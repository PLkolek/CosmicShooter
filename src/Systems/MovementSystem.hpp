/* 
 * File:   PhysicsSystem.hpp
 * Author: marzena
 *
 * Created on 19 luty 2013, 22:44
 */

#ifndef PHYSICSSYSTEM_HPP
#define	PHYSICSSYSTEM_HPP

#include "Systems/System.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/PhysicsComponent.hpp"

#include <SFML/System/Time.hpp>
#include <unordered_map>

class MovementSystem: public System
{
public:
	MovementSystem(Level::CompMap& components);
	MovementSystem(const MovementSystem& orig);
	virtual ~MovementSystem();
	void update(sf::Time deltaTime);
	void addEntity(int entity);
};

#endif	/* PHYSICSSYSTEM_HPP */

