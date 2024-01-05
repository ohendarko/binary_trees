#include "binary_trees.h"
/**
* binary_tree_is_full - checks if a binary tree is full
* @tree: pointer to the root node of the tree to check
* Return: 1 if tree is full, or 0 if tree is NULL
*/
int binary_tree_is_full(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);

	if ((tree->left == NULL && tree->right == NULL) ||
		(tree->left != NULL && tree->right != NULL))
		return (1);

	return (0);
}
