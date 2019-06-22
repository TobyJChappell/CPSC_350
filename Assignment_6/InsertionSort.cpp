#include <iostream>
#include "InsertionSort.h"

void InsertionSort::sort(double* arr, int size)
{
	for(int i = 1; i < size; i++)
	{
		double temp = arr[i];
		int j = i;
		while(j > 0 && arr[j - 1] >= temp)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = temp;
	}
}
