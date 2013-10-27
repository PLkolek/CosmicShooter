/*
 * ComponentsEnum.cpp
 *
 *  Created on: 24 paź 2013
 *      Author: kolzi
 */

#include "General/ComponentsEnum.hpp"

#include <boost/algorithm/string/case_conv.hpp>
//#include <boost/algorithm/string.hpp>
#include <utility>

#include "Components/BoundingBoxComponent.hpp"
#include "Components/CameraSourceComponent.hpp"
#include "Components/CountdownComponent.hpp"
#include "Components/DamageComponent.hpp"
#include "Components/HasScoreComponent.hpp"
#include "Components/MusicComponent.hpp"
#include "Components/ParticleComponent.hpp"
#include "Components/PhysicsComponent.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/PositionRelativeToComponent.hpp"
#include "Components/RemoveComponent.hpp"
#include "Components/ScoreComponent.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/StandableComponent.hpp"
#include "Components/StandsOnComponent.hpp"
#include "Components/TextComponent.hpp"
#include "Components/ViewportComponent.hpp"
#include "Exceptions/NoSuchComponentName.hpp"

int ComponentsEnum::nextId = 0;
ComponentsEnum::NameEnumMap ComponentsEnum::nameToEnum;
ComponentsEnum::EnumsVector ComponentsEnum::enums = ComponentsEnum::initEnums();

ComponentsEnum::ConstEnumsVector ComponentsEnum::getValues()
{
	return enums;
}

std::string ComponentsEnum::getName()
{
	return name;
}

ComponentsEnum::EnumsVector ComponentsEnum::initEnums()
{
	ComponentsEnum::EnumsVector result;
	result.emplace_back(std::unique_ptr<ComponentsEnum>(new ComponentsEnum::BoundingBox()));
	result.emplace_back(std::unique_ptr<ComponentsEnum>(new ComponentsEnum::CameraSource()));
	result.emplace_back(std::unique_ptr<ComponentsEnum>(new ComponentsEnum::Countdown()));
	result.emplace_back(std::unique_ptr<ComponentsEnum>(new ComponentsEnum::Damage()));
	result.emplace_back(std::unique_ptr<ComponentsEnum>(new ComponentsEnum::HasScore()));
	result.emplace_back(std::unique_ptr<ComponentsEnum>(new ComponentsEnum::Music()));
	result.emplace_back(std::unique_ptr<ComponentsEnum>(new ComponentsEnum::Particle()));
	result.emplace_back(std::unique_ptr<ComponentsEnum>(new ComponentsEnum::Physics()));
	result.emplace_back(std::unique_ptr<ComponentsEnum>(new ComponentsEnum::Position()));
	result.emplace_back(std::unique_ptr<ComponentsEnum>(new ComponentsEnum::PositionRelativeTo()));
	result.emplace_back(std::unique_ptr<ComponentsEnum>(new ComponentsEnum::Remove()));
	result.emplace_back(std::unique_ptr<ComponentsEnum>(new ComponentsEnum::Score()));
	result.emplace_back(std::unique_ptr<ComponentsEnum>(new ComponentsEnum::Sprite()));
	result.emplace_back(std::unique_ptr<ComponentsEnum>(new ComponentsEnum::Standable()));
	result.emplace_back(std::unique_ptr<ComponentsEnum>(new ComponentsEnum::StandsOn()));
	result.emplace_back(std::unique_ptr<ComponentsEnum>(new ComponentsEnum::Text()));
	result.emplace_back(std::unique_ptr<ComponentsEnum>(new ComponentsEnum::Viewport()));
	return result;
}

ComponentsEnum::~ComponentsEnum()
{
	// TODO Auto-generated destructor stub
}

ComponentsEnum& ComponentsEnum::getByName(std::string name)
{
	NameEnumMap::iterator it = nameToEnum.find(boost::to_upper_copy(name));
	if (it != nameToEnum.end())
		return nameToEnum.at(boost::to_upper_copy(name));
	throw NoSuchComponentName(name);
}

//transforms name to uppercase and stores in map
ComponentsEnum::ComponentsEnum(std::string name)
{
	nameToEnum.insert(
			std::pair<std::string, ComponentsEnum&>(boost::to_upper_copy(name),
					*this));
	id = nextId++;
}

Component* ComponentsEnum::BoundingBox::createComponent(
		rapidxml::xml_node<>* archetypeNode)
{
	return new BoundingBoxComponent(archetypeNode);
}

