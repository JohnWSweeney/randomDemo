#include "coinFlip.h"
#include "atomicBool.h"

void coinFlip()
{
	srand(std::time(nullptr));
	int side = rand()%2;
	if (side == 0)
	{
		std::cout << "Heads.\n\n";
	}
	else
	{
		std::cout << "Tails.\n\n";
	}
}

void coinFlipStreak(int streak)
{
	unsigned int index = 0;
	int headsCount = 0;
	int tailsCount = 0;
	int result;
	std::string winner;
	srand(std::time(nullptr));
	for (unsigned int i = 0; i < UINT_MAX; i++)
	{
		result = rand() % 2;
		if (result == 0)
		{
			++headsCount;
			tailsCount = 0;
		}
		else
		{
			headsCount = 0;
			++tailsCount;
		}

		if (headsCount == streak || tailsCount == streak)
		{
			if (headsCount == streak)
			{
				winner = "heads";
			}
			else if (tailsCount == streak)
			{
				winner = "tails";
			}
			std::cout << "A streak of " << streak << " " << winner << " in a row required " << index << " coin flips.\n\n";
			coinFlipStreakStatus = false;
			break;
		}
		++index;
	}
}