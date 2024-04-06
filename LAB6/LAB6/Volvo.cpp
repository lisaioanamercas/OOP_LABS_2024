#include "Volvo.h"
#include <iostream>
using namespace std;

void Volvo::GetName()
{
	cout << " Volvo ";
}

double Volvo::GetFuelCapacity()
{
	return 60;
}

double Volvo::GetFuelConsumption()
{
	return 0.12;
}

const float Volvo::GetAverageSpeed(Weather weather)
{
	if (weather == Weather::Rain)
		return 160;
	if (weather == Weather::Sunny)
		return 200;
	if (weather == Weather::Snow)
		return 140;

}




