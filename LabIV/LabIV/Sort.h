#pragma once
#include <algorithm>

class Sort
{
private:
    int* elements;
    int lg;

    int Atoi(char c)
    {
        int x = 0;
        if (c >= '0' and c <= '9')
            x = (c - '0');
        return x;
    }

    int partition(bool ascendent, int low, int high)
    {
        int pivot = this->elements[high];
        int i = (low - 1);

        for (int j = low; j <= high; j++)
        {
            if(ascendent==true)
            {
                if (this->elements[j] < pivot)
                {
                    i++;
                    std::swap(this->elements[i], this->elements[j]);
                }
            }
            else
            {
                if (this->elements[j] > pivot)
                {
                    i++;
                    std::swap(this->elements[i], this->elements[j]);
                }
            }
        }
        std::swap(this->elements[i + 1], this->elements[high]);
        return (i + 1);
    }

public:
    Sort(int, int, int);
    Sort() : elements(new int[8] { 1, 3, 5, 2, 9, 4, 1, 6 }) {
        this->lg = 8;
    };///initialization list :)
    Sort(int*, int);
    Sort(int, ...);
    Sort(const char*);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent, int low, int high);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};


