/* 
 * File:   NoSuchComponentName.hpp
 * Author: kolzi
 *
 * Created on 19 kwiecień 2013, 20:37
 */

#ifndef NOSUCHCOMPONENTNAME_HPP
#define	NOSUCHCOMPONENTNAME_HPP

#include <stdexcept>

class NoSuchComponentName: public std::runtime_error
{
	std::string name;
public:
	NoSuchComponentName(std::string name) :
			std::runtime_error("No such component name: " + name), name(name)
	{
	}
};

#endif	/* NOSUCHCOMPONENTNAME_HPP */

