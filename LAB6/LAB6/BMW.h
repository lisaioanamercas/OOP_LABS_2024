#pragma once
#include "Car.h"
class BMW:public Car
{
public:
	BMW() {};
	virtual ~BMW() override final {};


	virtual void GetName() override final;
	double virtual GetFuelCapacity() override final;
	double virtual GetFuelConsumption() override final;
	virtual const float GetAverageSpeed(Weather) override final;
	double GetTime;
};

