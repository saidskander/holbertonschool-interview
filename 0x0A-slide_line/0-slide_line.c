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
