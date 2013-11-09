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

ComponentsEnum::BoundingBox ComponentsEnum::BOUNDINGBOX=ComponentsEnum::BoundingBox();
ComponentsEnum::CameraSource ComponentsEnum::CAMERASOURCE=ComponentsEnum::CameraSource();
ComponentsEnum::Countdown ComponentsEnum::COUNTDOWN=ComponentsEnum::Countdown();
ComponentsEnum::Damage ComponentsEnum::DAMAGE=ComponentsEnum::Damage();
ComponentsEnum::HasScore ComponentsEnum::HASSCORE=ComponentsEnum::HasScore();
ComponentsEnum::Music ComponentsEnum::MUSIC=ComponentsEnum::Music();
ComponentsEnum::Particle ComponentsEnum::PARTICLE=ComponentsEnum::Particle();
ComponentsEnum::Physics ComponentsEnum::PHYSICS=ComponentsEnum::Physics();
ComponentsEnum::Position ComponentsEnum::POSITION=ComponentsEnum::Position();
ComponentsEnum::PositionRelativeTo ComponentsEnum::POSITIONRELATIVETO=ComponentsEnum::PositionRelativeTo();
ComponentsEnum::Remove ComponentsEnum::REMOVE=ComponentsEnum::Remove();
ComponentsEnum::Score ComponentsEnum::SCORE=ComponentsEnum::Score();
ComponentsEnum::Sprite ComponentsEnum::SPRITE=ComponentsEnum::Sprite();
ComponentsEnum::Standable ComponentsEnum::STANDABLE=ComponentsEnum::Standable();
ComponentsEnum::StandsOn ComponentsEnum::STANDSON=ComponentsEnum::StandsOn();
ComponentsEnum::Text ComponentsEnum::TEXT=ComponentsEnum::Text();
ComponentsEnum::Viewport ComponentsEnum::VIEWPORT=ComponentsEnum::Viewport();

ComponentsEnum::~ComponentsEnum()
{
	// TODO Auto-generated destructor stub
}

//transforms name to uppercase and stores in map
ComponentsEnum::ComponentsEnum(std::string name)
:Enum(name)
{
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
