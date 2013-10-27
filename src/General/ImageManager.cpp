/* 
 * File:   ImageManager.cpp
 * Author: marzena
 * 
 * Created on 9 maj 2013, 17:02
 */

#include <SFML/Graphics/Texture.hpp>
#include "Exceptions/FileNotFound.hpp"
#include "General/ImageManager.hpp"

std::unordered_map<std::string, sf::Texture> ImageManager::textures;
const std::string ImageManager::imageDirectory = "resources/";

sf::Sprite ImageManager::getSprite(std::string filename)
{
	if (textures.find(filename) == textures.end())
	{
		sf::Texture texture;

		if (!texture.loadFromFile(imageDirectory + filename))
		{
			throw FileNotFound(filename);
		}
		textures.insert(std::make_pair(filename, texture));

	}
	sf::Sprite sprite;
	sprite.setTexture(textures.at(filename));
	return sprite;
}
