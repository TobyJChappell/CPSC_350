#include <iostream>
#include "BubbleSort.h"

void BubbleSort::sort(double* arr, int size)
{
	for(int i = 0; i < size - 1; i++)
	{
		double temp = 0;
		for(int j = 0; j < size - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
