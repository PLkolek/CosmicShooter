/* 
 * File:   CountdownComponent.cpp
 * Author: kolzi
 * 
 * Created on 4 czerwiec 2013, 11:06
 */
#include "CountdownComponent.hpp"
#include "Exceptions/RequiredAttributeNotFound.hpp"

#include <boost/lexical_cast.hpp>
#include <set>

CountdownComponent::CountdownComponent(int EID) :
		Component(EID), startTime(-1), timeLeft(-1), toText(false), restart(
				false), actions(), actIt(actions.begin())
{
}

CountdownComponent::CountdownComponent(int EID, double startTime) :
		Component(EID), startTime(startTime), timeLeft(startTime), toText(
				false), restart(false), actions(), actIt(actions.begin())
{
}

CountdownComponent::CountdownComponent(CountdownComponent& orig) :
		Component(orig.EID), startTime(orig.startTime), timeLeft(orig.timeLeft), toText(
				orig.toText), restart(orig.restart), actions(orig.actions), actIt(
				actions.begin())
{
}

CountdownComponent::CountdownComponent(rapidxml::xml_node<>* componentNode) :
		CountdownComponent(-1)
{
	read(componentNode);
	std::cerr << "Countdown read!\n";
	for (Action act : actions)
	{
		std::cerr << act.name << " " << act.target << " " << act.time << "\n";
	}
}

void CountdownComponent::read(rapidxml::xml_node<>* componentNode)
{
	if (componentNode->first_attribute("time") != 0)
		startTime = timeLeft = boost::lexical_cast<double>(
				componentNode->first_attribute("time")->value());
	if (componentNode->first_attribute("toText") != 0)
		toText = boost::lexical_cast<bool>(
				componentNode->first_attribute("toText")->value());
	if (componentNode->first_attribute("restart") != 0)
		restart = boost::lexical_cast<bool>(
				componentNode->first_attribute("restart")->value());
	for (rapidxml::xml_node<> * actionNode = componentNode->first_node();
			actionNode; actionNode = actionNode->next_sibling())
	{
		Action a;
		a.name = actionNode->name();
		if (actionNode->first_attribute("time") != 0)
			a.time = boost::lexical_cast<double>(
					actionNode->first_attribute("time")->value());
		else
			throw RequiredAttributeNotFound("time", "Countdown::Action");

		if (actionNode->first_attribute("target") != 0)
			a.target = actionNode->first_attribute("target")->value();

		if (actionNode->first_attribute("targetTime") != 0)
			a.targetTime = boost::lexical_cast<double>(
					actionNode->first_attribute("targetTime")->value());
		else if (actionNode->name() == "Reset")
			throw RequiredAttributeNotFound("targetTime",
					"Countdown::ActionReset");

		actions.insert(a);
	}
	actIt = actions.begin();
}

Component* CountdownComponent::clone(int newEID)
{
	Component* comp = new CountdownComponent(*this);
	comp->EID = newEID;
	return comp;
}

