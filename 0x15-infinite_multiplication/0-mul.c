#include "holberton.h"
/**
 * main - int main
 * @argc: int argc
 * @argv: char *argv[]
 * Return: 0
 */
int main(int argc, char *argv[])
{
char *num1 = argv[1];
char *num2 = argv[2];
if (argc != 3 || !onlyNumbers(num1) || !onlyNumbers(num2))
{
printf("Error\n");
exit(98);
}
if (*num1 == 48 || *num2 == 48)
printf("0\n");
else
multiply(num2, num1);
return (0);
}

/**
 * multiply - void multiply
 * @num1: char *num1
 * @num2: char *num2
 */
void multiply(char *num1, char *num2)
{
int i, len1, len2, total, fdigit, sdigit, res = 0, tmp;
int *ptr;
len1 = _strlen(num1);
len2 = _strlen(num2);
tmp = len2;
total = len1 + len2;
ptr = _calloc(sizeof(int), (len1 + len2));
for (len1--; len1 >= 0; len1--)
{
fdigit = num1[len1] - '0';
res = 0;
len2 = tmp;
for (len2--; len2 >= 0; len2--)
{
sdigit = num2[len2] - '0';
res += ptr[len2 + len1 + 1] + (fdigit * sdigit);
ptr[len1 + len2 + 1] = res % 10;
res /= 10;
}
if (res)
ptr[len1 + len2 + 1] = res % 10;
}
while (*ptr == 0)
{
ptr++;
total--;
}
for (i = 0; i < total; i++)
printf("%i", ptr[i]);
printf("\n");
}
/**
 * onlyNumbers - int onlyNumbers
 * @c: char *c
 * Return: 0 = false, 1 = true
 */
int onlyNumbers(char *c)
{
while (*c)
{
if (*c < '0' || *c > '9')
return (0);
c++;
}
return (1);
}

/**
 * _strlen - int _strlen
 * @num2: char *num2
 * Return: num2-p
 */
int _strlen(char *num2)
{
char *p = num2;
while (*num2)
num2++;
return (num2 - p);
}

/**
 * _memset - char *_memset
 * @num2: char *num2
 * @b: char b
 * @n: unsigned int n
 * Return: 0
 */
char *_memset(char *num2, char b, unsigned int n)
{
char *ptr = num2;
while (n--)
*num2++ = b;
return (ptr);
}

/**
 * _calloc - void *_calloc
 * @nmemb: unsigned int nmemb
 * @size:  unsigned int size
 * Return: pointer
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
void *ptr;
if (!nmemb || !size)
return (NULL);
ptr = malloc(size * nmemb);
if (!ptr)
return (NULL);
_memset(ptr, 0, size * nmemb);
return (ptr);
}
