/* 
 * File:   FontManager.cpp
 * Author: kolzi
 * 
 * Created on 31 maj 2013, 14:15
 */

#include "Exceptions/FileNotFound.hpp"
#include "General/FontManager.hpp"
#include <iostream>

std::unordered_map<std::string, std::unique_ptr<sf::Font>> FontManager::fonts;
const std::string FontManager::fontDirectory = "resources/";

const sf::Font& FontManager::getFont(std::string filename)
{
	if (fonts.find(filename) == fonts.end())
	{
		std::unique_ptr<sf::Font> fontPtr(new sf::Font);

		if (!fontPtr->loadFromFile(fontDirectory + filename))
		{
			throw FileNotFound(filename);
		}
		fonts.insert(std::make_pair(filename, std::move(fontPtr)));

	}
	return *fonts.at(filename);
}
