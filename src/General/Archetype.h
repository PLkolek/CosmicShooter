/* 
 * File:   Archetype.h
 * Author: kolzi
 *
 * Created on 19 kwiecień 2013, 16:56
 */

#ifndef ARCHETYPE_H
#define	ARCHETYPE_H

#include <string>
#include <list>

#include "rapidxml/rapidxml.hpp"

class Component;

class Archetype
{
public:
	Archetype(rapidxml::xml_node<>* archetypeNode);
	Archetype(const Archetype& orig);
	virtual ~Archetype();
	std::list<std::pair<std::string, Component*>> components;
	std::list<std::string> systems;
	void read(rapidxml::xml_node<>* archetypeNode);
};

#endif	/* ARCHETYPE_H */

