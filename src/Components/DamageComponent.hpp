/* 
 * File:   DamageComponent.hpp
 * Author: kolzi
 *
 * Created on 31 maj 2013, 17:26
 */

#ifndef DAMAGECOMPONENT_HPP
#define	DAMAGECOMPONENT_HPP

#include "Component.hpp"

struct DamageComponent: public Component
{
	DamageComponent(int EID);
	DamageComponent(int EID, double damagePerSecond);
	DamageComponent(rapidxml::xml_node<>* componentNode);

	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);

	double damagePerSecond;
	bool once;
	bool taken;
	static const double defaultDamage;
};

#endif	/* DAMAGECOMPONENT_HPP */

