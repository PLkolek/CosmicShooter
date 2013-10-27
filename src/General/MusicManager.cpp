/* 
 * File:   MusicManager.cpp
 * Author: marzena
 * 
 * Created on 24 maj 2013, 13:01
 */

#include "General/MusicManager.h"
#include "Exceptions/FileNotFound.hpp"

std::unordered_map<std::string, sf::Music*> MusicManager::musics;
const std::string MusicManager::musicDirectory = "resources/";

sf::Music* MusicManager::getMusic(std::string filename)
{
	sf::Music* music;
	if (musics.find(filename) == musics.end())
	{
		music = new sf::Music;
		if (!music->openFromFile(musicDirectory + filename))
		{
			throw FileNotFound(filename);
		}
		musics.insert(std::make_pair(filename, music));
	}
	return musics.at(filename);
}
