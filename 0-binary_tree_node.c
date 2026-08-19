#include "binary_trees.h"
/**
 * binary_tree_node - creates a node in a binary tree
 * @parent: the parent node
 * @value: value to add to new node
 * Return: Pointer to new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	node->n = value;
	node->left = node->right = NULL;
	node->parent = parent;
	return (node);
}
