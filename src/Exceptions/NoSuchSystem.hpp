/* 
 * File:   NoSuchSystem.hpp
 * Author: kolzi
 *
 * Created on 4 czerwiec 2013, 17:18
 */

#ifndef NOSUCHSYSTEM_HPP
#define	NOSUCHSYSTEM_HPP

#include <stdexcept>

class NoSuchSystem: public std::runtime_error
{
	std::string name;
	std::string compName;
public:

	NoSuchSystem(std::string name) :
			std::runtime_error("No such system: " + name)
	{
	}
};

#endif	/* NOSUCHSYSTEM_HPP */

