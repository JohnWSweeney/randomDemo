#include "basic.h"
#include "atomicBool.h"

void unseededRand(int n, std::vector<int> &unseededData)
{
	// Generate/store ten unseeded (pseudo)random numbers.
	for (int i = 0; i < n; i++)
	{
		int x = rand();
		unseededData.push_back(x);
	}
}

void seededRand(int seed, int n, std::vector<int> &seededData)
{
	// Generate/store ten (pseudo)random numbers with user's seed.
	srand(seed);
	for (int i = 0; i < n; i++)
	{
		int x = rand();
		seededData.push_back(x);
	}
}

void basic(int seed, int n)
{
	// Compare unseeded, user-seeded, and system time-seeded (pseudo)random numbers.
	results data;
	unseededRand(n, data.unseededData);
	seededRand(seed, n, data.seededData);
	int sysTime = std::time(nullptr);
	seededRand(sysTime, n, data.seedSysTimeData);

	std::cout << "\n\tUnseeded:\t" << "Seed: " << seed << "\t\tSysTime seed:\n";
	for (int i = 0; i < n; i++)
	{
		std::cout << std::to_string(i+1) << "\t" << data.unseededData[i] << "\t\t" << data.seededData[i] << "\t\t" << data.seedSysTimeData[i] << '\n';
	}
	std::cout << "\nSystem time seed: " << sysTime << "\n\n";
	customBasicThreadStatus = false;
}