#include "binary_trees.h"
/**
*binary_tree_height - calculates the height of a binary tree
*@tree: pointer to tree
*Return: height in size_t
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0, temp = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
	{
		height = binary_tree_height(tree->left);
		height++;
	}
	if (tree->right != NULL)
	{
		temp = binary_tree_height(tree->right);
		temp++;
	}
	if (temp > height)
		height = temp;

	return (height);
}
