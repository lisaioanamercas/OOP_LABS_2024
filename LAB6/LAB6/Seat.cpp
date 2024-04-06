#include "Seat.h"
#include <iostream>
using namespace std;

void Seat::GetName()
{
	cout << " Seat ";
}

double Seat::GetFuelCapacity()
{
	return 40;
}

double Seat::GetFuelConsumption()
{
	return 0.05;
}

const float Seat::GetAverageSpeed(Weather weather)
{
	if (weather == Weather::Rain)
		return 170;
	if (weather == Weather::Sunny)
		return 200;
	if (weather == Weather::Snow)
		return 140;

}




