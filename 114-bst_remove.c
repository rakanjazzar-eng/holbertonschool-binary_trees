#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_min - Finds the minimum node in a BST
 * @tree: Pointer to the root of the BST
 *
 * Return: Pointer to the minimum node
 */
static bst_t *bst_min(bst_t *tree)
{
	while (tree->left != NULL)
		tree = tree->left;

	return (tree);
}

/**
 * replace_node - Replaces a node with its child and frees it
 * @root: Pointer to the root of the BST
 * @node: Node to replace
 * @child: Child replacing the node
 */
static void replace_node(bst_t **root, bst_t *node, bst_t *child)
{
	if (child != NULL)
		child->parent = node->parent;

	if (node->parent == NULL)
		*root = child;
	else if (node->parent->left == node)
		node->parent->left = child;
	else
		node->parent->right = child;

	free(node);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the BST
 * @value: Value to remove
 *
 * Return: Pointer to the new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = root;
	bst_t *successor;
	bst_t *child;

	while (node != NULL && node->n != value)
	{
		if (value < node->n)
			node = node->left;
		else
			node = node->right;
	}

	if (node == NULL)
		return (root);

	if (node->left != NULL && node->right != NULL)
	{
		successor = bst_min(node->right);
		node->n = successor->n;
		node = successor;
	}

	child = node->left != NULL ? node->left : node->right;
	replace_node(&root, node, child);

	return (root);
}
