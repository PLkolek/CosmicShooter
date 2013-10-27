/* 
 * File:   PhysicsComponent.cpp
 * Author: marzena
 * 
 * Created on 19 luty 2013, 22:38
 */

#include "PhysicsComponent.hpp"
#include "Exceptions/RequiredAttributeNotFound.hpp"

#include <boost/lexical_cast.hpp>


PhysicsComponent::PhysicsComponent(int EID, float mass, double acceleration, double maxSpeed, double stoppingSpeed) :
		Component(EID), v(), a(), f(), m(mass), angularV(0), prevV(), prevA(), prevF(), prevM(), prevAngularV(),
		 acceleration(acceleration), maxSpeed(maxSpeed), stoppingSpeed(stoppingSpeed)
{
}

PhysicsComponent::PhysicsComponent(rapidxml::xml_node<>* componentNode) :
		Component(-1), v(), a(), f(), angularV(0), prevV(), prevA(), prevF(), prevAngularV()
{
	read(componentNode);
}

void PhysicsComponent::read(rapidxml::xml_node<>* componentNode)
{
	if (componentNode->first_attribute("vx") != 0)
		v.x = boost::lexical_cast<double>(componentNode->first_attribute("vx")->value());
	if (componentNode->first_attribute("vy") != 0)
		v.y = boost::lexical_cast<double>(componentNode->first_attribute("vy")->value());
	if (componentNode->first_attribute("ax") != 0)
		a.x = boost::lexical_cast<double>(componentNode->first_attribute("ax")->value());
	if (componentNode->first_attribute("ay") != 0)
		a.y = boost::lexical_cast<double>(componentNode->first_attribute("ay")->value());
	if (componentNode->first_attribute("fx") != 0)
		f.x = boost::lexical_cast<double>(componentNode->first_attribute("fx")->value());
	if (componentNode->first_attribute("fy") != 0)
		f.y = boost::lexical_cast<double>(componentNode->first_attribute("fy")->value());

	if (componentNode->first_attribute("angularV") != 0)
		angularV = boost::lexical_cast<double>(componentNode->first_attribute("angularV")->value());

	if (componentNode->first_attribute("m") != 0)
		prevM=m = boost::lexical_cast<double>(componentNode->first_attribute("m")->value());
	else
		throw RequiredAttributeNotFound("m", "Physics");
	if (componentNode->first_attribute("acceleration") != 0)
		acceleration = boost::lexical_cast<double>(componentNode->first_attribute("acceleration")->value());
	else
		throw RequiredAttributeNotFound("acceleration", "Physics");
	if (componentNode->first_attribute("maxSpeed") != 0)
		maxSpeed = boost::lexical_cast<double>(componentNode->first_attribute("maxSpeed")->value());
	else
		throw RequiredAttributeNotFound("maxSpeed", "Physics");
	if (componentNode->first_attribute("stoppingSpeed") != 0)
		stoppingSpeed = boost::lexical_cast<double>(componentNode->first_attribute("stoppingSpeed")->value());
	else
		throw RequiredAttributeNotFound("stoppingSpeed", "Physics");
}

Component* PhysicsComponent::clone(int newEID)
{
	Component* comp = new PhysicsComponent(*this);
	comp->EID = newEID;
	return comp;
}
