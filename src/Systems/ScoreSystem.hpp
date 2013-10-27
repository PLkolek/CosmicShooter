/* 
 * File:   ScoreSystem.hpp
 * Author: kolzi
 *
 * Created on 8 czerwiec 2013, 14:31
 */

#ifndef SCORESYSTEM_HPP
#define	SCORESYSTEM_HPP

#include "System.hpp"

class ScoreSystem: public System
{
public:
	ScoreSystem(Level::CompMap& components);
	ScoreSystem(const ScoreSystem& orig);
	virtual ~ScoreSystem();
	void addEntity(int EID);
	void update(sf::Time deltaTime);
};

#endif	/* SCORESYSTEM_HPP */

