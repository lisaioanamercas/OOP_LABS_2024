#pragma once
#include "Car.h"
class RangeRover : public Car
{
public:
	RangeRover() {};
	virtual ~RangeRover() override final {};

	virtual void GetName() override final;
	double virtual GetFuelCapacity() override final;
	double virtual GetFuelConsumption() override final;
	virtual const float GetAverageSpeed(Weather) override final;
};