#include <stdio.h>
#include <stdlib.h>

/**
 * grid_addition - void grid_addition
 * @grid1: int grid1[3][3]
 * @grid2: int grid2[3][3]
*/

void grid_addition(int grid1[3][3], int grid2[3][3])
{
int x, j;
for (x = 0; x < 3; x++)
{
for (j = 0; j < 3; j++)
{
grid1[x][j] = grid1[x][j] + grid2[x][j];
}
}
}

/**
 * grid_print - print a grid
 * @grid: int grid[3][3]
*/
void grid_print(int grid[3][3])
{
int x = 0;
int j = 0;
printf("=\n");
for (x = 0; x < 3; x++)
{
for (j = 0; j < 3; j++)
{
if (j)
printf(" ");
printf("%d", grid[x][j]);
}
printf("\n");
}
}

/**
 * grid_is_ok - int grid_is_ok
 * @grid: int grid[3][3]
 * Return: 1 or 0
 */

int grid_is_ok(int grid[3][3])
{
int x = 0;
int j = 0;
for (x = 0; x < 3; x++)
{
for (j = 0; j < 3; j++)
{
if (grid[x][j] > 3)
return (0);
}
}
return (1);
}

/**
 * grid_change - change a grid value
 * @grid1: int grid[3][3]
*/

void grid_change(int grid1[3][3])
{
int x = 0;
int j = 0;
int gridx[3][3];
for (x = 0; x < 3; x++)
{
for (j = 0; j < 3; j++)
gridx[x][j] = 0;
}
for (x = 0; x < 3; x++)
{
	for (j = 0; j < 3; j++)
	{
		if (grid1[x][j] > 3)
		{
			grid1[x][j] = grid1[x][j] - 4;
			if ((x - 1) >= 0 && (x - 1) < 3)
				gridx[x - 1][j] += 1;
			if ((j - 1) >= 0 && (j - 1) < 3)
				gridx[x][j - 1] += 1;
			if ((x + 1) >= 0 && (x + 1) < 3)
				gridx[x + 1][j] += 1;
			if ((j + 1) >= 0 && (j + 1) < 3)
				gridx[x][j + 1] += 1;
		}
	}
}
	grid_addition(grid1, gridx);
}

/**
 * sandpiles_sum - void sandpiles_sum
 * @grid1: int grid1[3][3]
 * @grid2: int grid2[3][3]
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
grid_addition(grid1, grid2);
while (!grid_is_ok(grid1))
{
grid_print(grid1);
grid_change(grid1);
}
}
