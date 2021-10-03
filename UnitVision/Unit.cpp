#include "Unit.h"


Unit::Unit(float LocationX, float LocationY, float DirectionX, float DirectionY)
{
	Location.x = LocationX;
	Location.y = LocationY;

	Direction.x = DirectionX;
	Direction.y = DirectionY;

}

Unit::Unit(Unit2DVector Location, Unit2DVector Direction)
{
	this->Location = Location;
	this->Direction = Direction;
}


Unit::~Unit()
{

}

Unit2DVector Unit::GetForwardVector()
{
	return Direction;
}

Unit2DVector Unit::GetLocation()
{
	return Location;
}

int Unit::GetNumOfOtherUnits()
{
	return NumberOfOtherUnits;
}

void Unit::SetNumOfOtherUnits(int num)
{
	NumberOfOtherUnits = num;
}