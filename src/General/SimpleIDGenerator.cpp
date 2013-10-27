/* 
 * File:   SimpleIDGenerator.cpp
 * Author: kolzi
 * 
 * Created on 25 kwiecień 2013, 15:43
 */

#include "General/SimpleIDGenerator.hpp"
#include "General/SimpleIDGenerator.hpp"

int SimpleIDGenerator::nextID()
{
	return ++lastID;
}

