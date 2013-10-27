/* 
 * File:   DataToTextSystem.hpp
 * Author: kolzi
 *
 * Created on 31 maj 2013, 16:16
 */

#ifndef DATATOTEXTSYSTEM_HPP
#define	DATATOTEXTSYSTEM_HPP

#include <unordered_map>

#include "Systems/System.hpp"
#include "Components/PhysicsComponent.hpp"

class DataToTextSystem: public System
{
public:
	DataToTextSystem(Level::CompMap& components);
	DataToTextSystem(const DataToTextSystem& orig);
	virtual ~DataToTextSystem();
	void update(sf::Time deltaTime);
	void addEntity(int EID);
};

#endif	/* DATATOTEXTSYSTEM_HPP */

