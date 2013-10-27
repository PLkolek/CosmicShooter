/* 
 * File:   PairStringIntHash.hpp
 * Author: kolzi
 *
 * Created on 25 kwiecień 2013, 15:57
 */

#ifndef PAIRSTRINGINTHASH_HPP
#define	PAIRSTRINGINTHASH_HPP

#include <functional>

class PairIntStringHash
{
public:
	size_t operator()(const std::pair<int, std::string>& p) const
	{
		size_t h1 = std::hash<int>()(p.first);
		size_t h2 = std::hash<std::string>()(p.second);
		return h1 ^ h2;
	}
};

#endif	/* PAIRSTRINGINTHASH_HPP */

