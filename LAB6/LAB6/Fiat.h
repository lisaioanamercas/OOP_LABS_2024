#pragma once
#include "Car.h"
class Fiat : public Car
{
public:
	Fiat() {};
	virtual ~Fiat() override final {};


	virtual void GetName() override final;
	double virtual GetFuelCapacity() override final;
	double virtual GetFuelConsumption() override final;
	virtual const float GetAverageSpeed(Weather) override final;
};