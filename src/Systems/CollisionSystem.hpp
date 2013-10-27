/* 
 * File:   CollisionSystem.hpp
 * Author: marzena
 *
 * Created on 20 luty 2013, 00:06
 */

#ifndef COLLISIONSYSTEM_HPP
#define	COLLISIONSYSTEM_HPP

#include "Components/PositionComponent.hpp"
#include "Components/BoundingBoxComponent.hpp"
#include "Components/PhysicsComponent.hpp"
#include "Systems/System.hpp"
#include <unordered_map>

class CollisionSystem: public System
{
public:
	CollisionSystem(Level::CompMap& components);
	CollisionSystem(const CollisionSystem& orig);
	virtual ~CollisionSystem();
	void addEntity(int EID);
	void update(sf::Time deltaTime);
};

#endif	/* COLLISIONSYSTEM_HPP */

