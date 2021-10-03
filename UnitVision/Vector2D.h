#pragma once
#include <math.h>
struct Unit2DVector
{
	float x;
	float y;

	Unit2DVector operator-(Unit2DVector secondUnit)
	{
		return Unit2DVector{ this->x - secondUnit.x, this->y - secondUnit.y };
	};

	float operator*(Unit2DVector secondUnit)
	{
		return this->x * secondUnit.x + this->y * secondUnit.y;
	};

	float VectorSize();
};
