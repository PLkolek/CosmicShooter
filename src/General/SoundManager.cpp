/* 
 * File:   SoundManager.cpp
 * Author: marzena
 * 
 * Created on 13 maj 2013, 13:54
 */

#include "General/SoundManager.h"
#include "Exceptions/FileNotFound.hpp"

std::unordered_map<std::string, sf::SoundBuffer> SoundManager::buffers;
const std::string SoundManager::soundDirectory = "resources/";

sf::Sound SoundManager::getSound(std::string filename)
{
	sf::SoundBuffer buffer;
	if (buffers.find(filename) == buffers.end())
	{
		if (!buffer.loadFromFile(soundDirectory + filename))
		{
			throw FileNotFound(filename);
		}
		buffers.insert(std::make_pair(filename, buffer));

	}
	sf::Sound sound;
	sound.setBuffer(buffers.at(filename));
	return sound;

}

