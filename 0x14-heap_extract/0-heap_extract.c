#include "binary_trees.h"

/**
 * _height - static size_t _height
 * @tree: const binary_tree_t *tree
 * Return: tree from node
 */
static size_t _height(const binary_tree_t *tree)
{
size_t height_left;
size_t height_right;
height_left = tree->left ? 1 + _height(tree->left) : 0;
height_right = tree->right ? 1 + _height(tree->right) : 0;
return (height_left > height_right ? height_left : height_right);
}

/**
 * _sorting - heap_t *_sorting
 * @temp: heap_t *temp
 * Return: pointer
 */

heap_t *_sorting(heap_t *temp)
{
int aux;
while (temp->left || temp->right)
{
if (!temp->right || temp->left->n > temp->right->n)
{
aux = temp->n;
temp->n = temp->left->n;
temp->left->n = aux;
temp = temp->left;
}
else if (!temp->left || temp->left->n < temp->right->n)
{
aux = temp->n;
temp->n = temp->right->n;
temp->right->n = aux;
temp = temp->right;
}
}
return (temp);
}

/**
 * _preorder - void _preorder
 * @root: heap_t *root
 * @node: heap_t **node
 * @h: size_t h
 * @l: size_t l
 */
void _preorder(heap_t *root, heap_t **node, size_t h, size_t l)
{
if (!root)
return;
if (h == l)
*node = root;
l++;
if (root->left)
_preorder(root->left, node, h, l);
if (root->right)
_preorder(root->right, node, h, l);
}
/**
 * heap_extract - int heap_extract
 * @root: heap_t **root
 * Return: node value
 */
int heap_extract(heap_t **root)
{
int value;
heap_t *aux, *node;
if (!root || !*root)
return (0);
aux = *root;
value = aux->n;
if (!aux->left && !aux->right)
{
*root = NULL;
free(aux);
return (value);
}
_preorder(aux, &node, _height(aux), 0);
aux = _sorting(aux);
aux->n = node->n;
if (node->parent->right)
node->parent->right = NULL;
else
node->parent->left = NULL;
free(node);
return (value);
}
