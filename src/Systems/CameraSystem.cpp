/* 
 * File:   CameraSystem.cpp
 * Author: marzena
 * 
 * Created on 18 luty 2013, 23:24
 */

#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "CameraSystem.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/CameraSourceComponent.hpp"
#include <assert.h>
#include <iostream>
#include <boost/cast.hpp>

CameraSystem::CameraSystem(sf::RenderWindow& window, Level::CompMap& components) :
		System(components), window(window)
{
}

CameraSystem::CameraSystem(const CameraSystem& orig) :
		System(orig), window(orig.window)
{
}

CameraSystem::~CameraSystem()
{
}

void CameraSystem::update(sf::Time deltaTime)
{
	sf::Clock timer;
	for (auto it = entities.begin(); it != entities.end(); it++)
	{
		PositionComponent* pC = boost::polymorphic_downcast<PositionComponent*>(
				components.at(Level::CompKey(*it, "Position")));
		CameraSourceComponent* csC = boost::polymorphic_downcast<
				CameraSourceComponent*>(
				components.at(Level::CompKey(*it, "CameraSource")));
		ViewportComponent* vC = boost::polymorphic_downcast<ViewportComponent*>(
				components.at(Level::CompKey(*it, "Viewport")));
		view.setCenter(pC->x + csC->offsetX, pC->y + csC->offsetY);
		view.setSize(csC->sourceWidth, csC->sourceHeight);
		window.setView(view);
	}
	std::cerr << "Camera system: " << timer.getElapsedTime().asMilliseconds()
			<< "\n";
}

void CameraSystem::addEntity(int EID)
{
	assert(
			components.find(Level::CompKey(EID, "Position")) != components.end()
					&& components.find(Level::CompKey(EID, "CameraSource"))
							!= components.end()
					&& components.find(Level::CompKey(EID, "Viewport"))
							!= components.end());
	entities.insert(EID);
}
