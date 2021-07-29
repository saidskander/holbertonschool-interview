#include "binary_trees.h"
/**
 * sorted_array_to_avl - avl_t *sorted_array_to_avl
 * @array: int *array
 * @size: size_t size
 * Return: bin
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
avl_t *header = NULL;
if (array == NULL)
return (NULL);
if (nodes_binary(array, 0, (int)size - 1, &header) == NULL)
return (NULL);
return (header);
}
/**
 * nodes_binary - avl_t *nodes_binary
 * @array: int *array
 * @p1: int p1
 * @p2: int p2
 * @header: avl_t **header
 * Return: node bin
 */
avl_t *nodes_binary(int *array, int p1, int p2, avl_t **header)
{
avl_t *new_node = NULL, *left = NULL, *right = NULL;
int middle;
if (p1 > p2)
return (NULL);
middle = (p2 + p1) / 2;
nodes_binary(array, p1, middle - 1, &left);
nodes_binary(array, middle + 1, p2, &right);
new_node = malloc(sizeof(avl_t));
if (new_node == NULL)
return (NULL);
new_node->n = array[middle];
new_node->parent = NULL;
new_node->left = left;
new_node->right = right;
if (left != NULL)
left->parent = new_node;
if (right != NULL)
right->parent = new_node;
*header = new_node;
return (new_node);
}

