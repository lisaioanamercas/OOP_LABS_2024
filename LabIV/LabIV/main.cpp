#include <iostream>
#include "Sort.h"

int main()
{
	Sort* a = new Sort(6, 25, 60);///cu random
	Sort* b = new Sort(new int[7] {8, 7, 9, 1, 2, 3, 1}, 7);///from an existing vector
	Sort* c = new Sort();//from initialization list
	Sort* d = new Sort(5, 6, 7, 8, 1, 2);
	Sort* e = new Sort("10,1,5,4,6,3");

	e->Print();
	e->QuickSort(false, 0, e->GetElementsCount()-1);
	e->Print();

	return 0;
}