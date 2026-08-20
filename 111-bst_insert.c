#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *parent;
	bst_t *current;
	bst_t *new;

	if (tree == NULL)
		return (NULL);

	parent = NULL;
	current = *tree;

	while (current != NULL)
	{
		parent = current;

		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else
			return (NULL);
	}

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent == NULL)
		*tree = new;
	else if (value < parent->n)
		parent->left = new;
	else
		parent->right = new;

	return (new);
}
