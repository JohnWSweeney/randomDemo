#include "defaultPRNG.h"

int defaultPRNG = 3;

void prngQuery()
{
	if (defaultPRNG == 1)
	{
		std::cout << "PRNG: System-time seeded rand.\n\n";
	}
	else if (defaultPRNG == 2)
	{
		std::cout << "PRNG: rand_s.\n\n";
	}
	else if (defaultPRNG == 3)
	{
		std::cout << "PRNG: Random_device-seeded 32-bit Mersenne Twister.\n\n";
	}
	else if (defaultPRNG == 5)
	{
		std::cout << "PRNG: Random_device-seeded 64-bit Mersenne Twister.\n\n";
	}
}

void prngStatus(std::vector<std::string> &tokens)
{
	if (tokens[1] == "query")
	{
		prngQuery();
	}
	else if (tokens[1] == "set")
	{
		if (tokens[2] == "rand")
		{
			defaultPRNG = 1;
			prngQuery();
		}
		else if (tokens[2] == "rand_s")
		{
			defaultPRNG = 2;
			prngQuery();
		}
		else if (tokens[2] == "mt32")
		{
			defaultPRNG = 3;
			prngQuery();
		}
		else if (tokens[2] == "mt64")
		{
			defaultPRNG = 5;
			prngQuery();
		}
		else
		{
			std::cout << "Invalid PRNG type.\n\n";
		}
	}
	else
	{
		std::cout << "Invalid command.\n\n";
	}
}