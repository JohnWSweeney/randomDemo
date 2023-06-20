#include "random.h"

// private: seed functions.
void random::seedRand(int randSeed)
{
	srand(randSeed);
}

void random::seedRandSYS()
{
	srand(std::time(nullptr));
}

void random::initMt32(bool rdSeed, int mtSeed)
{
	if (rdSeed == true) // random_device seeded.
	{
		std::random_device rd;
		mt.seed(rd());
	}
	else // seeded with user int.
	{
		mt.seed(mtSeed);
	}
}

void random::initMt64(bool rdSeed, int mtSeed)
{
	if (rdSeed == true) // random_device seeded.
	{
		std::random_device rd;
		mt64.seed(rd());
	}
	else // seeded with user int.
	{
		mt64.seed(mtSeed);
	}
}

// private: return number functions.
int random::getRandNum(int min, int max)
{
	return ((double)rand() / RAND_MAX) * (max + 1 - min) + min; // review distribution algorithm.
}

unsigned int random::getRand_sNum(unsigned int min, unsigned int max)
{
	unsigned int num;
	errno_t err;
	err = rand_s(&num);
	if (err != 0)
	{
		std::cout << "rand_s failed with error: " << err << '\n';
	}
	else
	{
		return (unsigned int)((double)num / ((double)UINT_MAX + min) * (double)max + 1) + min; // review distribution algorithm.
	}
}

unsigned int random::getMt32Num(unsigned int min, unsigned int max)
{
	std::uniform_int_distribution<> dist(min, max);
	return dist(mt);
}

unsigned int random::getMt64Num(unsigned int min, unsigned int max)
{
	std::uniform_int_distribution<> dist(min, max);
	return dist(mt64);
}

// public: 
void random::setSeed(int prngType, int seed)
{
	switch (prngType)
	{
	case 0: // user seeded rand.
		this->seedRand(seed);
		break;
	case 1: // system time seeded rand.
		this->seedRandSYS();
		break;
	case 2: // placeholder, no seed for rand_s.
		break;
	case 3: // randon_device seeded 32-bit mersenne twister.
		this->initMt32(true, NULL);
		break;
	case 4: // user seeded 32-bit mersenne twister.
		this->initMt32(false, seed);
		break;
	case 5: // randon_device seeded 64-bit mersenne twister.
		this->initMt64(true, NULL);
		break;
	case 6: // user seeded 64-bit mersenne twister.
		this->initMt64(false, seed);
		break;
	}
}

unsigned int random::getNum(int prngType, unsigned int min, unsigned int max)
{
	switch (prngType)
	{
	case 0: // return number from user seeded rand.
		return this->getRandNum(min, max);
		break;
	case 1:  // return number from system time seeded rand.
		return this->getRandNum(min, max);
		break;
	case 2:  // return number from rand_s.
		return this->getRand_sNum(min, max);
		break;
	case 3:  // return number from randon_device seeded 32-bit mersenne twister.
		return this->getMt32Num(min, max);
		break;
	case 4:  // return number from user seeded 32-bit mersenne twister.
		return this->getMt32Num(min, max);
		break;
	case 5:  // return number from randon_device seeded 64-bit mersenne twister.
		return this->getMt64Num(min, max);
		break;
	case 6:  // return number from user seeded 64-bit mersenne twister.
		return this->getMt64Num(min, max);
		break;
	}
}