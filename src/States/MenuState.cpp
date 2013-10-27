/* 
 * File:   newClass.cpp
 * Author: mk
 * 
 * Created on 5 czerwiec 2013, 19:43
 */

#include <SFML/Window/Window.hpp>
#include "States/GameState.hpp"
#include "States/MenuState.hpp"
#include "General/FontManager.hpp"
#include "General/ImageManager.hpp"
#include <memory>
#include <iostream>

MenuState::MenuState(StateEngine& se, sf::RenderWindow& window) :
		window(window), se(se)
{
	selections[0].name = "New game";
	selections[0].defaultColor = sf::Color(0, 0, 0);
	selections[0].selectedColor = sf::Color(140, 140, 140);

	selections[1].name = "Quit game";
	selections[1].defaultColor = sf::Color(0, 0, 0);
	selections[1].selectedColor = sf::Color(140, 140, 140);

	active = 0;

	background = ImageManager::getSprite("background.png");
	background.setScale(1, 1.25);

}

void MenuState::update()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::KeyPressed)
		{
			std::cerr << "Key pressed\n";
			switch (event.key.code)
			{
			case sf::Keyboard::Down:
				if (active == numOptions - 1)
					active = 0;
				else
					active = active + 1;
				break;
			case sf::Keyboard::Up:
				if (active == 0)
					active = numOptions - 1;
				else
					active = active - 1;
				break;
			case sf::Keyboard::Return:
				if (active == 0)
					se.changeState(
							std::unique_ptr<State>(
									new GameState(window, se.getArchMan(),
											"testlevel.xml")));
				else
					window.close();
				break;
			default:
				break;
			}
		}
	}

	window.draw(background);

	sf::Text text;
	for (int i = 0; i < numOptions; i++)
	{
		text.setCharacterSize(50);
		text.setFont(FontManager::getFont("DejaVuSans.ttf"));
		text.setString(selections[i].name);
		if (i == active)
			text.setColor(selections[i].selectedColor);
		else
			text.setColor(selections[i].defaultColor);
		text.setPosition(200, 100 + i * 100);
		window.draw(text);
	}
}
void MenuState::Pause()
{

}

void MenuState::Resume()
{

}
