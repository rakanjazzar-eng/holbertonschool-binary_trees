#include <stdlib.h>
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
 * binary_tree_levelorder - Goes through a binary tree using level-order
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t **queue;
	const binary_tree_t *node;
	size_t size;
	size_t front = 0;
	size_t rear = 0;

	if (tree == NULL || func == NULL)
		return;

	size = tree_size(tree);
	queue = malloc(sizeof(*queue) * size);
	if (queue == NULL)
		return;

	queue[rear++] = tree;

	while (front < rear)
	{
		node = queue[front++];
		func(node->n);

		if (node->left != NULL)
			queue[rear++] = node->left;

		if (node->right != NULL)
			queue[rear++] = node->right;
	}

	free(queue);
}
