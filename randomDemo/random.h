#pragma once
#define _CRT_RAND_S
#include <iostream>
#include <stdlib.h>
#include <random>

class random
{
	// prngType 0: User-seeded rand.
	// prngType 1: System-time seeded rand.
	// prngType 2: rand_s.
	// prngType 3: Random_device-seeded 32-bit Mersenne Twister.
	// prngType 4: User-seeded 32-bit Mersenne Twister.
	// prngType 5: Random_device-seeded 64-bit Mersenne Twister.
	// prngType 6: User-seeded 64-bit Mersenne twiTwisterster.
private:
	std::mt19937 mt;
	std::mt19937_64 mt64;

	// Seed functions.
	void seedRand(int randSeed);
	void seedRandSYS();
	void initMt32(bool rdSeed, int mtSeed);
	void initMt64(bool rdSeed, int mtSeed);

	// Return number functions.
	int getRandNum(int min, int max);
	unsigned int getRand_sNum(unsigned int min, unsigned int max);
	unsigned int getMt32Num(unsigned int min, unsigned int max);
	unsigned int getMt64Num(unsigned int min, unsigned int max);
public:
	void setSeed(int prngType, int seed);
	unsigned int getNum(int prngType, unsigned int min, unsigned int max);
};