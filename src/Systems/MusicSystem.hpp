/* 
 * File:   MusicSystem.hpp
 * Author: mk
 *
 * Created on 25 maj 2013, 11:01
 */

#ifndef MUSICSYSTEM_HPP
#define	MUSICSYSTEM_HPP
#include "Systems/System.hpp"

class MusicSystem: public System
{
public:
	MusicSystem(Level::CompMap& components);
	MusicSystem(const MusicSystem& orig);
	virtual ~MusicSystem();
	void update(sf::Time deltaTime);
	void addEntity(int entity);
};

#endif	/* MUSICSYSTEM_HPP */

