#include <iostream>
#include "Mirror.h"

using namespace std;

/**
The number of neighbors a particular element has in Mirror mode
@param b Board being tested
@param i Row
@param j Column
@return int Number of neighbors
*/
int Mirror::numNeighbors(Board b, int i, int j)
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
					if((i == 0 && row == 0) || (j == 0 && col == 0) || (i == b.getHeight() - 1 && row == b.getHeight() - 1) || (j == b.getWidth() - 1 && col == b.getWidth() - 1))
					{
						count++;
					}
				}
			}
		}
	}
	if((b.getElement(i, j) == 'X') && ((i == 0 || i == b.getHeight() - 1) && (j == 0 || j == b.getWidth() - 1)))
	{
		count += 3;
	}
	else if((b.getElement(i, j) == 'X') && (i == 0 || i == b.getHeight() - 1 || j == 0 || j == b.getWidth() - 1))
	{
		count++;
	}
	if(b.getElement(i, j) == 'X')
	{
		count--;
		if(i == 0 || j == 0 || i == b.getHeight() - 1 || j == b.getWidth() - 1)
		{
			count--;
		}
	}
	return count;
}
