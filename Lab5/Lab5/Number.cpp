#include "Number.h"
#include <cstring>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

///////////////////////////////CONSTRUCTORI/DESTRUCTORI///////////////////////////////////////

Number::Number(const char* val, int baza)
{
	this->NrCif = strlen(val);
	this->baza = baza;
	int i = 0;
	for (i = 0; val[i] != NULL; i++)
	{
		this->valoare[i] = val[i];
	}
	this->valoare[i] = NULL;
}

Number::Number(int a) 
{
	this->baza = 10;;
	
	int copie = a, nr=0;
	while (copie)
		copie /= 10, nr++;
	
	this->NrCif = nr;
	for (int i = nr-1; i >= 0; i--)
	{
		this->valoare[i] = a%10 + '0';
		a /= 10;
	}
	this->valoare[nr] = NULL;
}

Number::~Number()
{
	delete[] this->valoare;
}

Number::Number(Number& y)
{
	this->baza = y.baza;
	this->NrCif = y.NrCif;
	delete[] this->valoare;
	this->valoare = new char[100];
	for (int i = 0; i < NrCif; i++)
		this->valoare[i] = y.valoare[i];
}

Number::Number(Number&& y)
{
	this->baza = y.baza;
	delete[] this->valoare;
	this->valoare = y.valoare;
	this->NrCif = y.NrCif;
}

////////////////////////////////////////OPERATORI////////////////////////////////////////////

Number operator+(Number a, Number b)
{
	int baza = max(a.baza, b.baza);

	int nr1 = a.ToBaza10();
	//printf("%d\n", nr1);
	int nr2 = b.ToBaza10();
	//printf("%s %d\n", "nr2: ", nr2);
	int rez = nr1 + nr2;
	//printf("%s %d\n", "rez este: ", rez);

	Number rezultatFinal("1", baza);
	rezultatFinal.DinBaza10(rez, baza);
	return rezultatFinal;
}

Number operator-(Number a, Number b)
{
	int baza = max(a.baza, b.baza);
	int nr1 = a.ToBaza10();
	int nr2 = b.ToBaza10();
	int rez = nr1 - nr2;

	Number rezultatFinal("1", baza);
	rezultatFinal.DinBaza10(rez, baza);
	return rezultatFinal;
}

char Number::operator[](int index)
{
	return this->valoare[index];
}

/// -- pre
void Number::operator--(int a)
{
	this->valoare[this->NrCif - 1] = '\0';
	this->NrCif--;
}

/// -- post
void Number::operator--()
{
	for (int i = 0; i < this->NrCif - 1; i++)
		this->valoare[i] = this->valoare[i + 1];
	this->valoare[this->NrCif - 1] = '\0';
	this->NrCif--;
}

bool Number::operator>(Number a)
{
	if (this->baza < a.baza)
		this->SwitchBase(a.baza);
	else
		a.SwitchBase(this->baza);

	int lg1 = this->NrCif;
	int lg2 = a.NrCif;

	if (lg1 > lg2)
	{
		return true;
	}
	else if (lg1 < lg2)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < lg1; i++)
		{
			if (this->valoare[i] > a[i])
				return true;
			else
				if (this->valoare[i] < a[i])
					return false;
		}
	}
	return false;
}

bool Number::operator>=(Number a)
{
	if (this->baza < a.baza)
		this->SwitchBase(a.baza);
	else
		a.SwitchBase(this->baza);

	int lg1 = this->NrCif;
	int lg2 = a.NrCif;

	if (lg1 > lg2)
	{
		return true;
	}
	else if (lg1 < lg2)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < lg1; i++)
		{
			if (this->valoare[i] > a[i])
				return true;
			else
				if (this->valoare[i] < a[i])
					return false;
		}
	}
	return true;
}

bool Number::operator<(Number a)
{
	if (this->baza < a.baza)
		this->SwitchBase(a.baza);
	else
		a.SwitchBase(this->baza);

	int lg1 = this->NrCif;
	int lg2 = a.NrCif;

	if (lg1 < lg2)
	{
		return true;
	}
	else if (lg1 > lg2)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < lg1; i++)
		{
			if (this->valoare[i] < a[i])
				return true;
			else
				if (this->valoare[i] > a[i])
					return false;
		}
	}
	return false;
}

bool Number::operator<=(Number a)
{
	if (this->baza < a.baza)
		this->SwitchBase(a.baza);
	else
		a.SwitchBase(this->baza);

	int lg1 = this->NrCif;
	int lg2 = a.NrCif;

	if (lg1 < lg2)
	{
		return true;
	}
	else if (lg1 > lg2)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < lg1; i++)
		{
			if (this->valoare[i] < a[i])
				return true;
			else
				if (this->valoare[i] > a[i])
					return false;
		}
	}
	return true;
}

bool Number::operator==(Number a)
{
	if (this->baza < a.baza)
		this->SwitchBase(a.baza);
	else
		a.SwitchBase(this->baza);

	int lg1 = this->NrCif;
	int lg2 = a.NrCif;

	if (lg1 != lg2)
		return false;
	else
	{
		for (int i = 0; i < lg1; i++)
		{
			if (this->valoare[i] != a[i])
				return false;
			else
				return true;
		}
		return false;
	}
}

void Number::operator+=(Number a)
{
	int baza = max(this->baza, a.baza);

	int nr1 = this->ToBaza10();
	//printf("%d\n", nr1);
	int nr2 = a.ToBaza10();
	//printf("%s %d\n", "nr2: ", nr2);
	int rez = nr1 + nr2;
	//printf("%s %d\n", "rez este: ", rez);

	this->DinBaza10(rez, baza);
}

/// = pentru Number
void Number::operator=(Number a)
{
	this->baza = a.baza;
	this->NrCif = a.NrCif;
	delete[] this->valoare;
	this->valoare = new char[100];
	for (int i = 0; i <= NrCif; i++)
	{
		this->valoare[i] = a.valoare[i];
		//printf("%c", this->valoare[i]);
	}
}

/// = pentru int
void Number::operator=(int a)
{
	//delete[] this->valoare;
	int baza = this->baza;
	this->SwitchBase(10);

	int copie = a, nr=0;
	while (copie)
		copie /= 10, nr++;

	this->NrCif = nr;
	for (int i = nr-1; i >= 0; i--)
	{
		this->valoare[i] = a%10 + '0';
		a /= 10;
	}
	this->SwitchBase(baza);
}

/// = pentru char
void Number::operator=(const char* a)
{
	//delete[] this->valoare;
	int baza = this->baza;
	this->SwitchBase(10);

	int nr = 0;
	for (int i = 0; a[i] != NULL; i++)
		nr++;
	this->NrCif = nr;
	
	for (int i = 0; i < nr; i++)
		this->valoare[i] = a[i];
	this->SwitchBase(baza);
}


////////////////////////////////////ALTELE///////////////////////////////////////////////////

void Number::SwitchBase(int NouaBaza)
{
	int rezultat = 0;
	rezultat = this->ToBaza10();
	this->DinBaza10(rezultat, NouaBaza);
}

void Number::Print()
{
	printf("%s\n", this->valoare);
}

int Number::GetDigitsCount()
{
	return this->NrCif;
}

int Number::GetBase()
{
	return this->baza;
}