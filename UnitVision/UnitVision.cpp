#include "Game.h"

int main()
{
	std::string PathToUnits("Units.txt");
	std::string NumOfVisibleUnits("Result.txt");
	Game MyGame(PathToUnits);
	MyGame.WriteVisibleUnits(NumOfVisibleUnits);
}

