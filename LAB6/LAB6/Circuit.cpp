#include "Circuit.h"
using namespace std;

/// ////////////////////////////////////////////////////CONSTRUCTORI + DESTRUCTORI/////////////////////////////////////
Circuit::Circuit()
{
	this->NumberOfCars = 0;
	this->lenght = 0;
}

Circuit::~Circuit()
{
	for (int i = 0; i < this->NumberOfCars; i++)
		delete this->cars[i];
}

/////////////////////////////////////////////////////////LUNGIME+VREME+ADD_CAR/////////////////////////////////////////////////
void Circuit::SetLength(const int lg)
{
	lenght = lg;
}

void Circuit::SetWeather(const Weather vreme)
{
	weather = vreme;
}

void Circuit::AddCar(Car* masina)
{
	cars[NumberOfCars++] = masina;
}

void Circuit::Race()
{
	for (int i = 0; i < this->NumberOfCars; i++)
	{
		if (cars[i]->GetAverageSpeed(weather) * (cars[i]->GetFuelCapacity() / cars[i]->GetFuelConsumption() >= lenght))
			cars[i]->GetTime = lenght / cars[i]->GetAverageSpeed(weather);
		else
			cars[i]->GetTime = -1.0f;
	}
}

void Circuit::ShowFinalRanks()
{
	Car* aux;
	bool ok;

	do
	{
		ok = true;
		for(int i=0; i<NumberOfCars-1; i++)
			if (cars[i]->GetTime > cars[i + 1]->GetTime)
			{
				aux = cars[i];
				cars[i] = cars[i + 1];
				cars[i + 1] = aux;
				ok = false;
			}
	} while (!ok);

	cout << "FINAL RANKS: " << endl;
	int rank = 1;
	for(int i=0; i<NumberOfCars; i++)
		if (cars[i]->GetTime != -1.0f)
		{
			if (rank == 1)
				cout << "On " << rank << "st place we have:";
			if (rank == 2)
				cout << "On " << rank << "nd place we have:";
			if (rank == 3)
				cout << "On " << rank << "rd place we have:";
			if(rank >=4)
				cout << "On " << rank << "th place we have:";
			cars[i]->GetName();
			cout << "with the score of: ";
			cout << " " << cars[i]->GetTime << " seconds" << endl;
			rank++;
		}
	cout << endl;
}

void Circuit::ShowWhoDidNotFinish()
{
	bool everybody = true;
	for(int i=0; i<NumberOfCars; i++)
		if (cars[i]->GetTime == -1.0f)
		{
			everybody = false;
			break;
		}
	if (everybody)
		cout << "EVERYBODY FINISHED THE RACE!!!!!" << endl;
	else
	{
		cout << "CARS WHO DID NOT FINISH THE RACE: " << endl;
		for (int i = 0; i < NumberOfCars; i++)
			if (cars[i]->GetTime == -1.0f)
			{
				cars[i]->GetName();
				cout << '\n' << endl;
			}
	}
	cout << endl;
}

