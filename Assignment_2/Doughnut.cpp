#include <iostream>
#include "Doughnut.h"

using namespace std;

/**
The number of neighbors a particular element has in Doughnut mode
@param b Board being tested
@param i Row
@param j Column
@return int Number of neighbors
*/
int Doughnut::numNeighbors(Board b, int i, int j)
{
	int count = 0;
	int row = 0;
	int col = 0;
	for(int x = -1; x <= 1; x++)
	{
		for(int y = -1; y <= 1; y++)
		{
			row = i + x;
			col = j + y;
			if(row == -1)
			{
				row = b.getHeight() - 1;
			}
			else if(row == b.getHeight())
			{
				row = 0;
			}
			if(col == -1)
			{
				col = b.getWidth() - 1;
			}
			else if(col == b.getWidth())
			{
				col = 0;
			}
			if(b.getElement(row, col) == 'X')
			{
				count++;
			}
		}
	}
	if(b.getElement(i, j) == 'X')
	{
		count--;
	}
	return count;
}
