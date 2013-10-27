/* 
 * File:   SoundManager.hpp
 * Author: marzena
 *
 * Created on 13 maj 2013, 13:54
 */

#ifndef SOUNDMANAGER_HPP
#define	SOUNDMANAGER_HPP
//#include <SFML/Audio.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>

class SoundManager
{
public:
	static sf::Sound getSound(std::string filename);
	static void releaseSound(std::string filename);
private:
	static std::unordered_map<std::string, sf::SoundBuffer> buffers;
	static const std::string soundDirectory;

};

#endif	/* SOUNDMANAGER_HPP */

