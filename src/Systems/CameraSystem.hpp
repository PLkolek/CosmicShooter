/* 
 * File:   CameraSystem.hpp
 * Author: marzena
 *
 * Created on 18 luty 2013, 23:24
 */

#ifndef CAMERASYSTEM_HPP
#define	CAMERASYSTEM_HPP

#include "System.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/CameraSourceComponent.hpp"
#include "Components/ViewportComponent.hpp"

#include <SFML/Graphics.hpp>
#include <unordered_map>
class CameraSystem: public System
{
public:
	CameraSystem(sf::RenderWindow& window, Level::CompMap& components);
	CameraSystem(const CameraSystem& orig);
	virtual ~CameraSystem();
	void update(sf::Time deltaTime);
	void addEntity(int EID);
private:
	sf::RenderWindow& window;
	sf::View view;
};

#endif	/* CAMERASYSTEM_HPP */

