#include "BMW.h"
#include <iostream>
using namespace std;

void BMW::GetName()
{
	cout << " BMW ";
}

double BMW::GetFuelCapacity()
{
	return 87;
}

double BMW::GetFuelConsumption()
{
	return 0.05;
}

const float BMW::GetAverageSpeed(Weather weather)
{
	if (weather == Weather::Rain)
		return 170;
	if (weather == Weather::Sunny)
		return 200;
	if (weather == Weather::Snow)
		return 150;

}




