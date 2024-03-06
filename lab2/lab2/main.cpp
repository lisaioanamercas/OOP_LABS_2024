#include "first_class.h"
#include "global.h"
#include "NumberList.h"
#include <stdio.h>

using namespace std;

int main()
{
	//first_class clasa1;
	//clasa1.SetX(25);
	//printf("Valoarea lui x in clasa mea este: %d\n", clasa1.GetX());
	//printf("Val. modificata a lui x este: %d\n", clasa1.GetXModified());
	//first_class clasa2;
	//clasa2.SetX(30);
	//printf("val lui compareByX hihihaha: %d\n", CompareByX(&clasa1, &clasa2));

	NumberList clasa1;
	clasa1.Init();
	clasa1.Add(5);
	clasa1.Add(2);
	clasa1.Add(3);
	clasa1.Add(1);
	clasa1.Add(7);
	printf("elementele vectorului nesortat sunt urmatoarele: ");
	clasa1.Print();
	printf("\n\n");
	printf("elementele vectorului sortat sunt urmatoarele: ");
	clasa1.Sort();
	clasa1.Print();
	return 0;
}