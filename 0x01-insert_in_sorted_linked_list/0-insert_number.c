#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * insert_node - listint_t *insert_node
 * @head: listint_t **head
 * @number: int number
 *
 * Return: 0.
 */
listint_t *insert_node(listint_t **head, int number)

{
	listint_t *current = *head;
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *previous = NULL;
	if (new_node == NULL)
	return (NULL);
	new_node->n = number;
	new_node->next = NULL;
	if (*head == NULL || (*head)->n >= number)
	{
	new_node->next = *head;
	*head = new_node;
	return (new_node);
	}
	while (current && number >= current->n)
	{
	previous = current;
	current = current->next;
        }

	new_node->next = current;
	previous->next = new_node;
	return (new_node);
}
