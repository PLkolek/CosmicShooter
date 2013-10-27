/* 
 * File:   SimpleIDGenerator.hpp
 * Author: kolzi
 *
 * Created on 25 kwiecień 2013, 15:43
 */

#ifndef SIMPLEIDGENERATOR_HPP
#define	SIMPLEIDGENERATOR_HPP

#include "IDGenerator.hpp"

class SimpleIDGenerator: public IDGenerator
{
public:
	int nextID();
private:
	int lastID = 0;
};

#endif	/* SIMPLEIDGENERATOR_HPP */

