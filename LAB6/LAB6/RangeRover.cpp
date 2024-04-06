#include "RangeRover.h"
#include <iostream>
using namespace std;

void RangeRover::GetName()
{
	cout << " RangeRover ";
}

double RangeRover::GetFuelCapacity()
{
	return 100;
}

double RangeRover::GetFuelConsumption()
{
	return 0.10;
}

const float RangeRover::GetAverageSpeed(Weather weather)
{
	if (weather == Weather::Rain)
		return 240;
	if (weather == Weather::Sunny)
		return 250;
	if (weather == Weather::Snow)
		return 230;

}




