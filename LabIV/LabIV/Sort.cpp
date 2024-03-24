#include "Sort.h"
#include <random>
#include <algorithm>
#include <varargs.h>

Sort::Sort(int count, int mini, int maxi)
{
	srand(time(NULL));
	this->elements = new int[count];
	this->lg = count;
	for (int i = 0; i < count; i++)
	{
		int number = rand() % maxi + mini;///aici ne asiguram intervalul [mini, maxi]
		this->elements[i] = number;
	}
} ///cu random

Sort::Sort(int* vectorash, int lung)
{
	/*this->elements = vectorash;*/ ///romaneasca

	this->elements = new int[lung];
	for (int i = 0; i < lung; i++)
	{
		elements[i] = vectorash[i];
	}
	this->lg = lung;///retinem lungimea in variabile din clasa
} ///from an existing vector

Sort::Sort(int count, ...)
{
	this->elements = new int[count];
	this->lg = count;

	int valoare;
	
	va_list vectorel;
	va_start(vectorel, (count));
	va_arg(vectorel, int);///romaneasca -> ia primul element de dupa count!!!
	for (int i = 0; i < count; i++)
	{
		valoare = va_arg(vectorel, int);
		this->elements[i] = valoare;
	}
	va_end(vectorel);
}///from variadic parameters

Sort::Sort(const char* lista)
{
	int nr=0, index = 1;///index e pentru elements
	for (int i = 0; lista[i] != '\0'; i++) {
		if (lista[i] == ',')
			index++;
	}
	this->lg = index;
	this->elements = new int[index];///alocam mem

	for (int i = 0; lista[i] != '\0'; i++) {
		if (lista[i] != ',')
			nr = nr * 10 + Atoi(lista[i]);
		else
		{
			this->elements[--index] = nr; ///o sa mi le puna in ordine inversa dar aia e
			nr = 0;
		}
	}
	this->elements[--index] = nr;
}

void Sort::InsertSort(bool ascendent)
{
	int i, key, j;
	for (i = 1; i < this->lg; i++) {
		key = this->elements[i];
		j = i - 1;
		while (j >= 0 && this->elements[j] > key) {
			this->elements[j + 1] = this->elements[j];
			j = j - 1;
		}
		this->elements[j + 1] = key;
	}
	if (ascendent == false)//daca nu imi cere sortare cresc
	{
		for (int i = 0; i < this->lg / 2; i++)
		{
			std::swap(this->elements[i], this->elements[this->lg - 1 - i]);
		}
	}
}

void Sort::QuickSort(bool ascendent, int low, int high)
{
	if (low < high)
	{
		int pi = partition(ascendent, low, high);
		QuickSort(ascendent, low, pi - 1);
		QuickSort(ascendent, pi + 1, high);
	}
}

void Sort::BubbleSort(bool ascendent)
{
	int i, j;
	bool swapped;
	for (i = 0; i < this->lg - 1; i++) 
	{
		swapped = false;
		for (j = 0; j < this->lg - i - 1; j++) 
		{
			if (this->elements[j] > this->elements[j + 1]) 
			{
				std::swap(this->elements[j], this->elements[j + 1]);
				swapped = true;
			}
		}
		// If no two elements were swapped
		// by inner loop, then break
		if (swapped == false)
			break;
	
	}
	if(ascendent==false)//daca nu imi cere sortare cresc
	{
		for (int i = 0; i < this->lg / 2; i++)
		{
			std::swap(this->elements[i], this->elements[this->lg - 1 - i]);
		}
	}
}

void Sort::Print()
{
	for (int i = 0; i < this->lg; i++){
		printf("%d ", this->elements[i]);
	}
	printf("\n");
}

int Sort::GetElementsCount()
{
	return this->lg;
}

int Sort::GetElementFromIndex(int index)
{
	if (index < 0 or index >= lg)
		return -1;
	return this->elements[index];
}
