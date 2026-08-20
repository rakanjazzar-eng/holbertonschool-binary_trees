#include "binary_trees.h"

/**
 * check_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the current node
 * @min: Pointer to the minimum allowed node
 * @max: Pointer to the maximum allowed node
 *
 * Return: 1 if valid, otherwise 0
 */
static int check_bst(const binary_tree_t *tree,
	const binary_tree_t *min, const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);

	if ((min != NULL && tree->n <= min->n) ||
	    (max != NULL && tree->n >= max->n))
		return (0);

	return (check_bst(tree->left, min, tree) &&
		check_bst(tree->right, tree, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_bst(tree, NULL, NULL));
}
