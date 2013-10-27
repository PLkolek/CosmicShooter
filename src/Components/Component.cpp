/* 
 * File:   Component.cpp
 * Author: marzena
 * 
 * Created on 18 luty 2013, 19:49
 */

#include "Component.hpp"

Component::Component(int EID) :
		EID(EID)
{
}

Component::Component(const Component& orig) :
		EID(orig.EID)
{
}

Component::~Component()
{
}

