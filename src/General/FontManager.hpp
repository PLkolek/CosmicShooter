/* 
 * File:   FontManager.hpp
 * Author: kolzi
 *
 * Created on 31 maj 2013, 14:15
 */

#ifndef FONTMANAGER_HPP
#define	FONTMANAGER_HPP

#include <SFML/Graphics/Font.hpp>
#include <unordered_map>
#include <memory>

class FontManager
{
public:
	static const sf::Font& getFont(std::string filename);
	static void releaseFont(std::string filename);
private:
	static std::unordered_map<std::string, std::unique_ptr<sf::Font>> fonts;
	static const std::string fontDirectory;

};

#endif	/* FONTMANAGER_HPP */

