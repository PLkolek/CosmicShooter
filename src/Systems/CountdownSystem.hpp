/* 
 * File:   CountdownSystem.hpp
 * Author: kolzi
 *
 * Created on 2 czerwiec 2013, 21:34
 */

#ifndef COUNTDOWNSYSTEM_HPP
#define	COUNTDOWNSYSTEM_HPP

#include "System.hpp"

class CountdownSystem: public System
{
public:
	CountdownSystem(Level::CompMap& components, Level& level);
	CountdownSystem(const CountdownSystem& orig);
	virtual ~CountdownSystem();
	void update(sf::Time deltaTime);
	void addEntity(int entity);

private:
	Level& level;
};

#endif	/* COUNTDOWNSYSTEM_HPP */

