#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <string>

void startBasicThread(std::vector<std::string> &tokens);
void startBasicSeedThread(std::vector<std::string> &tokens);
void startCoinFlipStreakThread(std::vector<std::string> &tokens);
void startDiceRollMatchThread(std::vector<std::string> &tokens);