/************************  ADVENT OF CODE 2022 **********************************
**                         adventofcode.com                                     *       *
**                                                                              *      /.\
**                         mlogic1 (https://github.com/mlogic1)                 *     /..'\
**                                                                              *     /'.'\
**                                                                              *    /.''.'\
**                                                                              *    /.'.'.\
**                                                                              *   /'.''.'.\
**                                                                              *   ^^^[_]^^^
********************************************************************************/

#ifndef ADVENT_DAYS
#define ADVENT_DAYS

#include <advent-common.h>
#include <cstdint>
#include <set>

namespace Day01
{
	void RunDay();

	void PartA(VecStack& stacks);
	void PartB(const std::set<uint32_t>& calorieSums);
}

namespace Day02
{
	void RunDay();

	void PartA(StringVector& input);
	void PartB(StringVector& input);
}

namespace Day03
{
	void RunDay();

	void PartA(StringVector& input);
	void PartB(StringVector& input);
}

namespace Day04
{
	void RunDay();

	void PartA(StringVector& input);
	void PartB(StringVector& input);
}

namespace Day05
{
	void RunDay();

	void PartA(std::vector<std::stack<char>>);
	void PartB(std::vector<std::stack<char>>);
}

#endif
