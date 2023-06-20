#include "chance.h"
#include "random.h"
#include "defaultPRNG.h"
#include "atomicBool.h"

void coinFlip()
{
	random rando;
	rando.setSeed(defaultPRNG, NULL);
	unsigned int side = rando.getNum(defaultPRNG, 0, 1);
	if (side == 0)
	{
		std::cout << "Heads.\n\n";
	}
	else
	{
		std::cout << "Tails.\n\n";
	}
}

void diceRoll(int numSides, int numDice)
{
	random rando;
	rando.setSeed(defaultPRNG, NULL);
	for (int i = 1; i < numDice + 1; i++)
	{
		int side = rando.getNum(defaultPRNG, 1, numSides);
		std::cout << "Die #" << i << ": " << side << "\n";
	}
	std::cout << '\n';
}

void coinFlipStreak(int streak)
{
	unsigned int index = 0;
	int headsCount = 0;
	int tailsCount = 0;
	int result;
	std::string winner;
	random rando;
	rando.setSeed(defaultPRNG, NULL);
	for (unsigned int i = 0; i < UINT_MAX; i++)
	{
		if (coinFlipStreakStatus == false)
		{
			std::cout << "coinFlipStreakThread stopped.\n\n";
			break;
		}

		result = rando.getNum(defaultPRNG, 0, 1);
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

void diceRollMatch(int numSides, int numDice)
{
	random rando;
	rando.setSeed(defaultPRNG, NULL);
	std::vector<int> result;
	int sideMatch = 0;
	int index = 1;

	do {
		if (diceRollMatchStatus == false)
		{
			std::cout << "diceRollMatch stopped.\n";
			break;
		}
		result.clear();
		sideMatch = 0;
		for (int i = 1; i < numDice + 1; i++)
		{
			int side = rando.getNum(defaultPRNG, 1, numSides);
			result.push_back(side);
		}

		for (int i = 1; i < result.size(); i++)
		{
			if (result[i] != result[0])
			{
				break;
			}
			else
			{
				++sideMatch;
				if (sideMatch == result.size() - 1)
				{
					diceRollMatchStatus = false;
				}
			}
		}
		++index;
	} while (sideMatch != result.size() - 1);
	std::cout << index << " rolls\n";
	for (int i = 0; i < numDice; i++)
	{
		std::cout << "Die #" << i + 1 << ": " << result[i] << '\n';
	}
	std::cout << "\n\n";
}