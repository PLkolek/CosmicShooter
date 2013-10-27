/* 
 * File:   RenderSystem.hpp
 * Author: marzena
 *
 * Created on 17 luty 2013, 23:29
 */

#ifndef RENDERSYSTEM_HPP
#define	RENDERSYSTEM_HPP

#include "Components/SpriteComponent.hpp"
#include "Components/PositionComponent.hpp"
#include "Systems/System.hpp"

#include <unordered_map>

class RenderSystem: public System
{
public:
	RenderSystem(sf::RenderWindow& window, Level::CompMap& components);
	RenderSystem(const RenderSystem& orig);
	virtual ~RenderSystem();
	void update(sf::Time deltaTime);
	void addEntity(int EID);
	static const int numLayers = 5;
private:
	sf::RenderWindow& window;
};

#endif	/* RENDERSYSTEM_HPP */

