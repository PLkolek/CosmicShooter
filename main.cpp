/*
 * File:   main.cpp
 * Author: marzena
 *
 * Created on 17 luty 2013, 22:43
 */

#include <unordered_map>
#include "Components/SpriteComponent.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/ViewportComponent.hpp"
#include "Components/CameraSourceComponent.hpp"
#include "Systems/RenderSystem.hpp"
#include "Systems/PlayerInputSystem.hpp"
#include "Systems/CameraSystem.hpp"
#include "Systems/MovementSystem.hpp"
#include "Components/BoundingBoxComponent.hpp"
#include "Systems/CollisionSystem.hpp"
#include "General/ArchetypesManager.h"
#include "Exceptions/NoSuchComponentName.hpp"
#include "Exceptions/RequiredAttributeNotFound.hpp"
#include <iostream>
#include <fstream>
#include "States/MenuState.hpp"
#include "States/StateEngine.hpp"
#include <memory>

int main(int argc, char** argv)
{
	try
	{
		sf::RenderWindow app(sf::VideoMode(800, 600, 32), "SFML Graphics");

		StateEngine se;
		se.pushState(std::unique_ptr<State>(new MenuState(se, app)));

		std::cerr << "Loop\n";
		sf::Clock timer;
		while (app.isOpen())
		{
			//std::cerr<<"nasmnmasdn\n";
			app.clear(sf::Color(128, 128, 255));
			se.update();
			app.display();
			//	std::cerr<<"Main: "<<timer.restart().asMilliseconds()<<"\n";
		}

		return EXIT_SUCCESS;
	} catch (const std::exception& e)
	{
		std::cerr << "CATCH\n";
		std::cerr << e.what() << "\n";
	}
}

