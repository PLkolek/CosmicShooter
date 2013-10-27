/* 
 * File:   TextTextRenderSystem.cpp
 * Author: kolzi
 * 
 * Created on 31 maj 2013, 16:36
 */

#include "TextRenderSystem.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/TextComponent.hpp"
#include <assert.h>
#include <boost/cast.hpp>

TextRenderSystem::TextRenderSystem(sf::RenderWindow& window,
		Level::CompMap& components) :
		System(components), window(window)
{

}

TextRenderSystem::TextRenderSystem(const TextRenderSystem& orig) :
		System(orig), window(orig.window)
{
}

TextRenderSystem::~TextRenderSystem()
{
}

void TextRenderSystem::update(sf::Time deltaTime)
{
	sf::Clock timer;
	for (auto it = entities.begin(); it != entities.end(); it++)
	{
		PositionComponent* pC = boost::polymorphic_downcast<PositionComponent*>(
				components.at(Level::CompKey(*it, "Position")));
		TextComponent* tC = boost::polymorphic_downcast<TextComponent*>(
				components.at(Level::CompKey(*it, "Text")));

		sf::View view = window.getView();
		window.setView(sf::View());
		tC->text.setPosition(pC->pos);
		window.draw(tC->text);
		window.setView(view);
	}
	std::cerr << "Text render system: "
			<< timer.getElapsedTime().asMilliseconds() << "\n";
}

void TextRenderSystem::addEntity(int EID)
{
	assert(
			components.find(Level::CompKey(EID, "Position")) != components.end()
					&& components.find(Level::CompKey(EID, "Text"))
							!= components.end());
	entities.insert(EID);
}

