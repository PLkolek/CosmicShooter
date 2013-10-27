/* 
 * File:   GameState.hpp
 * Author: mk
 *
 * Created on 5 czerwiec 2013, 19:45
 */

#ifndef GAMESTATE_HPP
#define	GAMESTATE_HPP
#include "State.hpp"
#include <SFML/Graphics.hpp>
#include "General/ArchetypesManager.h"
#include <string>
#include "General/Level.hpp"

class GameState: public State
{
public:
	GameState(sf::RenderWindow& app, const ArchetypesManager& archMan,
			std::string gameFile);
	void update();
	void Pause();
	void Resume();
private:
	Level level;
	sf::Clock clock;

};

#endif	/* GAMESTATE_HPP */

