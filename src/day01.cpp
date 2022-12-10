/************************  ADVENT OF CODE 2022 **********************************
**                         adventofcode.com                                     *       *
**                                                                              *      /.\
**                         mlogic1 (https://github.com/mlogic1)                 *     /..'\
**                                                                              *     /'.'\
**                                                                              *    /.''.'\
**                         Day 01 - Calorie Counting                            *    /.'.'.\
**                                                                              *   /'.''.'.\
**                                                                              *   ^^^[_]^^^
********************************************************************************/

#include <advent-common.h>
#include <iostream>
#include <exception>

static constexpr const char* INPUT_FILE = "day01a.txt";

namespace Day01
{
	void PartA(const std::set<uint32_t>& calorieSums)
	{
		std::cout <<  "Day01: Biggest sum: "<< *calorieSums.rbegin() << std::endl;
	}

	void PartB(const std::set<uint32_t>& calorieSums)
	{
		std::set<uint32_t>::reverse_iterator it = calorieSums.rbegin();
		uint32_t top3Sum = *it + *(++it) + *(++it);
		std::cout <<  "Day01: Sum of top 3: " << top3Sum << std::endl;
	}

	void RunDay()
	{
		StringVector input;

		std::set<uint32_t> calorieSums;

		try
		{
			std::ifstream file = common::OpenFile(INPUT_FILE);
			string line;
			uint32_t sum = 0;

			while(getline(file, line))
			{
				if (line.empty())
				{
					calorieSums.insert(sum);
					sum = 0;
				}
				else
				{
					sum += std::stoi(line);
				}
			}

			common::CloseFile(file);
		}
		catch(const std::runtime_error& e)
		{
			std::cout << "Day 01 input file fail: " << e.what() << std::endl;
		}

		PartA(calorieSums);
		PartB(calorieSums);
	}
}