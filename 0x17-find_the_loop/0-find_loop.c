#include "lists.h"

/**
* find_listint_loop - listint_t *find_listint_loop
* @head: listint_t *head
* Return: The address or null
**/
listint_t *find_listint_loop(listint_t *head)
{
listint_t *a = head;
listint_t *b = head;
if (!head)
return (NULL);
while (a->next && b->next->next)
{
a = a->next;
b = b->next->next;
if (a == b)
{
a = head;
while (a != b)
{
a = a->next;
b = b->next;
}
return (b);
}
}
return (NULL);
}
