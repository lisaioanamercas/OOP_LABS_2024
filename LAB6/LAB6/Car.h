#pragma once
#include "Weather.h"
#include <iostream>
using namespace std;

class Car {
public:
	Car() {};
	virtual void GetName() = 0;
	double virtual GetFuelCapacity() = 0; //in L
	double virtual GetFuelConsumption() = 0; //in L/km
	virtual const float GetAverageSpeed(Weather) = 0; //in km/h
	double GetTime;
	virtual ~Car() {};
};
