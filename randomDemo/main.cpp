#include "start.h"

int main()
{
	std::cout << "randomDemo v1.0.0\n\n";
	bool running = true;
	std::vector<std::string> tokens;
	while (running)
	{
		getInput(tokens);
		startMenu(running, tokens);
	}
}