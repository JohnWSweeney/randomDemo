#include "start.h"
#include "threads.h"
#include "basic.h"
#include "chance.h"
#include "defaultPRNG.h"
#include "atomicBool.h"

void getInput(std::vector<std::string> &tokens)
{
	tokens.clear();
	// Tokenize user input.
	do {
		std::string input, tempStr;
		std::getline(std::cin, input, '\n');
		std::stringstream strStream(input);
		while (getline(strStream, tempStr, ' '))
		{
			tokens.push_back(tempStr);
		}
	} while (tokens.empty());
}

void startMenu(bool &running, std::vector<std::string> &tokens)
{
	// 
	if (tokens[0] == "basic")
	{
		if (tokens.size() < 2)
		{
			basic(10, 0, 10);
		}
		else
		{
			startBasicThread(tokens);
		}
	}
	else if (tokens[0] == "wall")
	{
		wall();
	}
	else if (tokens[0] == "basicSeed")
	{
		if (tokens.size() < 2)
		{
			basicSeed(10, 0, 0, 10);
		}
		else
		{
			if (tokens[1].empty() || tokens[2].empty())
			{
				std::cout << "Invalid basicSeed function parameter(s).\n\n";
			}
			else
			{
				startBasicSeedThread(tokens);
			}
		}
	}
	else if (tokens[0] == "coinFlip")
	{
		coinFlip();
	}
	else if (tokens[0] == "diceRoll")
	{
		try {
			int numSides = std::stoi(tokens[1]);
			int numDice = std::stoi(tokens[2]);
			if (numSides < 4)
			{
				throw 20;
			}
			if (numDice < 1)
			{
				throw 20;
			}
			diceRoll(numSides, numDice);
		}
		catch (std::invalid_argument)
		{
			std::cout << "Invalid arguement for number of dice sides.\n\n";
		}
		catch (std::out_of_range)
		{
			std::cout << "Number of dice sides is out of range.\n\n";
		}
		catch (int e)
		{
			std::cout << "Dice must have at least four sides and/or there must be at least one die.\n\n";
		}
	}
	else if (tokens[0] == "coinFlipStreak")
	{
		startCoinFlipStreakThread(tokens);
	}
	else if (tokens[0] == "diceRollMatch")
	{
		startDiceRollMatchThread(tokens);
	}
	else if (tokens[0] == "default")
	{
		prngStatus(tokens);
	}
	else if (tokens[0] == "stop")
	{
		if (tokens[1] == "all")
		{
			basicStatus = false;
			basicSeedStatus = false;
			coinFlipStreakStatus = false;
			diceRollMatchStatus = false;
			std::cout << "All threads stopped.\n\n";
		}
		else
		{
			std::cout << "Invalid stop command.\n\n";
		}
	}
	else if (tokens[0] == "exit")
	{
		basicStatus = false;
		basicSeedStatus = false;
		coinFlipStreakStatus = false;
		diceRollMatchStatus = false;
		running = false;
	}
	else
	{
		std::cout << "Invalid function.\n\n";
	}
}