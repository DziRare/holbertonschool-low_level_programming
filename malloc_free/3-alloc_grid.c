#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * alloc_grid - Returns a pointer to a 2 dimensional array of integers
 * @width: Width of grid
 * @height: Length of grid
 *
 * Return: Pointer to grid or NULL
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int col;
	int row;
	int i;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(height * sizeof(int));
	if (grid == NULL)
		return (NULL);
	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(width * sizeof(int));
		if (grid[i] == NULL)
			return (NULL);
	}

	for (col = 0; col < height; col++)
	{
		for (row = 0; row < width; row++)
			grid[col][row] = 0;
	}

	return (grid);
}
