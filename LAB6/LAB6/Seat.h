#pragma once
#include "Car.h"
class Seat :public Car
{
public:
	Seat() {};
	virtual ~Seat() override final {};


	virtual void GetName() override final;
	double virtual GetFuelCapacity() override final;
	double virtual GetFuelConsumption() override final;
	virtual const float GetAverageSpeed(Weather) override final;
	double GetTime;
};


