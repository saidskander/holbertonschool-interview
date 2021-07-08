
#include "menger.h"

/**
 * menger - void menger
 * @step: int step
 */
void menger(int step)
{
int column, row, size;
char rizar;
size = pow(3, step);
for (row = 0; row < size; ++row)
{
for (column = 0; column < size; ++column)
{
rizar = menger_char(row, column);
printf("%c", rizar);
}
putchar(10);
}
}

/**
 * menger_char - char menger_char
 * @column: int column
 * @row: int row
 * Return: char
 */
char menger_char(int column, int row)
{
while (row || column)
{
if (row % 3 == 1 && column % 3 == 1)
return (' ');
row = row / 3;
column = column / 3;
}
return ('#');
}
