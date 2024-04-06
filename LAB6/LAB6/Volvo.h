#pragma once
#include "Car.h"
class Volvo :public Car
{
public:
	Volvo() {};
	virtual ~Volvo() override final {};


	virtual void GetName() override final;
	double virtual GetFuelCapacity() override final;
	double virtual GetFuelConsumption() override final;
	virtual const float GetAverageSpeed(Weather) override final;
	double GetTime;
};

