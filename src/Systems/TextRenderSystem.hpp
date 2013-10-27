/* 
 * File:   TextRenderSystem.hpp
 * Author: kolzi
 *
 * Created on 31 maj 2013, 16:36
 */

#ifndef TEXTRENDERSYSTEM_HPP
#define	TEXTRENDERSYSTEM_HPP

#include "System.hpp"

class TextRenderSystem: public System
{
public:
	TextRenderSystem(sf::RenderWindow& window, Level::CompMap& components);
	TextRenderSystem(const TextRenderSystem& orig);
	virtual ~TextRenderSystem();
	void update(sf::Time deltaTime);
	void addEntity(int EID);
private:
	sf::RenderWindow& window;
};

#endif	/* TEXTRENDERSYSTEM_HPP */

