/* 
 * File:   DataToTextSystem.cpp
 * Author: kolzi
 * 
 * Created on 31 maj 2013, 16:16
 */

#include <assert.h>
#include <boost/lexical_cast.hpp>
#include <boost/cast.hpp>

#include "DataToTextSystem.hpp"
#include "Components/TextComponent.hpp"
#include "Components/ScoreComponent.hpp"
#include "Components/CountdownComponent.hpp"

DataToTextSystem::DataToTextSystem(Level::CompMap& components) :
		System(components)
{
}

DataToTextSystem::DataToTextSystem(const DataToTextSystem& orig) :
		System(orig)
{
}

DataToTextSystem::~DataToTextSystem()
{
}

void DataToTextSystem::update(sf::Time deltaTime)
{
	sf::Clock timer;
	for (int EID : entities)
	{
		TextComponent& tC = *boost::polymorphic_downcast<TextComponent*>(
				components.at(Level::CompKey(EID, "Text")));
		if (components.find(Level::CompKey(EID, "Score")) != components.end())
		{
			ScoreComponent& sC = *boost::polymorphic_downcast<ScoreComponent*>(
					components.at(Level::CompKey(EID, "Score")));
			if (sC.toText)
				tC.text.setString(
						boost::lexical_cast<std::string>((int) sC.score));
		}
		if (components.find(Level::CompKey(EID, "Countdown"))
				!= components.end())
		{
			CountdownComponent& cC = *boost::polymorphic_downcast<
					CountdownComponent*>(
					components.at(Level::CompKey(EID, "Countdown")));
			if (cC.toText)
				tC.text.setString(
						boost::lexical_cast<std::string>((int) cC.timeLeft));
		}
	}
	std::cerr << "DataToText system: "
			<< timer.getElapsedTime().asMilliseconds() << "\n";
}

void DataToTextSystem::addEntity(int EID)
{
	assert(
			(components.find(Level::CompKey(EID, "Score")) != components.end()
					|| components.find(Level::CompKey(EID, "Countdown"))
							!= components.end())
					&& components.find(Level::CompKey(EID, "Text"))
							!= components.end());
	entities.insert(EID);
}

