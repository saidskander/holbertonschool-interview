#include "search_algos.h"
/**
 * print - void print
 * @array: int *array
 * @left: size_t left
 * @right: size_t right
 * Return: 0
 **/
void print(int *array, size_t left, size_t right)
{
printf("Searching in array: ");
while (left < right)
{
printf("%i, ", array[left]);
left++;
}
printf("%i\n", array[left]);
}
/**
 * recursion_array - int recursion_array
 * @array: int *array
 * @left: int left
 * @right: int right
 * @value: int value
 * Return: 0
 **/
int recursion_array(int *array, int left, int right, int value)
{
int between;
print(array, left, right);
between = (right - left) / 2 + left;
if (left == right)
return (-1);
if (array[between] == value && array[between - 1] != value)
return (between);
if (array[between] >= value)
return (recursion_array(array, left, between, value));
if (array[between] <= value)
return (recursion_array(array, between + 1, right, value));
return (-1);
}
/**
 * advanced_binary - int advanced_binary
 * @array: int *array
 * @size: size_t size
 * @value: int value
 * Return: return -1
 **/
int advanced_binary(int *array, size_t size, int value)
{
if (array == NULL)
return (-1);
return (recursion_array(array, 0, size - 1, value));
}
