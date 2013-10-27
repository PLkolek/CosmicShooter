/* 
 * File:   RenderSystem.cpp
 * Author: marzena
 * 
 * Created on 17 luty 2013, 23:29
 */

#include "RenderSystem.hpp"
#include "Components/PositionRelativeToComponent.hpp"
#include <assert.h>
#include <boost/cast.hpp>

RenderSystem::RenderSystem(sf::RenderWindow& window, Level::CompMap& components) :
		System(components), window(window)
{

}

RenderSystem::RenderSystem(const RenderSystem& orig) :
		System(orig), window(orig.window)
{
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::update(sf::Time deltaTime)
{
	sf::Clock timer;
	std::list<int> onLayer[numLayers];
	for (auto it = entities.begin(); it != entities.end(); it++)
	{
		SpriteComponent* sC = boost::polymorphic_downcast<SpriteComponent*>(
				components.at(Level::CompKey(*it, "Sprite")));
		onLayer[sC->layer].push_back(*it);
	}
	for (int i = numLayers - 1; i >= 0; i--)
	{
		for (int EID : onLayer[i])
		{
			PositionComponent* pC = boost::polymorphic_downcast<
					PositionComponent*>(
					components.at(Level::CompKey(EID, "Position")));
			SpriteComponent* sC = boost::polymorphic_downcast<SpriteComponent*>(
					components.at(Level::CompKey(EID, "Sprite")));
			int x = pC->pos.x;
			int y = pC->pos.y;
			if (components.find(Level::CompKey(EID, "PositionRelativeTo"))
					!= components.end())
			{
				PositionRelativeToComponent& prtC =
						*boost::polymorphic_downcast<
								PositionRelativeToComponent*>(
								components.at(
										Level::CompKey(EID,
												"PositionRelativeTo")));
				PositionComponent& ppC = *boost::polymorphic_downcast<
						PositionComponent*>(
						components.at(
								Level::CompKey(prtC.relativeTo, "Position")));
				x += ppC.pos.x;
				y += ppC.pos.y;
			}
			int orX = sC->sprite.getLocalBounds().width / 2.0;
			int orY = sC->sprite.getLocalBounds().height / 2.0;
			sC->sprite.setOrigin(orX, orY);
			sC->sprite.setPosition(x + orX, y + orY);
			sC->sprite.setRotation(pC->angle);

			sC->currentFrameTime += deltaTime.asSeconds();
			int i = 0;
			while (sC->currentFrameTime
					> sC->loopTime / double(sC->numberOfFrames))
			{
				i++;
				sC->currentFrameTime -= sC->loopTime
						/ double(sC->numberOfFrames);
			}
			sf::IntRect textRect = sC->sprite.getTextureRect();
			textRect.left = (textRect.left + i * textRect.width)
					% int(sC->sprite.getTexture()->getSize().x);
			sC->sprite.setTextureRect(textRect);
			window.draw(sC->sprite);
		}
	}
	std::cerr << "Render system: " << timer.getElapsedTime().asMilliseconds()
			<< "\n";
}

void RenderSystem::addEntity(int EID)
{
	assert(
			components.find(Level::CompKey(EID, "Position")) != components.end()
					&& components.find(Level::CompKey(EID, "Sprite"))
							!= components.end());
	entities.insert(EID);
}
