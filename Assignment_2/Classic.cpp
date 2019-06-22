#include <iostream>
#include "Classic.h"

using namespace std;

/**
The number of neighbors a particular element has in Classic mode
@param b Board being tested
@param i Row
@param j Column
@return int Number of neighbors
*/
int Classic::numNeighbors(Board b, int i, int j)
{
	int count = 0;
	for(int x = -1; x <= 1; x++)
	{
		for(int y = -1; y <= 1; y++)
		{
			int row = i + x;
			int col = j + y;
			if(row >= 0 && col >= 0 && row < b.getHeight() && col < b.getWidth())
			{
				if(b.getElement(row, col) == 'X')
				{
					count++;
				}
			}
		}
	}
	if(b.getElement(i, j) == 'X')
	{
		count--;
	}
	return count;
}