ComponentsEnum::BoundingBox::BoundingBox() :
		ComponentsEnum("BoundingBox")
{
}

Component* ComponentsEnum::CameraSource::createComponent(
		rapidxml::xml_node<>* archetypeNode)
{
	return new CameraSourceComponent(archetypeNode);
}

ComponentsEnum::CameraSource::CameraSource() :
		ComponentsEnum("CameraSource")
{
}

Component* ComponentsEnum::Countdown::createComponent(
		rapidxml::xml_node<>* archetypeNode)
{
	return new CountdownComponent(archetypeNode);
}

ComponentsEnum::Countdown::Countdown() :
		ComponentsEnum("Countdown")
{
}

Component* ComponentsEnum::Damage::createComponent(
		rapidxml::xml_node<>* archetypeNode)
{
	return new DamageComponent(archetypeNode);
}

ComponentsEnum::Damage::Damage() :
		ComponentsEnum("Damage")
{
}

Component* ComponentsEnum::HasScore::createComponent(
		rapidxml::xml_node<>* archetypeNode)
{
	return new HasScoreComponent(archetypeNode);
}

ComponentsEnum::HasScore::HasScore() :
		ComponentsEnum("HasScore")
{
}

Component* ComponentsEnum::Music::createComponent(
		rapidxml::xml_node<>* archetypeNode)
{
	return new MusicComponent(archetypeNode);
}

ComponentsEnum::Music::Music() :
		ComponentsEnum("Music")
{
}

Component* ComponentsEnum::Particle::createComponent(
		rapidxml::xml_node<>* archetypeNode)
{
	return new ParticleComponent(archetypeNode);
}

ComponentsEnum::Particle::Particle() :
		ComponentsEnum("Particle")
{
}

Component* ComponentsEnum::Physics::createComponent(
		rapidxml::xml_node<>* archetypeNode)
{
	return new PhysicsComponent(archetypeNode);
}

ComponentsEnum::Physics::Physics() :
		ComponentsEnum("Physics")
{
}

Component* ComponentsEnum::Position::createComponent(
		rapidxml::xml_node<>* archetypeNode)
{
	return new PositionComponent(archetypeNode);
}

ComponentsEnum::Position::Position() :
		ComponentsEnum("Position")
{
}

Component* ComponentsEnum::PositionRelativeTo::createComponent(
		rapidxml::xml_node<>* archetypeNode)
{
	return new PositionRelativeToComponent(archetypeNode);
}

ComponentsEnum::PositionRelativeTo::PositionRelativeTo() :
		ComponentsEnum("PositionRelativeTo")
{
}

Component* ComponentsEnum::Remove::createComponent(
		rapidxml::xml_node<>* archetypeNode)
{
	return new RemoveComponent(archetypeNode);
}

ComponentsEnum::Remove::Remove() :
		ComponentsEnum("Remove")
{
}

Component* ComponentsEnum::Score::createComponent(
		rapidxml::xml_node<>* archetypeNode)
{
	return new ScoreComponent(archetypeNode);
}

ComponentsEnum::Score::Score() :
		ComponentsEnum("Score")
{
}

Component* ComponentsEnum::Sprite::createComponent(
		rapidxml::xml_node<>* archetypeNode)
{
	return new SpriteComponent(archetypeNode);
}

ComponentsEnum::Sprite::Sprite() :
		ComponentsEnum("Sprite")
{
}

Component* ComponentsEnum::Standable::createComponent(
		rapidxml::xml_node<>* archetypeNode)
{
	return new StandableComponent(archetypeNode);
}

ComponentsEnum::Standable::Standable() :
		ComponentsEnum("Standable")
{
}

Component* ComponentsEnum::Text::createComponent(
		rapidxml::xml_node<>* archetypeNode)
{
	return new TextComponent(archetypeNode);
}

ComponentsEnum::Text::Text() :
		ComponentsEnum("Text")
{
}

Component* ComponentsEnum::Viewport::createComponent(
		rapidxml::xml_node<>* archetypeNode)
{
	return new ViewportComponent(archetypeNode);
}

ComponentsEnum::Viewport::Viewport() :
		ComponentsEnum("Viewport")
{
}

Component* ComponentsEnum::StandsOn::createComponent(
		rapidxml::xml_node<>* archetypeNode)
{
	return new StandsOnComponent(archetypeNode);
}

ComponentsEnum::StandsOn::StandsOn() :
		ComponentsEnum("StandsOn")
{
}
