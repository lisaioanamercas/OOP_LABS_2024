#include "NumberList.h"
#include <math.h>
#include <stdio.h>

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
    numbers[count] = x;
    count += 1;
    ///adauga x orice ar fi
	if (this->count >= 10)
		return false;
    return true;
}

void NumberList::Sort()
{
	///ok deci imi trebuie sortare pentru vectorul numbers -> insertion sort
    int i, key, j;
    for (i = 1; i < this->count; i++)
    {
        key = this->numbers[i];
        j = i - 1;

        while (j >= 0 && numbers[j] > key)
        {
            this->numbers[j + 1] = this->numbers[j];
            j = j - 1;
        }
        this->numbers[j + 1] = key;
    }
}

void NumberList::Print()
{
    int i;
    for (i = 0; i < this->count; i++)
        printf("%d ", this->numbers[i]);
    printf("\n");
}