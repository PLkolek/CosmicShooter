/* 
 * File:   Level.hpp
 * Author: kolzi
 *
 * Created on 24 kwiecień 2013, 22:13
 */

#ifndef LEVEL_HPP
#define	LEVEL_HPP

#include <unordered_map>
#include <list>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

#include "TechnicalShit/PairIntStringHash.hpp"
#include "SimpleIDGenerator.hpp"

class Component;
class System;
class ArchetypesManager;

class Level
{
public:
	typedef std::pair<int, std::string> CompKey;
	typedef std::unordered_map<CompKey, Component*, PairIntStringHash> CompMap;
	typedef std::unordered_map<std::string, System*> SysMap;

	Level(sf::RenderWindow& app, const ArchetypesManager& archetypesManager);
	Level(const Level& orig);
	virtual ~Level();

	int getNextID();

	void addComponent(int EID, std::string compName, Component* comp);
	void removeComponent(int EID, std::string compName);
	void addEntityToSystem(int EID, std::string system);
	void removeEntityFromSystem(int EID, std::string system);
	void removeEntity(int EID);

	bool systemExists(std::string name);

	void read(std::istream& str);
	void update(sf::Time deltaTime);

	//returns new entity ID
	int addArchetype(std::string archetype);

private:
	sf::RenderWindow& app;
	const ArchetypesManager& archetypesManager;
	std::unique_ptr<IDGenerator> idGenerator;
	std::list<System*> systems;
	std::unordered_map<std::string, System*> systemsMap;
	CompMap components;

	std::list<CompKey> componentToRemove;
	std::list<std::pair<int, std::string> > entitiesToRemoveFromSystems;
	std::list<int> entitiesToRemove;

};

#endif	/* LEVEL_HPP */

