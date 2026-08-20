#include "binary_trees.h"

/**
 * tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Number of nodes in the tree
 */
static size_t tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * is_complete - Checks completeness using node indexes
 * @tree: Pointer to the current node
 * @index: Index of the current node
 * @size: Total number of nodes
 *
 * Return: 1 if complete, otherwise 0
 */
static int is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete(tree->left, (2 * index) + 1, size) &&
		is_complete(tree->right, (2 * index) + 2, size));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);

	size = tree_size(tree);

	return (is_complete(tree, 0, size));
}
