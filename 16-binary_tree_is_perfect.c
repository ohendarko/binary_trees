#include "binary_trees.h"
/**
* binary_tree_is_perfect - checks if a binary tree is perfect
* @tree: pointer to the root node of the tree to check
* Return: 1 if tree is perfect, or 0 if tree is NULL
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height = binary_tree_height(tree);

	if (tree == NULL)
		return (0);

	return (is_perfect_recursive(tree, height, 0));
}

/**
* binary_tree_height - Measures the height of a binary tree
* @tree: Pointer to the root node of the tree to measure the height
* Return: Height of the tree, or 0 if tree is NULL
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
* is_perfect_recursive - Checks if a binary tree is perfect recursively
* @tree: Pointer to the current root node
* @height: Height of the tree
* @level: Current level of the node
* Return: 1 if the tree is perfect, 0 otherwise
*/
int is_perfect_recursive(const binary_tree_t *tree, int height, int level)
{
	if (tree == NULL)
		return (0);
	if (binary_tree_balance(tree) == 0)
	{
		if ((tree->left == NULL && tree->right == NULL) ||
			(tree->left != NULL && tree->right != NULL))
		{
			if ((is_perfect_recursive(tree->left, height, level + 1) &&
				is_perfect_recursive(tree->right, height, level + 1)) ||
				(!is_perfect_recursive(tree->left, height, level + 1) &&
				!is_perfect_recursive(tree->right, height, level + 1)))
				return (1);
		}
	}
	return (0);
}

/**
* binary_tree_balance - measures the balance factor of a binary tree
* @tree: pointer to the root node of the tree to measure the balance factor
* Return: Balance factor of the tree, or 0 if tree is NULL
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}
