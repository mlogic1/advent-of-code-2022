/************************  ADVENT OF CODE 2022 **********************************
**                         adventofcode.com                                     *       *
**                                                                              *      /.\
**                         mlogic1 (https://github.com/mlogic1)                 *     /..'\
**                                                                              *     /'.'\
**                                                                              *    /.''.'\
**                         Day 02 - Rock Paper Scissors                         *    /.'.'.\
**                                                                              *   /'.''.'.\
**                                                                              *   ^^^[_]^^^
********************************************************************************/

#include <advent-common.h>
#include <iostream>
#include <exception>

static constexpr const char* INPUT_FILE = "day02a.txt";

namespace Day02
{
	static const std::map<string, uint32_t> SCORING_MAP =
	{
		{ "A X", 1 + 3 },
		{ "A Y", 2 + 6 },
		{ "A Z", 3 + 0 },
		{ "B X", 1 + 0 },
		{ "B Y", 2 + 3 },
		{ "B Z", 3 + 6 },
		{ "C X", 1 + 6 },
		{ "C Y", 0 + 2 },
		{ "C Z", 3 + 3 }
	};

	static const std::map<string, uint32_t> SCORING_MAP_B =
	{
		{ "A X", 0 + 3 },
		{ "A Y", 3 + 1 },
		{ "A Z", 6 + 2 },
		{ "B X", 0 + 1 },
		{ "B Y", 3 + 2 },
		{ "B Z", 6 + 3 },
		{ "C X", 0 + 2 },
		{ "C Y", 3 + 3 },
		{ "C Z", 6 + 1 }
	};

	void PartA(StringVector& input)
	{
		uint32_t playerScore = 0;
		for (int i = 0; i < input.size(); ++i)
		{
			const char oponent = input[i].at(0);
			const char player = input[i].at(2);
			playerScore += SCORING_MAP.at(input[i]);
		}
		std::cout << "Day02 Part A player score: " << playerScore << std::endl;
	}

	void PartB(StringVector& input)
	{
		uint32_t playerScore = 0;
		for (int i = 0; i < input.size(); ++i)
		{
			const char oponent = input[i].at(0);
			const char player = input[i].at(2);
			playerScore += SCORING_MAP_B.at(input[i]);
		}
		std::cout << "Day02 Part B player score: " << playerScore << std::endl;
	}

	void RunDay()
	{
		StringVector input;

		if (!common::ReadEntireFileStrings(INPUT_FILE, input))
		{
			std::cout << "Day 02 input file fail" << std::endl;
			return;
		}

		PartA(input);
		PartB(input);
	}
}