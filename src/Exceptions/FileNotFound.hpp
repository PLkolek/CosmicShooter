/* 
 * File:   FileNotFoundException.hpp
 * Author: marzena
 *
 * Created on 9 maj 2013, 18:31
 */

#ifndef FILENOTFOUNDEXCEPTION_HPP
#define	FILENOTFOUNDEXCEPTION_HPP

#include <stdexcept>
#include <string>

class FileNotFound: public std::runtime_error
{
	std::string name;
public:
	FileNotFound(std::string name) :
			runtime_error("File not found: " + name)
	{
	}
};

#endif	/* FILENOTFOUNDEXCEPTION_HPP */

