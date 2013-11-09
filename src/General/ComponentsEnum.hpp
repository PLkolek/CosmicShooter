/*
 * ComponentsEnum.h
 *
 *  Created on: 24 paź 2013
 *      Author: kolzi
 */

#ifndef COMPONENTSENUM_H_
#define COMPONENTSENUM_H_

#include <map>
#include <string>
#include <vector>
#include <list>
#include <functional>
#include "rapidxml/rapidxml.hpp"

#include "Utility/Enum.h"

class Component;

class ComponentsEnum: public Enum<ComponentsEnum>
{
public:
	static int nextId;

	virtual Component* createComponent(rapidxml::xml_node<>* archetypeNode)=0;
	virtual ~ComponentsEnum();

	class BoundingBox;
	class CameraSource;
	class Countdown;
	class Damage;
	class HasScore;
	class Music;
	class Particle;
	class Physics;
	class Position;
	class PositionRelativeTo;
	class Remove;
	class Score;
	class Sprite;
	class Standable;
	class StandsOn;
	class Text;
	class Viewport;

	static BoundingBox BOUNDINGBOX;
	static CameraSource CAMERASOURCE;
	static Countdown COUNTDOWN;
	static Damage DAMAGE;
	static HasScore HASSCORE;
	static Music MUSIC;
	static Particle PARTICLE;
	static Physics PHYSICS;
	static Position POSITION;
	static PositionRelativeTo POSITIONRELATIVETO;
	static Remove REMOVE;
	static Score SCORE;
	static Sprite SPRITE;
	static Standable STANDABLE;
	static StandsOn STANDSON;
	static Text TEXT;
	static Viewport VIEWPORT;

private:
	ComponentsEnum(std::string name);
};

class ComponentsEnum::BoundingBox: public ComponentsEnum
{
public:
	friend class ComponentsEnum;
	virtual Component* createComponent(rapidxml::xml_node<>* archetypeNode);
private:
	BoundingBox();
};

class ComponentsEnum::CameraSource: public ComponentsEnum
{
public:
	friend class ComponentsEnum;
	virtual Component* createComponent(rapidxml::xml_node<>* archetypeNode);
private:
	CameraSource();
};

class ComponentsEnum::Countdown: public ComponentsEnum
{
public:
	friend class ComponentsEnum;
	virtual Component* createComponent(rapidxml::xml_node<>* archetypeNode);
private:
	Countdown();
};

class ComponentsEnum::Damage: public ComponentsEnum
{
public:
	friend class ComponentsEnum;
	virtual Component* createComponent(rapidxml::xml_node<>* archetypeNode);
private:
	Damage();
};

class ComponentsEnum::HasScore: public ComponentsEnum
{
public:
	friend class ComponentsEnum;
	virtual Component* createComponent(rapidxml::xml_node<>* archetypeNode);
private:
	HasScore();
};

class ComponentsEnum::Music: public ComponentsEnum
{
public:
	friend class ComponentsEnum;
	virtual Component* createComponent(rapidxml::xml_node<>* archetypeNode);
private:
	Music();
};

class ComponentsEnum::Particle: public ComponentsEnum
{
public:
	friend class ComponentsEnum;
	virtual Component* createComponent(rapidxml::xml_node<>* archetypeNode);
private:
	Particle();
};

class ComponentsEnum::Physics: public ComponentsEnum
{
public:
	friend class ComponentsEnum;
	virtual Component* createComponent(rapidxml::xml_node<>* archetypeNode);
private:
	Physics();
};

class ComponentsEnum::Position: public ComponentsEnum
{
public:
	friend class ComponentsEnum;
	virtual Component* createComponent(rapidxml::xml_node<>* archetypeNode);
private:
	Position();
};

class ComponentsEnum::PositionRelativeTo: public ComponentsEnum
{
public:
	friend class ComponentsEnum;
	virtual Component* createComponent(rapidxml::xml_node<>* archetypeNode);
private:
	PositionRelativeTo();
};

class ComponentsEnum::Remove: public ComponentsEnum
{
public:
	friend class ComponentsEnum;
	virtual Component* createComponent(rapidxml::xml_node<>* archetypeNode);
private:
	Remove();
};

class ComponentsEnum::Score: public ComponentsEnum
{
public:
	friend class ComponentsEnum;
	virtual Component* createComponent(rapidxml::xml_node<>* archetypeNode);
private:
	Score();
};

class ComponentsEnum::Sprite: public ComponentsEnum
{
public:
	friend class ComponentsEnum;
	virtual Component* createComponent(rapidxml::xml_node<>* archetypeNode);
private:
	Sprite();
};

class ComponentsEnum::Standable: public ComponentsEnum
{
public:
	friend class ComponentsEnum;
	virtual Component* createComponent(rapidxml::xml_node<>* archetypeNode);
private:
	Standable();
};

class ComponentsEnum::StandsOn: public ComponentsEnum
{
public:
	friend class ComponentsEnum;
	virtual Component* createComponent(rapidxml::xml_node<>* archetypeNode);
private:
	StandsOn();
};

class ComponentsEnum::Text: public ComponentsEnum
{
public:
	friend class ComponentsEnum;
	virtual Component* createComponent(rapidxml::xml_node<>* archetypeNode);
private:
	Text();
};

class ComponentsEnum::Viewport: public ComponentsEnum
{
public:
	friend class ComponentsEnum;
	virtual Component* createComponent(rapidxml::xml_node<>* archetypeNode);
private:
	Viewport();
};

#endif /* COMPONENTSENUM_H_ */
