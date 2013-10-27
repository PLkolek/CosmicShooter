/* 
 * File:   ImageManager.hpp
 * Author: marzena
 *
 * Created on 10 maj 2013, 17:48
 */

#ifndef IMAGEMANAGER_HPP
#define	IMAGEMANAGER_HPP

#include <unordered_map>
#include <SFML/Graphics.hpp>

class ImageManager
{
public:
	static sf::Sprite getSprite(std::string filename);
	static void releaseSprite(std::string filename);
private:
	static std::unordered_map<std::string, sf::Texture> textures;
	static const std::string imageDirectory;

};

#endif	/* IMAGEMANAGER_HPP */

