/* 
 * File:   Component.hpp
 * Author: marzena
 *
 * Created on 18 luty 2013, 19:49
 */

#ifndef COMPONENT_HPP
#define	COMPONENT_HPP

#include "rapidxml/rapidxml.hpp"
#include <list>
#include <Systems/System.hpp>

class Component
{
public:
	Component(int EID);
	Component(const Component& orig);
	virtual ~Component();
	virtual Component* clone(int newEID)=0;
	virtual void read(rapidxml::xml_node<>* componentNode)=0;
	int EID;
private:

};

#endif	/* COMPONENT_HPP */

