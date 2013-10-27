/* 
 * File:   CollisionSystem.cpp
 * Author: marzena
 * 
 * Created on 20 luty 2013, 00:06
 */

#include "CollisionSystem.hpp"
#include "Components/BoundingBoxComponent.hpp"
#include "Components/StandsOnComponent.hpp"
#include "Components/StandableComponent.hpp"
#include "Components/HasScoreComponent.hpp"
#include "Components/ScoreComponent.hpp"
#include "Components/DamageComponent.hpp"
#include "Components/CountdownComponent.hpp"

#include <iostream>
#include <algorithm>
#include <assert.h>
#include <boost/cast.hpp>
#include <set>

CollisionSystem::CollisionSystem(Level::CompMap& components) :
		System(components)
{
}

CollisionSystem::CollisionSystem(const CollisionSystem& orig) :
		System(orig)
{
}

CollisionSystem::~CollisionSystem()
{
}

void CollisionSystem::addEntity(int EID)
{
	assert(
			components.find(Level::CompKey(EID, "Position")) != components.end()
					&& components.find(Level::CompKey(EID, "BoundingBox"))
							!= components.end());
	entities.insert(EID);
}

void CollisionSystem::update(sf::Time deltaTime)
{
	sf::Clock timer;
	std::list<int> resetX, resetY;
	for (auto it = entities.begin(); it != entities.end(); it++)
	{
		BoundingBoxComponent& bbCi = *boost::polymorphic_downcast<
				BoundingBoxComponent*>(
				components.at(Level::CompKey(*it, "BoundingBox")));
		bbCi.collidedWith.clear();
	}
	for (auto it = entities.begin(); it != entities.end(); it++)
	{
		PositionComponent& posCi = *boost::polymorphic_downcast<
				PositionComponent*>(
				components.at(Level::CompKey(*it, "Position")));
		PhysicsComponent empty(*it,0, 0, 0, 0);
		PhysicsComponent& physCi = (
				components.find(Level::CompKey(*it, "Physics"))
						!= components.end() ?
						*boost::polymorphic_downcast<PhysicsComponent*>(
								components.at(Level::CompKey(*it, "Physics"))) :
						empty);

		BoundingBoxComponent& bbCi = *boost::polymorphic_downcast<
				BoundingBoxComponent*>(
				components.at(Level::CompKey(*it, "BoundingBox")));

		//	bool iCanStand = components.find(Level::CompKey(*it, "StandsOn")) != components.end();
		//	bool iStandable = components.find(Level::CompKey(*it, "Standable")) != components.end();

		//	bool iHasScore = components.find(Level::CompKey(*it, "HasScore")) != components.end();
		//	bool iDamage = components.find(Level::CompKey(*it, "Damage")) != components.end();

		auto jt = it;
		for (jt++; jt != entities.end(); jt++)
		{
			PositionComponent& posCj = *boost::polymorphic_downcast<
					PositionComponent*>(
					components.at(Level::CompKey(*jt, "Position")));
			PhysicsComponent& physCj = (
					components.find(Level::CompKey(*jt, "Physics"))
							!= components.end() ?
							*boost::polymorphic_downcast<PhysicsComponent*>(
									components.at(
											Level::CompKey(*jt, "Physics"))) :
							empty);

			BoundingBoxComponent& bbCj = *boost::polymorphic_downcast<
					BoundingBoxComponent*>(
					components.at(Level::CompKey(*jt, "BoundingBox")));

			sf::Rect<double> bbi = bbCi.boundingBox;
			sf::Rect<double> bbj = bbCj.boundingBox;

			bbi.left += posCi.x;
			bbi.top += posCi.y;
			bbj.left += posCj.x;
			bbj.top += posCj.y;

			if (bbi.intersects(bbj))
			{
				double tx = 999999;
				double ty = 999999;
				double relVx = physCi.v.x - physCj.v.x;
				if (relVx > 0)
					tx = (bbi.left + bbi.width - bbj.left) / relVx;
				if (relVx < 0)
					tx = (bbi.left - bbj.left - bbj.width) / relVx;
				double relVy = physCi.v.y - physCj.v.y;
				if (relVy > 0)
					ty = (bbi.top + bbi.height - bbj.top) / relVy;
				if (relVy < 0)
					ty = (bbi.top - bbj.top - bbj.height) / relVy;
				double t = std::min(tx, ty);

				const double eps = 0.001;
				BoundingBoxComponent::CollisionData colDatai, colDataj;
				colDatai.EID = *jt;
				colDataj.EID = *it;

				colDataj.tx = colDatai.tx = std::min(tx,
						(double) deltaTime.asSeconds());
				colDataj.ty = colDatai.ty = std::min(ty,
						(double) deltaTime.asSeconds());

				if (tx <= deltaTime.asSeconds() + eps)
				{
					if (posCi.x - (tx * physCi.v.x) <= posCj.x - (t * physCj.v.x))
					{
						colDatai.right = true;
						colDataj.left = true;
					}
					else
					{
						colDatai.left = true;
						colDataj.right = true;
					}
				}
				if (ty <= deltaTime.asSeconds() + eps)
				{
					if (posCi.y - (ty * physCi.v.y) <= posCj.y - (t * physCj.v.y))
					{
						colDatai.bottom = true;
						colDataj.top = true;
					}
					else
					{
						colDatai.top = true;
						colDataj.bottom = true;
					}
				}
				bbCi.collidedWith.push_back(colDatai);
				bbCj.collidedWith.push_back(colDataj);

				bool sameGroup = false;
				for (int group : bbCi.collisionGroups)
				{
					if (bbCj.collisionGroups.find(group)
							!= bbCj.collisionGroups.end())
					{
						sameGroup = true;
						break;
					}
				}
				if (sameGroup)
				{
					if (t == tx && t <= deltaTime.asSeconds() + eps)
					{
						if ((bbCi.leftSolid && bbCj.rightSolid && colDatai.left
								&& colDataj.right)
								|| (bbCj.leftSolid && bbCi.rightSolid
										&& colDataj.left && colDatai.right))
						{
							posCi.x -= (t * physCi.v.x);
							posCj.x -= (t * physCj.v.x);
							resetX.push_back(*it);
							resetX.push_back(*jt);
							/*	physCi.vx=0;
							 physCi.ax=0;
							 physCj.ax=0;
							 physCj.vx=0;*/
						}
						else if ((bbCi.topSolid && bbCj.bottomSolid
								&& colDatai.top && colDataj.bottom)
								|| (bbCj.topSolid && bbCi.bottomSolid
										&& colDataj.top && colDatai.bottom))
						{
							resetY.push_back(*it);
							resetY.push_back(*jt);
							posCi.y -= (ty * physCi.v.y);
							posCj.y -= (ty * physCj.v.y);
							/*	physCi.ay=0;
							 physCi.vy=0;
							 physCj.vy=0;
							 physCj.ay=0;*/
						}
					}
					else if (t == ty && t <= deltaTime.asSeconds() + eps)
					{
						if ((bbCi.topSolid && bbCj.bottomSolid && colDatai.top
								&& colDataj.bottom)
								|| (bbCj.topSolid && bbCi.bottomSolid
										&& colDataj.top && colDatai.bottom))
						{
							resetY.push_back(*it);
							resetY.push_back(*jt);
							posCi.y -= (ty * physCi.v.y);
							posCj.y -= (ty * physCj.v.y);
							/*	physCi.ay=0;
							 physCi.vy=0;
							 physCj.vy=0;
							 physCj.ay=0;*/
						}
						else if ((bbCi.leftSolid && bbCj.rightSolid
								&& colDatai.left && colDataj.right)
								|| (bbCj.leftSolid && bbCi.rightSolid
										&& colDataj.left && colDatai.right))
						{
							resetX.push_back(*it);
							resetX.push_back(*jt);
							posCi.x -= (tx * physCi.v.x);
							posCj.x -= (tx * physCj.v.x);
							/*physCi.vx=0;
							 physCi.ax=0;
							 physCj.ax=0;
							 physCj.vx=0;*/
						}
					}
				}
			}
		}
	}
	for (int EID : resetX)
	{
		if (components.find(Level::CompKey(EID, "Physics")) != components.end())
		{
			PhysicsComponent& pC = *boost::polymorphic_downcast<
					PhysicsComponent*>(
					components.at(Level::CompKey(EID, "Physics")));
			pC.v.x = pC.a.x = 0;
		}
	}
	for (int EID : resetY)
	{
		if (components.find(Level::CompKey(EID, "Physics")) != components.end())
		{
			PhysicsComponent& pC = *boost::polymorphic_downcast<
					PhysicsComponent*>(
					components.at(Level::CompKey(EID, "Physics")));
			pC.v.y = pC.a.y = 0;
		}
	}
	std::cerr << "Collision system: " << timer.getElapsedTime().asMilliseconds()
			<< "\n";
}
