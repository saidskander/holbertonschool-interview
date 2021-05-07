#include"binary_trees.h"
/**
 * heap_insert - insert Heap
 * @root: theap_t **root
 * @value: int value
 * Return: pointer to the inserted node
 **/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;

	new_node = malloc(sizeof(*new_node));

	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = *root;

	return (new_node);
}
