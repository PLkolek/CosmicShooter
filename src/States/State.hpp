/* 
 * File:   State.hpp
 * Author: mk
 *
 * Created on 5 czerwiec 2013, 19:39
 */

#ifndef STATE_HPP
#define	STATE_HPP

class State
{
public:
	virtual void update()=0;
	virtual void Pause()=0;
	virtual void Resume()=0;
};
#endif	/* STATE_HPP */

