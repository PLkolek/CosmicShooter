/* 
 * File:   GameState.cpp
 * Author: mk
 * 
 * Created on 5 czerwiec 2013, 19:45
 */

#include <SFML/Graphics/RenderStates.hpp>

#include "States/GameState.hpp"
#include <iostream>
#include <fstream>

GameState::GameState(sf::RenderWindow& app, const ArchetypesManager& archMan,
		std::string gameFile) :
		level(app, archMan)
{
	std::ifstream levelFile("resources/" + gameFile);
	level.read(levelFile);
	std::cerr << "Level read\n";
	clock.restart();

}
void GameState::update()
{
	level.update(clock.restart());
}

void GameState::Pause()
{
}

void GameState::Resume()
{
}
