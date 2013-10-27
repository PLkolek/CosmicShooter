/* 
 * File:   ScoreComponent.hpp
 * Author: kolzi
 *
 * Created on 28 maj 2013, 03:39
 */

#ifndef SCORECOMPONENT_HPP
#define	SCORECOMPONENT_HPP

#include "Component.hpp"

struct ScoreComponent: public Component
{
	ScoreComponent(int EID);
	ScoreComponent(int EID, double score);
	ScoreComponent(rapidxml::xml_node<>* componentNode);

	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);

	static const double defaultScore;
	double score;
	bool toText;
};

#endif	/* SCORECOMPONENT_HPP */

