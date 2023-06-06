#include "threads.h"
#include "basic.h"
#include "coinFlip.h"
#include "atomicBool.h"
#include <string>

void startBasicCustomThread(std::vector<std::string> &tokens)
{
	int seed, n;
	try {
		seed = stoi(tokens[1]);
	}
	catch (std::invalid_argument)
	{
		std::cout << "Invalid arguement for seed integer.\n\n";
	}
	catch (std::out_of_range)
	{
		std::cout << "Seed integer is out of range.\n\n";
	}

	try {
		n = stoi(tokens[2]);
	}
	catch (std::invalid_argument)
	{
		std::cout << "Invalid arguement for n.\n\n";
	}
	catch (std::out_of_range)
	{
		std::cout << "n is out of range.\n\n";
	}

	try {
		customBasicThreadStatus = true;
		std::thread customBasicThread(basic, seed, n);
		customBasicThread.detach();
	}
	catch (...)
	{
		std::cout << "Error starting customBasicThread.\n\n";
	}
}

void startCoinFlipStreakThread(std::vector<std::string> &tokens)
{
	try {
		int streak = stoi(tokens[1]);
		if (streak > 15)
		{
			throw (streak);
		}
		coinFlipStreakStatus = true;
		std::thread streakThread(coinFlipStreak, streak);
		streakThread.detach();
	}
	catch (std::invalid_argument)
	{
		std::cout << "Invalid arguement for streak length.\n\n";
	}
	catch (std::out_of_range)
	{
		std::cout << "Streak length is out of range.\n\n";
	}
	catch (int streak)
	{
		std::cout << "Streak length must be less than 16. Not sure why yet.\n\n";
	}
}