/* 
 * File:   Level.cpp
 * Author: kolzi
 * 
 * Created on 24 kwiecień 2013, 22:13
 */

#include <vector>
#include <istream>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "rapidxml/rapidxml.hpp"

#include "Components/Component.hpp"
#include "General/ArchetypesManager.h"
#include "General/Level.hpp"
#include "Systems/RenderSystem.hpp"
#include "Systems/CameraSystem.hpp"
#include "Systems/CollisionSystem.hpp"
#include "Systems/MovementSystem.hpp"
#include "Systems/PlayerInputSystem.hpp"
#include "Systems/MusicSystem.hpp"
#include "Systems/DataToTextSystem.hpp"
#include "Systems/TextRenderSystem.hpp"
#include "Systems/ParticleSystem.hpp"
#include "Systems/CountdownSystem.hpp"
#include "Systems/StandsOnSystem.hpp"
#include "Systems/ScoreSystem.hpp"
#include "Systems/RemoveOnContactSystem.hpp"
#include "Exceptions/NoSuchSystem.hpp"
#include "General/ComponentsEnum.hpp"

Level::Level(sf::RenderWindow& app, const ArchetypesManager& archetypesManager) :
		app(app), archetypesManager(archetypesManager), idGenerator(
				new SimpleIDGenerator())
{
	systemsMap.insert(
			std::pair<std::string, System*>("Music",
					new MusicSystem(components)));
	systems.push_back(systemsMap.at("Music"));

	systemsMap.insert(
			std::pair<std::string, System*>("Particle",
					new ParticleSystem(components, *this)));
	systems.push_back(systemsMap.at("Particle"));

	systemsMap.insert(
			std::pair<std::string, System*>("PlayerInput",
					new PlayerInputSystem(components, app)));
	systems.push_back(systemsMap.at("PlayerInput"));

	systemsMap.insert(
			std::pair<std::string, System*>("Movement",
					new MovementSystem(components)));
	systems.push_back(systemsMap.at("Movement"));

	systemsMap.insert(
			std::pair<std::string, System*>("Collision",
					new CollisionSystem(components)));
	systems.push_back(systemsMap.at("Collision"));

	systemsMap.insert(
			std::pair<std::string, System*>("Score",
					new ScoreSystem(components)));
	systems.push_back(systemsMap.at("Score"));

	systemsMap.insert(
			std::pair<std::string, System*>("StandsOn",
					new StandsOnSystem(components)));
	systems.push_back(systemsMap.at("StandsOn"));

	systemsMap.insert(
			std::pair<std::string, System*>("RemoveOnContact",
					new RemoveOnContactSystem(components, *this)));
	systems.push_back(systemsMap.at("RemoveOnContact"));

	systemsMap.insert(
			std::pair<std::string, System*>("DataToText",
					new DataToTextSystem(components)));
	systems.push_back(systemsMap.at("DataToText"));

	systemsMap.insert(
			std::pair<std::string, System*>("Countdown",
					new CountdownSystem(components, *this)));
	systems.push_back(systemsMap.at("Countdown"));

	systemsMap.insert(
			std::pair<std::string, System*>("Camera",
					new CameraSystem(app, components)));
	systems.push_back(systemsMap.at("Camera"));

	systemsMap.insert(
			std::pair<std::string, System*>("Render",
					new RenderSystem(app, components)));
	systems.push_back(systemsMap.at("Render"));

	systemsMap.insert(
			std::pair<std::string, System*>("TextRender",
					new TextRenderSystem(app, components)));
	systems.push_back(systemsMap.at("TextRender"));

}

Level::Level(const Level& orig) :
		app(app), archetypesManager(orig.archetypesManager), idGenerator(
				orig.idGenerator.get()), systems(orig.systems), systemsMap(
				orig.systemsMap), components(orig.components)
{
}

Level::~Level()
{
}

