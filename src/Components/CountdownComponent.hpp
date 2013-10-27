/* 
 * File:   CountdownComponent.hpp
 * Author: kolzi
 *
 * Created on 4 czerwiec 2013, 11:06
 */

#ifndef COUNTDOWNCOMPONENT_HPP
#define	COUNTDOWNCOMPONENT_HPP

#include <set>

#include "Component.hpp"

struct Action
{
	double time;
	std::string name;
	std::string target;
	double targetTime;
};

class CompareByTime
{
public:
	bool operator()(const Action& lhs, const Action& rhs) const
	{
		return (lhs.time > rhs.time);
	}
};

struct CountdownComponent: public Component
{
	CountdownComponent(int EID);
	CountdownComponent(int EID, double startTime);
	CountdownComponent(CountdownComponent& orig);
	CountdownComponent(rapidxml::xml_node<>* componentNode);

	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);

	double startTime;
	double timeLeft;
	bool toText;
	bool restart;

	std::multiset<Action, CompareByTime> actions;
	std::multiset<Action, CompareByTime>::iterator actIt;
};

#endif	/* COUNTDOWNCOMPONENT_HPP */

