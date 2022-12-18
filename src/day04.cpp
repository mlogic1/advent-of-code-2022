/************************  ADVENT OF CODE 2022 **********************************
**                         adventofcode.com                                     *       *
**                                                                              *      /.\
**                         mlogic1 (https://github.com/mlogic1)                 *     /..'\
**                                                                              *     /'.'\
**                                                                              *    /.''.'\
**                         Day 04 - Camp Cleanup                                *    /.'.'.\
**                                                                              *   /'.''.'.\
**                                                                              *   ^^^[_]^^^
********************************************************************************/

#include <advent-common.h>
#include <algorithm>
#include <iostream>
#include <exception>

static constexpr const char* INPUT_FILE = "day04a.txt";

namespace Day04
{
	struct range
	{
		int32_t low;
		int32_t high;
	};

	bool IsInRange(const range& l, const range& r)
	{
		return (r.low >= l.low && r.high <= l.high) || (l.low >= r.low && l.high <= r.high);
	}

	bool Overlaps(const range& l, const range& r)
	{
		return (l.low <= r.high) && (l.high >= r.low);
	}

	void PartA(StringVector& input)
	{
		uint32_t count = 0;
		for (int i = 0; i < input.size(); ++i)
		{
			StringVector pairsStr = common::SplitStringWithDelimiter(input[i], ',');
			StringVector pair = common::SplitStringWithDelimiter(pairsStr[0], '-');
			range l{std::stoi(pair[0]), std::stoi(pair[1])};
			pair = common::SplitStringWithDelimiter(pairsStr[1], '-');
			range r{std::stoi(pair[0]), std::stoi(pair[1])};

			count += IsInRange(l, r);
		}

		std::cout << "Day04 Part A Num of fully covered pairs: " << count << std::endl;
	}

	void PartB(StringVector& input)
	{
		uint32_t count = 0;
		for (int i = 0; i < input.size(); ++i)
		{
			StringVector pairsStr = common::SplitStringWithDelimiter(input[i], ',');
			StringVector pair = common::SplitStringWithDelimiter(pairsStr[0], '-');
			range l{std::stoi(pair[0]), std::stoi(pair[1])};
			pair = common::SplitStringWithDelimiter(pairsStr[1], '-');
			range r{std::stoi(pair[0]), std::stoi(pair[1])};

			count += Overlaps(l, r);
		}

		std::cout << "Day04 Part B Num of overlapping pairs: " << count << std::endl;
	}

	void RunDay()
	{
		StringVector input;

		if (!common::ReadEntireFileStrings(INPUT_FILE, input))
		{
			std::cout << "Day 04 input file fail" << std::endl;
			return;
		}

		PartA(input);
		PartB(input);
	}
}
