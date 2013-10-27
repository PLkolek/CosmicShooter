/* 
 * File:   ParticleSystem.hpp
 * Author: kolzi
 *
 * Created on 2 czerwiec 2013, 17:15
 */

#ifndef PARTICLESYSTEM_HPP
#define	PARTICLESYSTEM_HPP

#include "System.hpp"

class ParticleSystem: public System
{
public:
	ParticleSystem(Level::CompMap& components, Level& level);
	ParticleSystem(const ParticleSystem& orig);
	virtual ~ParticleSystem();
	void update(sf::Time deltaTime);
	void addEntity(int entity);

private:
	Level& level;
};

#endif	/* PARTICLESYSTEM_HPP */

