#include "start.h"
#include "threads.h"
#include "basic.h"
#include "coinFlip.h"
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
			basic(1, 10);
		}
		else
		{
			startBasicCustomThread(tokens);
		}
	}
	else if (tokens[0] == "coinFlip")
	{
		coinFlip();
	}
	else if (tokens[0] == "coinFlipStreak")
	{
		startCoinFlipStreakThread(tokens);
	}
	else if (tokens[0] == "stop")
	{
		if (tokens[1] == "all")
		{
			customBasicThreadStatus = false;
			coinFlipStreakStatus = false;
			std::cout << "All threads stopped.\n\n";
		}
		else
		{
			std::cout << "Invalid stop command.\n\n";
		}
	}
	else if (tokens[0] == "exit")
	{
		customBasicThreadStatus = false;
		coinFlipStreakStatus = false;
		running = false;
	}
	else
	{
		std::cout << "Invalid command.\n\n";
	}
}