/* 
 * File:   TextComponent.cpp
 * Author: kolzi
 * 
 * Created on 31 maj 2013, 13:55
 */

#include <boost/lexical_cast.hpp>

#include "TextComponent.hpp"
#include "Exceptions/RequiredAttributeNotFound.hpp"
#include "Components/Component.hpp"
#include "General/FontManager.hpp"

TextComponent::TextComponent(int EID) :
		Component(EID), text()
{
}

TextComponent::TextComponent(const TextComponent& orig) :
		Component(orig.EID), text(orig.text)
{
}

TextComponent::~TextComponent()
{
}

TextComponent::TextComponent(rapidxml::xml_node<>* componentNode) :
		TextComponent(-1)
{
	read(componentNode);
}

void TextComponent::read(rapidxml::xml_node<>* componentNode)
{
	if (componentNode->first_attribute("font") == 0)
		throw RequiredAttributeNotFound("font", "TextComponent");
	text.setFont(
			FontManager::getFont(
					componentNode->first_attribute("font")->value()));
	if (componentNode->first_attribute("text") != 0)
		text.setString(componentNode->first_attribute("text")->value());
	if (componentNode->first_attribute("size") != 0)
		text.setCharacterSize(
				boost::lexical_cast<int>(
						componentNode->first_attribute("size")->value()));
}

Component* TextComponent::clone(int newEID)
{
	Component* comp = new TextComponent(*this);
	comp->EID = newEID;
	return comp;
}
