/* 
 * File:   ScoreSystem.cpp
 * Author: kolzi
 * 
 * Created on 8 czerwiec 2013, 14:31
 */
#include <boost/cast.hpp>

#include "ScoreSystem.hpp"
#include "Components/BoundingBoxComponent.hpp"
#include "Components/HasScoreComponent.hpp"
#include "Components/ScoreComponent.hpp"
#include "Components/DamageComponent.hpp"

ScoreSystem::ScoreSystem(Level::CompMap& components) :
		System(components)
{
}

ScoreSystem::ScoreSystem(const ScoreSystem& orig) :
		System(orig)
{
}

ScoreSystem::~ScoreSystem()
{
}

void ScoreSystem::addEntity(int EID)
{
	assert(
			components.find(Level::CompKey(EID, "HasScore")) != components.end()
					&& components.find(Level::CompKey(EID, "BoundingBox"))
							!= components.end());
	entities.insert(EID);
}

void ScoreSystem::update(sf::Time deltaTime)
{
	sf::Clock timer;
	for (auto it = entities.begin(); it != entities.end(); it++)
	{
		BoundingBoxComponent& bbi = *boost::polymorphic_downcast<
				BoundingBoxComponent*>(
				components.at(Level::CompKey(*it, "BoundingBox")));
		for (BoundingBoxComponent::CollisionData collWith : bbi.collidedWith)
		{
			double currT = std::min(collWith.tx, collWith.tx);
			if (components.find(Level::CompKey(collWith.EID, "Damage"))
					!= components.end())
			{
				HasScoreComponent& hasScore = *boost::polymorphic_downcast<
						HasScoreComponent*>(
						components.at(Level::CompKey(*it, "HasScore")));
				DamageComponent& damage = *boost::polymorphic_downcast<
						DamageComponent*>(
						components.at(Level::CompKey(collWith.EID, "Damage")));
				ScoreComponent& score = *boost::polymorphic_downcast<
						ScoreComponent*>(
						components.at(
								Level::CompKey(hasScore.scoreEID, "Score")));

				if (damage.once && !damage.taken)
				{
					score.score -= damage.damagePerSecond;
					damage.taken = true;
				}
				else if (!damage.once)
					score.score -= damage.damagePerSecond * currT;
			}
		}
	}
	std::cerr << "Score system: " << timer.getElapsedTime().asMilliseconds()
			<< "\n";
}
