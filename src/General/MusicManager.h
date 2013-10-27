/* 
 * File:   MusicManager.hpp
 * Author: marzena
 *
 * Created on 24 maj 2013, 13:01
 */

#ifndef MUSICMANAGER_HPP
#define	MUSICMANAGER_HPP
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>

class MusicManager
{
public:
	static sf::Music* getMusic(std::string filename);
	static void releaseMusic(std::string filename);
private:
	static std::unordered_map<std::string, sf::Music*> musics;
	static const std::string musicDirectory;
};

#endif	/* MUSICMANAGER_HPP */

