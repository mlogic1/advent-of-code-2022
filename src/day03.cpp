/************************  ADVENT OF CODE 2022 **********************************
**                         adventofcode.com                                     *       *
**                                                                              *      /.\
**                         mlogic1 (https://github.com/mlogic1)                 *     /..'\
**                                                                              *     /'.'\
**                                                                              *    /.''.'\
**                         Day 03 - Rucksack Reorganization                     *    /.'.'.\
**                                                                              *   /'.''.'.\
**                                                                              *   ^^^[_]^^^
********************************************************************************/

#include <advent-common.h>
#include <algorithm>
#include <iostream>
#include <exception>

static constexpr const char* INPUT_FILE = "day03a.txt";

namespace Day03
{
	static std::map<char, uint32_t> PRIORITY_MAP;

	static void SetupPriorityMap()
	{
		PRIORITY_MAP.clear();
		int priority = 1;
		for (short i = 'a'; i < 'a' + 26; ++i)
		{
			PRIORITY_MAP[i] = priority;
			++priority;
		}

		for (short i = 'A'; i < 'A' + 26; ++i)
		{
			PRIORITY_MAP[i] = priority;
			++priority;
		}
	}

	void PartA(StringVector& input)
	{
		uint32_t totalSum = 0;
		for (int i = 0; i < input.size(); ++i)
		{
			size_t lenHalf = input[i].size() / 2;
			string left = input[i].substr(0, lenHalf);
			string right = input[i].substr(lenHalf, lenHalf);

			std::vector<char> processedChars;
			for (char c : left)
			{
				if (std::find(processedChars.begin(), processedChars.end(), c) != processedChars.end())
				{
					continue;
				}


				int count = std::count(right.begin(), right.end(), c);
				if (count > 0)
				{
					totalSum += PRIORITY_MAP.at(c);
				}
				processedChars.push_back(c);
			}
		}


		std::cout << "Day03 Part A total priority sum: " << totalSum << std::endl;
	}

	void PartB(StringVector& input)
	{
		uint32_t totalSum = 0;
		for (int i = 0; i < input.size(); i+=3)
		{
			for (char c: input[i])
			{
				// if character is found in next two lines, that's the badge, if not, conitnue
				if (std::find(input[i+1].begin(), input[i+1].end(), c) != input[i+1].end())
				{
					if (std::find(input[i+2].begin(), input[i+2].end(), c) != input[i+2].end())
					{
						// std::cout<<"Found badge: " << c << std::endl;
						totalSum += PRIORITY_MAP.at(c);
						break;
					}
				}
			}
		}
		std::cout << "Day 03 Part B sum: " << totalSum << std::endl;
	}

	void RunDay()
	{
		SetupPriorityMap();
		StringVector input;

		if (!common::ReadEntireFileStrings(INPUT_FILE, input))
		{
			std::cout << "Day 03 input file fail" << std::endl;
			return;
		}

		PartA(input);
		PartB(input);
	}
}
