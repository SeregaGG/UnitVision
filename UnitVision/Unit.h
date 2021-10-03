#pragma once
#include "Vector2D.h"
class Unit
{
public:
	Unit(float LocationX, float LocationY, float DirectionX, float DirectionY);
	Unit(Unit2DVector Location, Unit2DVector Direction);
	~Unit();



	Unit2DVector GetLocation();
	Unit2DVector GetForwardVector();

	int GetNumOfOtherUnits();
	void SetNumOfOtherUnits(int num);

	float VisionZone = 135.5 / 180;
	float VisionDistance = 2;

private:
	int NumberOfOtherUnits = 0;
	Unit2DVector Location;
	Unit2DVector Direction;
};
