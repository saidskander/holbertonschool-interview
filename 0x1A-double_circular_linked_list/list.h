#ifndef double_circular_linked_list_H
#define double_circular_linked_list_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct List - doubly linked list
 * @str: string - (malloc'ed string)
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;

List *add_node_begin(List **list, char *str);
List *add_node_end(List **list, char *str);

#endif
