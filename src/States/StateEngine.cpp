/* 
 * File:   StateEngine.cpp
 * Author: mk
 * 
 * Created on 9 czerwiec 2013, 18:04
 */

#include "States/StateEngine.hpp"

#include <fstream>
#include <queue>
#include <iostream>

StateEngine::StateEngine()
{
	std::ifstream file("resources/archetypes.xml");
	archMan.read(file);
}

StateEngine::StateEngine(const StateEngine& orig)
{
}

StateEngine::~StateEngine()
{
}

const ArchetypesManager& StateEngine::getArchMan() const
{
	return archMan;
}

void StateEngine::update()
{
	std::cerr << "Update\n";
	toPop = 0;
	std::cerr << "Update\n";
	states.top()->update();
	std::cerr << "Updated\n";
	for (int i = 0; i < toPop; i++)
		states.pop();
	while (!toPush.empty())
	{
		states.push(std::move(toPush.back()));
		toPush.pop();
	}

}

void StateEngine::changeState(std::unique_ptr<State> state)
{
	toPop++;
	toPush.push(std::move(state));
}

void StateEngine::pushState(std::unique_ptr<State> state)
{
	states.push(std::move(state));
}
