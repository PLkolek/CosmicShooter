/* 
 * File:   IncorrentFrameWidth.hpp
 * Author: kolzi
 *
 * Created on 1 czerwiec 2013, 17:26
 */

#ifndef INCORRENTFRAMEWIDTH_HPP
#define	INCORRENTFRAMEWIDTH_HPP

#include <stdexcept>
class IncorrectFrameWidth: public std::runtime_error
{
	std::string filename;
	std::string compName;
public:
	IncorrectFrameWidth(std::string filename, std::string compName) :
			std::runtime_error(
					"Required attribute " + filename + " of component "
							+ compName + " not found!"), filename(filename), compName(
					compName)
	{
	}
};

#endif	/* INCORRENTFRAMEWIDTH_HPP */

