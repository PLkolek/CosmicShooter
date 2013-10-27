/* 
 * File:   DamageComponent.cpp
 * Author: kolzi
 * 
 * Created on 31 maj 2013, 13:45
 */

#include "DamageComponent.hpp"
#include "Exceptions/RequiredAttributeNotFound.hpp"

#include <boost/lexical_cast.hpp>

const double DamageComponent::defaultDamage = 100000;

DamageComponent::DamageComponent(int EID) :
		Component(EID), damagePerSecond(defaultDamage), once(false), taken(
				false)
{
}

DamageComponent::DamageComponent(int EID, double damagePerSecond) :
		Component(EID), damagePerSecond(defaultDamage), once(false), taken(
				false)
{
}

DamageComponent::DamageComponent(rapidxml::xml_node<>* componentNode) :
		DamageComponent(-1)
{
	read(componentNode);
}

void DamageComponent::read(rapidxml::xml_node<>* componentNode)
{
	if (componentNode->first_attribute("damagePerSecond") != 0)
		damagePerSecond = boost::lexical_cast<double>(
				componentNode->first_attribute("damagePerSecond")->value());
	if (componentNode->first_attribute("once") != 0)
		once = boost::lexical_cast<bool>(
				componentNode->first_attribute("once")->value());
}

Component* DamageComponent::clone(int newEID)
{
	Component* comp = new DamageComponent(*this);
	comp->EID = newEID;
	return comp;
}
