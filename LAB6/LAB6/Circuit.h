#pragma once
#include "Car.h"
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"
#include "Weather.h"

class Circuit {
private:
	int lenght;
	Car* cars[100];
	int NumberOfCars;
	Weather weather;
public:
	Circuit();
	~Circuit();
	void SetLength(const int);
	void SetWeather(const Weather);
	void AddCar(Car*);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};