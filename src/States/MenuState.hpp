/* 
 * File:   newClass.hpp
 * Author: mk
 *
 * Created on 5 czerwiec 2013, 19:43
 */

#ifndef NEWCLASS_HPP
#define	NEWCLASS_HPP
#include "State.hpp"
#include "StateEngine.hpp"
#include "SFML/Graphics.hpp"

class MenuState: public State
{
public:
	MenuState(StateEngine& se, sf::RenderWindow& window);
	void update();
	void Pause();
	void Resume();
private:
	struct MenuOption
	{
		std::string name;
		sf::Color selectedColor;
		sf::Color defaultColor;
	};
	static const int numOptions = 2;
	MenuOption selections[numOptions];
	sf::RenderWindow& window;
	int active;
	StateEngine& se;
	sf::Sprite background;
};

#endif	/* NEWCLASS_HPP */

