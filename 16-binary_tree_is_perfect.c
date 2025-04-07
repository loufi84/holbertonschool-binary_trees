#include "binary_trees.h"

/**
 * find_depth - Helper function to count the depth of a tree
 *
 * @tree: A pointer to the tree to check
 *
 * Return: The depth of the tree
 */

int find_depth(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

/**
 * is_perfect - Helper function that checks if a tree is perfect recursively
 *
 * @tree: A pointer to the root of the tree
 * @depth: The depth of the tree;
 * @level: At which level we are on the tree
 *
 * Return: 1 if perfect, 0 otherwise
 */

int is_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (
		is_perfect(tree->left, depth, level + 1) &&
		is_perfect(tree->right, depth, level + 1)
	);
}

/**
 * binary_tree_is_perfect - A function that checks if a binary tree is perfect
 *
 * @tree: A pointer to the root of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;

	if (tree == NULL)
		return (0);

	depth = find_depth(tree);
	return (is_perfect(tree, depth, 0));
}
