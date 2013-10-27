/* 
 * File:   BoundingBoxComponent.hpp
 * Author: marzena
 *
 * Created on 18 luty 2013, 22:20
 */

#ifndef BOUNDINGBOXCOMPONENT_HPP
#define	BOUNDINGBOXCOMPONENT_HPP

#include <set>

#include "Component.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "rapidxml/rapidxml.hpp"

struct BoundingBoxComponent: public Component
{
	struct CollisionData
	{
		CollisionData() :
				EID(0), tx(0), ty(0), top(0), right(0), bottom(0), left(0)
		{
		}
		int EID;
		double tx, ty;
		bool top, right, bottom, left;
	};
	BoundingBoxComponent(int EID);
	BoundingBoxComponent(sf::Rect<double> boundingBox, int EID);
	BoundingBoxComponent(rapidxml::xml_node<>* componentNode);
	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);

	sf::Rect<double> boundingBox;
	bool topSolid, rightSolid, bottomSolid, leftSolid;
	//pair entity - collision time
	std::list<CollisionData> collidedWith;
	std::set<int> collisionGroups;
};

#endif	/* BOUNDINGBOXCOMPONENT_HPP */

