/* 
 * File:   ParticleSystem.cpp
 * Author: kolzi
 * 
 * Created on 2 czerwiec 2013, 17:15
 */

#include "ParticleSystem.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/ParticleComponent.hpp"
#include "Components/PhysicsComponent.hpp"
#include "Components/SpriteComponent.hpp"
#include "General/ImageManager.hpp"
#include "Components/ScoreComponent.hpp"
#include "Components/PositionRelativeToComponent.hpp"
#include "Components/CountdownComponent.hpp"

#include <assert.h>
#include <boost/cast.hpp>

ParticleSystem::ParticleSystem(Level::CompMap& components, Level& level) :
		System(components), level(level)
{

}

ParticleSystem::ParticleSystem(const ParticleSystem& orig) :
		System(orig), level(level)
{
}

ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::update(sf::Time deltaTime)
{
	sf::Clock timer;
	for (auto it = entities.begin(); it != entities.end(); it++)
	{
		PositionComponent& posC = *boost::polymorphic_downcast<
				PositionComponent*>(
				components.at(Level::CompKey(*it, "Position")));
		ParticleComponent& parC = *boost::polymorphic_downcast<
				ParticleComponent*>(
				components.at(Level::CompKey(*it, "Particle")));
		double timePerParticle = 1.0 / parC.minParticlesPerSec;
		if (parC.minParticlesPerSec != parC.maxParticlesPerSec)
			timePerParticle =
					1.0
							/ double(
									parC.minParticlesPerSec
											+ rand()
													% int(
															parC.maxParticlesPerSec
																	- parC.minParticlesPerSec));

		int particlesToEmit = 0;
		parC.timeSinceLastParticle += deltaTime.asSeconds();
		while (parC.timeSinceLastParticle > timePerParticle)
		{
			if (parC.salvo)
				particlesToEmit += parC.particlesInSalvo;
			else
				particlesToEmit++;
			parC.timeSinceLastParticle -= timePerParticle;
		}

		for (int i = 0; i < particlesToEmit; i++)
		{
			//FIXME: speed must be relative to particle emiter speed
			int newID = level.addArchetype(parC.emitsArchetype);

			double ratio = double(rand()) / double(RAND_MAX);
			double angle = parC.minAngle
					+ ratio * (parC.maxAngle - parC.minAngle);
			angle += posC.angle;
			ratio = double(rand()) / double(RAND_MAX);
			double v = parC.minV + ratio * (parC.maxV - parC.minV);
			PhysicsComponent& partPhysComp = *boost::polymorphic_downcast<
					PhysicsComponent*>(
					components.at(Level::CompKey(newID, "Physics")));
			partPhysComp.v.x = cos(angle / 180.0 * M_PI) * v;
			partPhysComp.v.y = sin(angle / 180.0 * M_PI) * v;

			ratio = double(rand()) / double(RAND_MAX);
			double aV = parC.minAngularV
					+ ratio * (parC.maxAngularV - parC.minAngularV);
			partPhysComp.angularV = aV;

			PositionComponent& partPosComp = *boost::polymorphic_downcast<
					PositionComponent*>(
					components.at(Level::CompKey(newID, "Position")));
			partPosComp.x = posC.x;
			partPosComp.y = posC.y;
			if (components.find(Level::CompKey(*it, "PositionRelativeTo"))
					!= components.end())
			{
				PositionRelativeToComponent& prtC =
						*boost::polymorphic_downcast<
								PositionRelativeToComponent*>(
								components.at(
										Level::CompKey(*it,
												"PositionRelativeTo")));
				PositionComponent& ppC = *boost::polymorphic_downcast<
						PositionComponent*>(
						components.at(
								Level::CompKey(prtC.relativeTo, "Position")));
				partPosComp.x += ppC.x;
				partPosComp.y += ppC.y;
			}

			if (components.find(Level::CompKey(newID, "Countdown"))
					!= components.end())
			{
				CountdownComponent& partCountComp =
						*boost::polymorphic_downcast<CountdownComponent*>(
								components.at(
										Level::CompKey(newID, "Countdown")));
				ratio = double(rand()) / double(RAND_MAX);
				partCountComp.startTime = partCountComp.timeLeft =
						parC.minLifeTime
								+ ratio * (parC.maxLifeTime - parC.minLifeTime);
			}
		}
	}
	std::cerr << "Particle system: " << timer.getElapsedTime().asMilliseconds()
			<< "\n";
}

void ParticleSystem::addEntity(int EID)
{
	assert(
			components.find(Level::CompKey(EID, "Position")) != components.end()
					&& components.find(Level::CompKey(EID, "Particle"))
							!= components.end());
	entities.insert(EID);
}

