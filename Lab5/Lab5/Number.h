#pragma once
#include <algorithm>
using namespace std;

class Number
{
private:
	int NrCif, baza;
	char* valoare = new char[100];

	int ToBaza10()
	{
		int putere = 0;
		int rezultat = 0;
		for (int i = this->NrCif - 1; i >= 0; i--)
		{
			int ValCif;
			if (this->valoare[i] >= '0' and this->valoare[i] <= '9')
				ValCif = this->valoare[i] - '0';
			else
				ValCif = this->valoare[i] - 'A' + 10;
			rezultat += ValCif * pow(this->baza, putere);
			putere++;
		}
		this->baza = 10;//actualizam baza numarului curent!
		return rezultat;
	}

	void DinBaza10(int numar, int baza)
	{
		char* nou = new char[100];
		int index = 0;
		while (numar)
		{
			int rest = numar % baza;
			if (rest < 10)
				nou[index] = rest + '0';
			else
				nou[index] = 'A' + (rest - 10);
			index++;
			numar /= baza;
		}
		nou[index] = '\0';
		char* rezultat = new char[100];
		for (int i = index-1, j=0;i >= 0; i--, j++)
			rezultat[j] = nou[i];
		rezultat[index] = '\0';
		this->valoare = rezultat;
		this->baza = baza;
		this->NrCif = index;
	}

public:
	///////////////////////////////CONSTRUCTORI/DESTRUCTORI///////////////////////////////////////

	Number(const char* val, int baza); // 2<=baza<=16
	Number(int a); // constructor pentru int
	~Number();///destructor
	Number(Number& y);///copy cons
	Number(Number&& y);///move cons

	////////////////////////////////////////OPERATORI////////////////////////////////////////////
	friend Number operator+ (Number a, Number b);
	friend Number operator- (Number a, Number b);
	void operator+= (Number a);
	void operator= (Number a);
	void operator= (int a);
	void operator= (const char* a);
	void operator-- (int a);
	void operator-- ();
	bool operator> (Number a);
	bool operator< (Number a);
	bool operator<= (Number a);
	bool operator>= (Number a);
	bool operator== (Number a);
	char operator[](int index);


	////////////////////////////////////ALTELE////////////////////////////////////////////////////
	void SwitchBase(int NouaBaza);
	void Print();
	int  GetDigitsCount();
	int  GetBase();
};