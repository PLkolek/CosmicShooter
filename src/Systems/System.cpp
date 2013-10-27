/* 
 * File:   System.cpp
 * Author: marzena
 * 
 * Created on 18 luty 2013, 19:51
 */

#include <list>

#include "System.hpp"

System::System(Level::CompMap& components) :
		components(components)
{
}

System::System(const System& orig) :
		components(orig.components), entities(orig.entities)
{
}

System::~System()
{
}

void System::removeEntity(int EID)
{
	entities.erase(EID);
}
