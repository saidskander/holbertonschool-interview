#include <stdlib.h>
#include "slide_line.h"
/**
 * swap_ints - swap_ints
 * @p: int *p
 * @p2: int *p2
 */
void swap_ints(int *p, int *p2)
{
int temp = *p;
*p = *p2;
*p2 = temp;
}
/**
 * shift_left - void shift_left
 * @line: int *line
 * @size: size_t size
 */
void shift_left(int *line, size_t size)
{
size_t x;
size_t pos = 0;
for (x = 0; x < size && pos < size; x++)
{
while (line[pos] == 0 && pos < size && pos + 1 < size)
pos++;
if (!line[x])
swap_ints(&line[pos], &line[x]);
pos++;
}
}


/**
 * slide_line - int slide_line
 * @line: int *line
 * @size: size_t size
 * @direction: int direction
 * Return: 1 for success, else 0.
 */
int slide_line(int *line, size_t size, int direction)
{
size_t x = 0;
if (direction == SLIDE_LEFT) {
shift_left(line, size);
for (x = 0; x < size; x++)
{
if (line[x] == line[x + 1])
{
line[x] = line[x] + line[x + 1];
line[x + 1] = 0;
}
}
shift_left(line, size);
return (1);
} else if (direction == SLIDE_RIGHT) {
shift_right(line, size);
for (x = size - 1; (int) x >= 0; x--)
{
if (line[x] == line[x - 1])
{
line[x] = line[x] + line[x - 1];
line[x - 1] = 0;
}
}
shift_right(line, size);
return (1);
}
return (0);
}
