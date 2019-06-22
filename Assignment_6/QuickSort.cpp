#include <iostream>
#include "QuickSort.h"

void QuickSort::sort(double* arr, int low, int high)
{
	if (low < high)
  {
		double pivot = arr[high];
    int index = (low - 1);
		double temp = 0;
    for (int i = low; i < high; i++)
    {
        if (arr[i] <= pivot)
        {
            index++;
						swap(arr, index, i);
        }
    }
		index++;
		swap(arr, index, high);
		sort(arr, low, index - 1);
		sort(arr, index + 1, high);
  }
}

void QuickSort::swap(double* arr, int a, int b)
{
  double temp;
  temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;

}
