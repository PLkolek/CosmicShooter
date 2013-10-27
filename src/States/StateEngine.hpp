/* 
 * File:   StateEngine.hpp
 * Author: mk
 *
 * Created on 9 czerwiec 2013, 18:04
 */

#ifndef STATEENGINE_HPP
#define	STATEENGINE_HPP
#include <memory>
#include <stack>
#include <queue>
#include "State.hpp"
#include "General/ArchetypesManager.h"

class StateEngine
{
public:
	StateEngine();
	StateEngine(const StateEngine& orig);
	virtual ~StateEngine();
	void update();
	void changeState(std::unique_ptr<State> state);
	void pushState(std::unique_ptr<State> state);
	const ArchetypesManager& getArchMan() const;

private:
	std::stack<std::unique_ptr<State>> states;
	std::queue<std::unique_ptr<State>> toPush;
	int toPop;

	ArchetypesManager archMan;
};

#endif	/* STATEENGINE_HPP */

