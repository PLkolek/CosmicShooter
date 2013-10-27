/* 
 * File:   RemoveOnContactSystem.hpp
 * Author: kolzi
 *
 * Created on 8 czerwiec 2013, 19:20
 */

#ifndef REMOVEONCONTACTSYSTEM_HPP
#define	REMOVEONCONTACTSYSTEM_HPP

#include "System.hpp"

class RemoveOnContactSystem: public System
{
public:
	RemoveOnContactSystem(Level::CompMap& components, Level& level);
	RemoveOnContactSystem(const RemoveOnContactSystem& orig);
	virtual ~RemoveOnContactSystem();
	void addEntity(int EID);
	void update(sf::Time deltaTime);
private:
	Level& level;
};

#endif	/* REMOVEONCONTACTSYSTEM_HPP */

