#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "Unit.h"

class Game
{
public:
	Game(std::string path);
	~Game();

	void WriteVisibleUnits(std::string path);
	int GetNumberOfVisibleUnits(Unit* ViewerUnit);
	float GetCosBetweenVectors(Unit2DVector firstVector, Unit2DVector secondVector);
	int GetTotalUnitsLen();
private:
	std::vector<Unit*> TotalUnits;
};

