#include "Game.h"

int Game::GetTotalUnitsLen()
{
	return TotalUnits.size();
}

float Game::GetCosBetweenVectors(Unit2DVector firstVector, Unit2DVector secondVector)
{
	return (firstVector * secondVector) / (firstVector.VectorSize() * secondVector.VectorSize());
}

int Game::GetNumberOfVisibleUnits(Unit* ViewerUnit)
{
	int UnitsNum = 0;
	for (int i = 0; i < TotalUnits.size(); i++)
	{
		if (TotalUnits[i] == ViewerUnit)
		{
			continue;
		}

		Unit2DVector BetweenUnits = TotalUnits[i]->GetLocation() - ViewerUnit->GetLocation();

		if (BetweenUnits.VectorSize() > ViewerUnit->VisionDistance)
		{
			continue;
		}

		float cosBetweenUnits = GetCosBetweenVectors(ViewerUnit->GetForwardVector(), BetweenUnits);
		if (cosBetweenUnits >= ViewerUnit->VisionZone / 2)
		{
			UnitsNum++;
			ViewerUnit->SetNumOfOtherUnits(UnitsNum);
		}

	}
	return ViewerUnit->GetNumOfOtherUnits();
}
void Game::WriteVisibleUnits(std::string path)
{
	std::ofstream out("Result.txt");
	if (out.is_open())
	{
		for (int i = 0; i < GetTotalUnitsLen(); i++)
		{
			out << GetNumberOfVisibleUnits(TotalUnits[i]) << std::endl;
		}
	}
	out.close();
}
Game::Game(std::string path)
{
	std::ifstream UnitsFile(path);
	std::string FileStr;
	while (getline(UnitsFile, FileStr, '\n'))
	{
		std::istringstream ist(FileStr, std::istringstream::in);
		std::string value;
		std::vector<float> LocAndDir;
		while (ist >> value)
		{
			LocAndDir.push_back(stof(value));
		}

		Unit* TempUnit = new Unit{ LocAndDir[0], LocAndDir[1], LocAndDir[2], LocAndDir[3] };

		TotalUnits.push_back(TempUnit);
	}
	UnitsFile.close();
}

Game::~Game()
{
	//удалять объекты из массива если они "умирают"
}