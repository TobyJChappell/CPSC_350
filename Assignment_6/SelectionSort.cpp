#include <iostream>
#include "SelectionSort.h"

void SelectionSort::sort(double* arr, int size)
{
	for(int i = 0; i < size - 1; i++)
	{
		int min = i;
		for(int j = i + 1; j < size; j++)
		{
			if(arr[min]  > arr[j])
			{
				min = j;
			}
		}
		double temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}
