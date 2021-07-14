#include <stdlib.h>
#include "slide_line.h"

/**
 * tmp_ints - void tmp_ints
 * @p: int *p
 * @p2: int *p2
 */
void tmp_ints(int *p, int *p2)
{
int temp = *p;
*p2 = temp;
}

/**
 * back_left - void back_left
 * @line: int *line
 * @size: size_t size
 */
void back_left(int *line, size_t size)
{
size_t i, pos = 0;
for (i = 0; i < size && pos < size; i++)
{
while (line[pos] == 0 && pos < size && pos + 1 < size)
pos++;
if (!line[i])
tmp_ints(&line[pos], &line[i]);
pos++;
}
}

/**
 * back_right - void back_right
 * @line: int *line
 * @size: size_t size
 */
void back_right(int *line, size_t size)
{
size_t i;
size_t pos = size - 1;
for (i = size - 1; (int) i >= 0 && (int) pos >= 0; i--)
{
while (line[pos] == 0 && (int) pos > 0)
pos--;
if (!line[i])
tmp_ints(&line[pos], &line[i]);
pos--;
}
}

/**
 * slide_line - int slide_line
 * @line: int *line
 * @size: size_t size
 * @direction: int direction
 * Return: 1 for success, else 0
 */
int slide_line(int *line, size_t size, int direction)
{
size_t i = 0;
if (direction == SLIDE_LEFT) {
back_left(line, size);
for (i = 0; i < size; i++)
{
if (line[i] == line[i + 1])
{
line[i] = line[i] + line[i + 1];
line[i + 1] = 0;
}
}
back_left(line, size);
return (1);
} else if (direction == SLIDE_RIGHT) {
back_right(line, size);
for (i = size - 1; (int) i >= 0; i--)
{
if (line[i] == line[i - 1])
{
line[i] = line[i] + line[i - 1];
line[i - 1] = 0;
}
}
back_right(line, size);
return (1);
}
return (0);
}
