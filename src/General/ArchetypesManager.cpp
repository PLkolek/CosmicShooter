/* 
 * File:   ArchetypesManager.cpp
 * Author: kolzi
 * 
 * Created on 19 kwiecień 2013, 17:35
 */

#include "General/Archetype.h"
#include "General/ArchetypesManager.h"
#include "rapidxml/rapidxml.hpp"
#include "Components/Component.hpp"
#include "Exceptions/RequiredAttributeNotFound.hpp"

#include <vector>
#include <iostream>

ArchetypesManager::ArchetypesManager() throw (RequiredAttributeNotFound)
{
}

ArchetypesManager::ArchetypesManager(const ArchetypesManager& orig)
{
}

ArchetypesManager::~ArchetypesManager()
{
}

void ArchetypesManager::read(std::istream& str)
{
	rapidxml::xml_document<> doc;

	std::vector<char> buffer((std::istreambuf_iterator<char>(str)), std::istreambuf_iterator<char>());
	buffer.push_back('\0');
	doc.parse<0>(&buffer[0]);
	for (rapidxml::xml_node<> * archetypeNode = doc.first_node("Archetype"); archetypeNode; archetypeNode =
			archetypeNode->next_sibling("Archetype"))
	{
		std::cerr<<"Reading archetype: "<<archetypeNode->first_attribute("name")->value()<<"\n";
		archetypes[archetypeNode->first_attribute("name")->value()] = new Archetype(archetypeNode);
	}
}

void ArchetypesManager::addEntity(int EID, std::string archName, Level::CompMap& components,
		Level::SysMap& systems) const
{
	std::cerr << "\nAdding: " << archName << "\n";
	Archetype* archetype = archetypes.at(archName);
	for (auto comp : archetype->components)
	{
//		std::cerr<<"ArchMan adding component: "<<EID<<" "<< comp.first<<"||\n";
		components[Level::CompKey(EID, comp.first)] = comp.second->clone(EID);
	}
	for (auto sys : archetype->systems)
	{
//		std::cerr<<"ArchMan adding system: "<<sys<<"||\n";
		systems.at(sys)->addEntity(EID);
	}
//	std::cerr<<"ArchMan end\n";
}
