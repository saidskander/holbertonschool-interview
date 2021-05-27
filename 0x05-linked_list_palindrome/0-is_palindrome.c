#include "lists.h"
/**
 * is_palindrome - Checks if list is a palindrome.
 * @head: listint_t **head
 * Return: 1 if it is a palindrome otherwise 0
 */
int is_palindrome(listint_t **head)
{
int list[1000000];
long n = 0, x;
listint_t *node;
if (head == NULL)
return (0);
if (*head == NULL)
return (1);
if ((*head)->next == NULL)
return (1);
node = *head;
while (node != NULL)
{
list[n] = node->n;
node = node->next;
n++;
}
for (x = 0; x < (n / 2); x++)
{
if (list[x] != list[n - x - 1])
return (0);
}
return (1);
}

