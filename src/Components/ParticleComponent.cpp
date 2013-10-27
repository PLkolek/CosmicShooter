/* 
 * File:   ParticleComponent.cpp
 * Author: kolzi
 * 
 * Created on 2 czerwiec 2013, 16:40
 */

#include "ParticleComponent.hpp"
#include "Exceptions/RequiredAttributeNotFound.hpp"
#include <boost/lexical_cast.hpp>

const double ParticleComponent::defaultMinV = 100;
const double ParticleComponent::defaultMaxV = 200;
const double ParticleComponent::defaultMinAngularV = 90;
const double ParticleComponent::defaultMaxAngularV = 360;
const double ParticleComponent::defaultMinAngle = -15;
const double ParticleComponent::defaultMaxAngle = 15;
const double ParticleComponent::defaultMinHeight = 0.5;
const double ParticleComponent::defaultMaxHeight = 1.5;
const double ParticleComponent::defaultMinWidth = 0.5;
const double ParticleComponent::defaultMaxWidth = 1.5;
const double ParticleComponent::defaultMinLifeTime = 0.25;
const double ParticleComponent::defaultMaxLifeTime = 0.75;
const double ParticleComponent::defaultMinGravity = 10;
const double ParticleComponent::defaultMaxGravity = 20;
const double ParticleComponent::defaultMinParticlesPerSec = 10;
const double ParticleComponent::defaultMaxParticlesPerSec = 30;
const int ParticleComponent::defaultParticlesInSalvo = 30;

ParticleComponent::ParticleComponent(int EID) :
		Component(EID), timeSinceLastParticle(0), minV(defaultMinV), maxV(
				defaultMaxV), minAngle(defaultMinAngle), maxAngle(
				defaultMaxAngle), minWidth(defaultMinWidth), maxWidth(
				defaultMaxWidth), minHeight(defaultMinHeight), maxHeight(
				defaultMaxHeight), minAngularV(defaultMinAngularV), maxAngularV(
				defaultMaxAngularV), minGravity(defaultMinGravity), maxGravity(
				defaultMaxGravity), minLifeTime(defaultMinLifeTime), maxLifeTime(
				defaultMaxLifeTime), minParticlesPerSec(
				defaultMinParticlesPerSec), maxParticlesPerSec(
				defaultMaxParticlesPerSec), salvo(false), particlesInSalvo(
				defaultParticlesInSalvo)

{

}

ParticleComponent::ParticleComponent(rapidxml::xml_node<>* componentNode) :
		ParticleComponent(-1)
{
	read(componentNode);
}

ParticleComponent::~ParticleComponent()
{
}

void ParticleComponent::read(rapidxml::xml_node<>* componentNode)
{
	if (componentNode->first_attribute("minV") != 0)
		minV = boost::lexical_cast<double>(
				componentNode->first_attribute("minV")->value());
	if (componentNode->first_attribute("maxV") != 0)
		maxV = boost::lexical_cast<double>(
				componentNode->first_attribute("maxV")->value());
	if (componentNode->first_attribute("minAngle") != 0)
		minAngle = boost::lexical_cast<double>(
				componentNode->first_attribute("minAngle")->value());
	if (componentNode->first_attribute("maxAngle") != 0)
		maxAngle = boost::lexical_cast<double>(
				componentNode->first_attribute("maxAngle")->value());
	if (componentNode->first_attribute("minWidth") != 0)
		minWidth = boost::lexical_cast<double>(
				componentNode->first_attribute("minWidth")->value());
	if (componentNode->first_attribute("maxWidth") != 0)
		maxWidth = boost::lexical_cast<double>(
				componentNode->first_attribute("maxWidth")->value());
	if (componentNode->first_attribute("minHeight") != 0)
		minHeight = boost::lexical_cast<double>(
				componentNode->first_attribute("minHeight")->value());
	if (componentNode->first_attribute("maxHeight") != 0)
		maxHeight = boost::lexical_cast<double>(
				componentNode->first_attribute("maxHeight")->value());
	if (componentNode->first_attribute("minAngularV") != 0)
		minAngularV = boost::lexical_cast<double>(
				componentNode->first_attribute("minAngularV")->value());
	if (componentNode->first_attribute("maxAngularV") != 0)
		maxAngularV = boost::lexical_cast<double>(
				componentNode->first_attribute("maxAngularV")->value());
	if (componentNode->first_attribute("minGravity") != 0)
		minGravity = boost::lexical_cast<double>(
				componentNode->first_attribute("minGravity")->value());
	if (componentNode->first_attribute("maxGravity") != 0)
		maxGravity = boost::lexical_cast<double>(
				componentNode->first_attribute("maxGravity")->value());
	if (componentNode->first_attribute("minLifeTime") != 0)
		minLifeTime = boost::lexical_cast<double>(
				componentNode->first_attribute("minLifeTime")->value());
	if (componentNode->first_attribute("maxLifeTime") != 0)
		maxLifeTime = boost::lexical_cast<double>(
				componentNode->first_attribute("maxLifeTime")->value());
	if (componentNode->first_attribute("minParticlesPerSec") != 0)
		minParticlesPerSec = boost::lexical_cast<double>(
				componentNode->first_attribute("minParticlesPerSec")->value());
	if (componentNode->first_attribute("maxParticlesPerSec") != 0)
		maxParticlesPerSec = boost::lexical_cast<double>(
				componentNode->first_attribute("maxParticlesPerSec")->value());
	if (componentNode->first_attribute("minInterval") != 0)
		maxParticlesPerSec = 1.0
				/ boost::lexical_cast<double>(
						componentNode->first_attribute("minInterval")->value());
	if (componentNode->first_attribute("maxInterval") != 0)
	{
		minParticlesPerSec = 1.0
				/ boost::lexical_cast<double>(
						componentNode->first_attribute("maxInterval")->value());
		timeSinceLastParticle = 1.0 / minParticlesPerSec;
	}
	if (componentNode->first_attribute("salvo") != 0)
		salvo = boost::lexical_cast<bool>(
				componentNode->first_attribute("salvo")->value());
	if (componentNode->first_attribute("particlesInSalvo") != 0)
		particlesInSalvo = boost::lexical_cast<int>(
				componentNode->first_attribute("particlesInSalvo")->value());

	if (componentNode->first_attribute("emits") != 0)
		emitsArchetype = componentNode->first_attribute("emits")->value();
	else
		throw RequiredAttributeNotFound("emits", "ParticleComponent");

}

Component* ParticleComponent::clone(int newEID)
{
	Component* comp = new ParticleComponent(*this);
	comp->EID = newEID;
	return comp;
}