void Level::read(std::istream& str)
{
	rapidxml::xml_document<> doc;

	std::vector<char> buffer((std::istreambuf_iterator<char>(str)),
			std::istreambuf_iterator<char>());
	buffer.push_back('\0');
	doc.parse<0>(&buffer[0]);
	for (rapidxml::xml_node<> * objectNode = doc.first_node("Object");
			objectNode; objectNode = objectNode->next_sibling("Object"))
	{
		int EID = idGenerator->nextID();
		//	std::cerr<<"Level read, new entity: "<<EID<<" "<<objectNode->first_attribute("name")->value()<<"\n";
		archetypesManager.addEntity(EID,
				objectNode->first_attribute("name")->value(), components,
				systemsMap);
		//	std::cerr<<"Added entity\n";
		for (rapidxml::xml_node<> * componentNode = objectNode->first_node();
				componentNode; componentNode = componentNode->next_sibling())
		{
			//		std::cerr<<"Level reading: "<<componentNode->name()<<"|||\n";
			//		std::cerr<<(components.find(CompKey(EID,componentNode->name()))!=components.end())<<"\n";
			components[CompKey(EID, componentNode->name())]->read(
					componentNode);
			//		std::cerr<<"Finished reading\n";
		}
	}
}

void Level::update(sf::Time deltaTime)
{
	std::cerr << "Update\n";
	std::cerr << "Components left: " << components.size() << "\n";
	sf::Clock timer;
	for (auto system : systems)
	{
		system->update(deltaTime);
	}
	std::cerr << "Level updated: " << timer.restart().asMilliseconds() << "\n";
	for (auto comp : componentToRemove)
		components.erase(comp);
	componentToRemove.clear();

	std::cerr << "Components removed: " << timer.restart().asMilliseconds()
			<< "\n";

	for (auto enP : entitiesToRemoveFromSystems)
		systemsMap.at(enP.second)->removeEntity(enP.first);
	entitiesToRemoveFromSystems.clear();

	std::cerr << "Entities removed from systems: "
			<< timer.restart().asMilliseconds() << "\n";

	sf::Clock preciseTimer;
	long long int t1 = 0, t2 = 0;
	int counter = 0;
	for (int EID : entitiesToRemove)
	{
		for (const Enum<ComponentsEnum> component : ComponentsEnum::getValues())
		{
			counter++;
			components.erase(CompKey(EID, component.getName()));
		}
		t1 += preciseTimer.restart().asMicroseconds();

		for (auto system : systems)
		{
			system->removeEntity(EID);
		}
		t2 += preciseTimer.restart().asMicroseconds();

	}
	entitiesToRemove.clear();
	std::cerr << "Entity components removed in: " << t1 << " counter: "
			<< counter << "\n";
	std::cerr << "From systems removed in: " << t2 << "\n";
	std::cerr << "Entities removed: " << timer.restart().asMilliseconds()
			<< "\n";
}

void Level::addComponent(int EID, std::string compName, Component* comp)
{
	components.insert(
			std::pair<CompKey, Component*>(CompKey(EID, compName), comp));
}

void Level::removeComponent(int EID, std::string compName)
{
	componentToRemove.push_back(CompKey(EID, compName));
}

void Level::addEntityToSystem(int EID, std::string system)
{
	if (!systemExists(system))
		throw NoSuchSystem(system);
	systemsMap.at(system)->addEntity(EID);
}

void Level::removeEntityFromSystem(int EID, std::string system)
{
	if (!systemExists(system))
		throw NoSuchSystem(system);
	entitiesToRemoveFromSystems.push_back(std::make_pair(EID, system));
}

int Level::getNextID()
{
	return idGenerator->nextID();
}

int Level::addArchetype(std::string archetype)
{
	int id = idGenerator->nextID();
	archetypesManager.addEntity(id, archetype, components, systemsMap);
	return id;

}

void Level::removeEntity(int EID)
{
	entitiesToRemove.push_back(EID);
}

bool Level::systemExists(std::string name)
{
	return (systemsMap.find(name) != systemsMap.end());
}
