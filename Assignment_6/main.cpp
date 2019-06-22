#include <iostream>
#include <chrono>
#include "InputHandler.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"

using namespace std::chrono;

int main(int argc, char** argv)
{
	InputHandler* input;
	if(argc <= 1)
	{
		input = new InputHandler();
	}
	else
	{
		input = new InputHandler(argv[1]);
	}
	cout << endl;
	int size = input->size;
	int outputSize = 10;
	if(size < 10)
	{
		outputSize = size;
	}
	double arr[size];
	for(int x = 0; x < size; x++)
	{
		arr[x] = input->array[x];
	}
	cout << "Original: ";
	for(int x = 0; x < outputSize; x++)
	{
		cout << arr[x] << " ";
	}
	cout << endl;
	BubbleSort b1;
	auto start = high_resolution_clock::now();
  b1.sort(arr, size);
  auto finish = high_resolution_clock::now();
	auto elapsed = duration_cast<milliseconds>(finish - start);
	cout << "Bubble Sort (" << elapsed.count() << " milliseconds): ";
	for(int x = 0; x < outputSize; x++)
	{
		cout << arr[x] << " ";
	}
	cout << endl;
	SelectionSort s1;
	for(int x = 0; x < size; x++)
	{
		arr[x] = input->array[x];
	}
	start = high_resolution_clock::now();
	s1.sort(arr, size);
	finish = high_resolution_clock::now();
	elapsed = duration_cast<milliseconds>(finish - start);
	cout << "Selection Sort (" << elapsed.count() << " milliseconds): ";
	for(int x = 0; x < outputSize; x++)
	{
		cout << arr[x] << " ";
	}
	cout << endl;
	InsertionSort i1;
	for(int x = 0; x < size; x++)
	{
		arr[x] = input->array[x];
	}
	start = high_resolution_clock::now();
  i1.sort(arr, size);
  finish = high_resolution_clock::now();
	elapsed = duration_cast<milliseconds>(finish - start);
	cout << "Insertion Sort (" << elapsed.count() << " milliseconds): ";
	for(int x = 0; x < outputSize; x++)
	{
		cout << arr[x] << " ";
	}
	cout << endl;
	QuickSort q1;
	for(int x = 0; x < size; x++)
	{
		arr[x] = input->array[x];
	}
	start = high_resolution_clock::now();
	q1.sort(arr, 0, size - 1);
	finish = high_resolution_clock::now();
	elapsed = duration_cast<milliseconds>(finish - start);
	cout << "Quick Sort (" << elapsed.count() << " milliseconds): ";
	for(int x = 0; x < outputSize; x++)
	{
		cout << arr[x] << " ";
	}
	cout << endl << endl;
	delete input;
}
