/* 
 * File:   RequiredAttributeNotFound.hpp
 * Author: kolzi
 *
 * Created on 19 kwiecień 2013, 20:33
 */

#ifndef REQUIREDATTRIBUTENOTFOUND_HPP
#define	REQUIREDATTRIBUTENOTFOUND_HPP

#include <stdexcept>
class RequiredAttributeNotFound: public std::runtime_error
{
public:
	std::string name;
	std::string compName;

	RequiredAttributeNotFound(std::string name1, std::string compName1) :
			std::runtime_error(
					"Required attribute " + name1 + " of component " + compName1
							+ " not found!"), name(name1), compName(compName1)
	{
	}
};

#endif	/* REQUIREDATTRIBUTENOTFOUND_HPP */

