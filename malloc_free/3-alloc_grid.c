#include "main.h"
#include <stdlib.h>

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

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(height * sizeof(int *));
	if (grid == NULL)
	{
		free(grid);
		return (NULL);
	}
	for (col = 0; col < height; col++)
	{
		grid[col] = malloc(width * sizeof(int));
		if (grid[col] == NULL)
		{
			while (col >= 0)
				free(grid[col]);
				col--;
			return (NULL);
		}

		for (row = 0; row < width; row++)
			grid[col][row] = 0;
	}

	return (grid);
}
