#include <stdio.h>
#include "palindrome.h"
/**
 * reverse - void reverse
 * @n: unsigned long n
 * @rev: unsigned long *rev
 * Return: No Return
 */
void reverse(unsigned long n, unsigned long *rev)
{
if (n > 0)
{
*rev = *rev * 10 + (n % 10);
n = n / 10;
reverse(n, rev);
}

}

/**
 * is_palindrome - int is_palindrome
 * @n : unsigned long n
 * Return: 1 otherwise 0
 */
int is_palindrome(unsigned long n)
{
unsigned long rev = 0;
reverse(n, &rev);
if (rev == n)
return (1);
return (0);
}
