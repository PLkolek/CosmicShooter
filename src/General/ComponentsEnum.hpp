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
#include <memory>

#include "rapidxml/rapidxml.hpp"

class Component;

class ComponentsEnum
{
public:
	typedef const std::vector<std::unique_ptr<ComponentsEnum>>&  ConstEnumsVector;
	static int nextId;
	static ConstEnumsVector getValues();
	static ComponentsEnum& getByName(std::string name);

	virtual Component* createComponent(rapidxml::xml_node<>* archetypeNode)=0;
	virtual std::string getName();
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
private:
	ComponentsEnum(std::string name);
	typedef std::vector<std::unique_ptr<ComponentsEnum>>  EnumsVector;
	typedef std::map<std::string, ComponentsEnum&>  NameEnumMap;
	static NameEnumMap nameToEnum;
	static EnumsVector enums;
	std::string name;
	int id;
	static EnumsVector initEnums();
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
