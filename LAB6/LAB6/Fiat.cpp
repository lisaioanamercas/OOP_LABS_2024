#include "Fiat.h"
#include <iostream>
using namespace std;

void Fiat::GetName()
{
	cout << " Fiat ";
}

double Fiat::GetFuelCapacity()
{
	return 60;
}

double Fiat::GetFuelConsumption()
{
	return 0.05;
}

const float Fiat::GetAverageSpeed(Weather weather)
{
	if (weather == Weather::Rain)
		return 110;
	if (weather == Weather::Sunny)
		return 130;
	if (weather == Weather::Snow)
		return 90;
}