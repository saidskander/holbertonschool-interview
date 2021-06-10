#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - int check_cycle
 * @list: listint_t
 * Return: 0 if there is no cycle, otherwise 1
 */

int check_cycle(listint_t *list)
{
listint_t *cycle, *List;
if (!list)
return (0);
cycle = list;
List = list;
while (cycle && List && list->next)
{
List = List->next->next;
if (List == cycle)
return (1);
}
return (0);
}
