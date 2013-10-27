/* 
 * File:   FileNotFoundException.hpp
 * Author: marzena
 *
 * Created on 9 maj 2013, 18:31
 */

#ifndef FILENOTFOUNDEXCEPTION_HPP
#define	FILENOTFOUNDEXCEPTION_HPP

#include <exception>
#include <string>

class FileNotFound: public std::exception
{
	std::string name;
public:
	const char* what()
	{
		return ("File not found: " + name).c_str();
	}
	FileNotFound(std::string name) :
			name(name)
	{
	}
};

#endif	/* FILENOTFOUNDEXCEPTION_HPP */

