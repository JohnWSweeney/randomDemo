#pragma once
#include <iostream>
#include <string>
#include <vector>

struct results
{
	std::vector<int> unseededData;
	std::vector<int> seededData;
	std::vector<int> seedSysTimeData;
};

void unseededRand(std::vector<int> &unseededData);
void seededRand(int seed, std::vector<int> &seededData);
void basic(int seed, int n);