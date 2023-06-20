#pragma once
#include <iostream>
#include <string>
#include <vector>

extern int defaultPRNG;

void prngQuery();
void prngStatus(std::vector<std::string> &tokens);