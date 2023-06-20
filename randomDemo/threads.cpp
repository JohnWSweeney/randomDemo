#include "threads.h"
#include "basic.h"
#include "chance.h"
#include "atomicBool.h"

void startBasicThread(std::vector<std::string> &tokens)
{
	if (tokens[1] == "stop")
	{
		basicStatus = false;
	}
	else
	{
		try {
			unsigned int n = stoi(tokens[1]);
			unsigned int min = stoi(tokens[2]);
			unsigned int max = stoi(tokens[3]);
			basicStatus = true;
			std::thread basicThread(basic, n, min, max);
			basicThread.detach();
		}
		catch (std::invalid_argument)
		{
			std::cout << "Invalid arguement for n.\n\n";
		}
		catch (std::out_of_range)
		{
			std::cout << "n is out of range.\n\n";
		}
	}
}

void startBasicSeedThread(std::vector<std::string> &tokens)
{
	if (tokens[1] == "stop")
	{
		basicSeedStatus = false;
	}
	else
	{
		try {
			int n = stoi(tokens[1]);
			int seed = stoi(tokens[2]);
			int min = stoi(tokens[3]);
			int max = stoi(tokens[4]);
			basicSeedStatus = true;
			std::thread basicSeedThread(basicSeed, n, seed, min, max);
			basicSeedThread.detach();
		}
		catch (std::invalid_argument)
		{
			std::cout << "Invalid arguement for n.\n\n";
		}
		catch (std::out_of_range)
		{
			std::cout << "n is out of range.\n\n";
		}
	}
	
}

void startCoinFlipStreakThread(std::vector<std::string> &tokens)
{
	if (tokens[1] == "stop")
	{
		coinFlipStreakStatus = false;
	}
	else
	{
		try {
			int streak = stoi(tokens[1]);
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
	
}

void startDiceRollMatchThread(std::vector<std::string> &tokens)
{
	if (tokens[1] == "stop")
	{
		diceRollMatchStatus = false;
	}
	else
	{
		try {
			int numSides = std::stoi(tokens[1]);
			int numDice = std::stoi(tokens[2]);
			if (numSides < 4 || numDice < 2)
			{
				throw 20;
			}
			diceRollMatchStatus = true;
			std::thread diceStreakThread(diceRollMatch, numSides, numDice);
			diceStreakThread.detach();
		}
		catch (std::invalid_argument)
		{
			std::cout << "Invalid arguement for int.\n\n";
		}
		catch (std::out_of_range)
		{
			std::cout << "int is out of range.\n\n";
		}
		catch (int e)
		{
			std::cout << "asdfasdfasdf.\n\n";
		}
	}	
}