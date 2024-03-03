// lab1_OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
using namespace std;
#define __STDC_WANT_LIB_EXT1__ 1 //?
char str[201];
int sum, x;






int main()
{
    errno_t error_code;
    FILE* file1;
    error_code = fopen_s(&file1, "in.txt", "r");
    if (error_code == 0)
    {
        if (fgets(str, 201, file1) != NULL)
        {
            size_t n = strlen(str);
            x = 0;
            for (int i = 0; i < n; i++)
                if (str[i] >= '0' and str[i] <= '9')
                    x = x * 10 + (str[i] - '0');
            sum += x;
        }
        fclose(file1);
    }
    else
        printf("Error! Failed to open file in r mode!");

    printf("%d \n", sum);
    return 0;
}