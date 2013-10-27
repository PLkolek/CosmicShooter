/* 
 * File:   System.hpp
 * Author: marzena
 *
 * Created on 18 luty 2013, 19:51
 */

#ifndef SYSTEM_HPP
#define	SYSTEM_HPP

#include <list>
#include <unordered_set>

#include "General/Level.hpp"

class System
{
public:
	System(Level::CompMap& components);
	System(const System& orig);
	virtual ~System();
	void removeEntity(int EID);
	virtual void addEntity(int EID)=0;
	virtual void update(sf::Time deltaTime)=0;
protected:
	Level::CompMap& components;
	std::unordered_set<int> entities;

};

#endif	/* SYSTEM_HPP */

