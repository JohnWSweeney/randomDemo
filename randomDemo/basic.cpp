#include "basic.h"
#include "random.h"
#include "defaultPRNG.h"
#include "atomicBool.h"
#include "characters.h"

void basic(unsigned int n, unsigned int min, unsigned int max)
{
	// Compare rand, rand_s, mt19937, and mt19937_64 random numbers.
	random rando;
	std::cout << "#\trand:\trand_s:\tmt32:\tmt64:\n";
	rando.setSeed(1, NULL);
	rando.setSeed(3, NULL);
	rando.setSeed(5, NULL);
	for (int i = 1; i < n + 1; i++)
	{
		std::cout << i << "\t";
		std::cout << rando.getNum(1, min, max) << "\t";
		std::cout << rando.getNum(2, min, max) << "\t";
		std::cout << rando.getNum(3, min, max) << "\t";
		std::cout << rando.getNum(5, min, max) << '\n';
	}
	std::cout << '\n';
	basicStatus = false;
}

void basicSeed(int n, int seed, unsigned int min, unsigned int max)
{
	// Compare rand, mt19937, and mt19937_64 random numbers with user seed.
	random rando;
	std::cout << "#\trand\tmt32\tmt64\n";
	rando.setSeed(0, seed);
	rando.setSeed(4, seed);
	rando.setSeed(6, seed);
	for (int i = 1; i < n + 1; i++)
	{
		std::cout << i << '\t';
		std::cout << rando.getNum(0, min, max) << '\t';
		std::cout << rando.getNum(4, min, max) << '\t';
		std::cout << rando.getNum(6, min, max) << '\n';
	}
	std::cout << '\n';
	basicSeedStatus = false;
}

void wall()
{
	// Make a wall of text from 1M random characters.
	int wallSize = 1000000;
	std::string wallOfText;
	char tempChar, prevChar = '\0';
	int temp, prevtemp = 9;
	random rando;
	rando.setSeed(defaultPRNG, NULL);
	for (int i = 0; i < wallSize; i++)
	{
		do {
			temp = rando.getNum(defaultPRNG, 0, 3);
			unsigned int index;
			if (temp == 0) // lowercase letters.
			{
				index = rando.getNum(defaultPRNG, 0, charLowerCase.size() - 1);
				tempChar = charLowerCase[index];
			}
			else if (temp == 1) // uppercase letters.
			{
				index = rando.getNum(defaultPRNG, 0, charUpperCase.size() - 1);
				tempChar = charUpperCase[index];
			}
			else if (temp == 2) // numbers.
			{
				index = rando.getNum(defaultPRNG, 0, numbers.size() - 1);
				tempChar = numbers[index];
			}
			else // special characters.
			{
				index = rando.getNum(defaultPRNG, 0, special.size() - 1);
				tempChar = special[index];
			}
		} while (tempChar == prevChar || temp == prevtemp);
		wallOfText.push_back(tempChar);
		prevChar = tempChar;
		prevtemp = temp;
	}
	std::cout << wallOfText << "\n\n";
}