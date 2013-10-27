/* 
 * File:   StandsOnSystem.hpp
 * Author: kolzi
 *
 * Created on 8 czerwiec 2013, 14:09
 */

#ifndef STANDSONSYSTEM_HPP
#define	STANDSONSYSTEM_HPP

#include "System.hpp"

class StandsOnSystem: public System
{
public:
	StandsOnSystem(Level::CompMap& components);
	StandsOnSystem(const StandsOnSystem& orig);
	virtual ~StandsOnSystem();
	void addEntity(int EID);
	void update(sf::Time deltaTime);
};

#endif	/* STANDSONSYSTEM_HPP */

